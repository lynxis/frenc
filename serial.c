
#include "common.h"
#include "sleep.h"
#include "serial.h"
#include "power.h"

#include "ringbuffer.h"
#include "led.h"

#define UART_RXBUFFERSIZE 128
#define UART_TXBUFFERSIZE 128

struct baudrate {
	enum e_baudrate baudrate;
	uint8_t n;
	uint8_t brr;
};

static const struct baudrate baudrate_10mhz[] = {
	{.baudrate = B4800, .n = 0, .brr = 64}, /* Error 0.16 % */
	{.baudrate = B9600, .n = 0, .brr = 32}, /* Error -1.36 % */
	{.baudrate = B19200, .n = 0, .brr = 15}, /* Error 1.73 % */
	{.baudrate = B31250, .n = 0, .brr = 9}, /* Error 0.00 % */
	{.baudrate = B38400, .n = 0, .brr = 8}, /* Error 1.73 % */
};

static int set_baudrate(enum e_baudrate baudrate) {
	for(short i=0; i < ARRAY_SIZE(baudrate_10mhz); i++) {
		if (baudrate_10mhz[i].baudrate != baudrate)
			continue;

		SMR_1 &= ~SMR_CKS0 & ~SMR_CKS1;
		SMR_1 |= (baudrate_10mhz[i].n & 0x3);

		BRR_1 = baudrate_10mhz[i].brr;

		return 0;
	}
	return 1;
}

int setup_serial(enum e_baudrate baudrate, short enable_interupts) {

	/* See H8S/2140B Group Hardware Manual
	 * Page 380, Rev. 3.00, Mar 21, 2006 REJ09B0300-0300
	 */

	/* enable serial interace 1 */
	MSTPCRL &= ~MSTPCRL_SCI1;

	/* clear Tx/Rx enable bits */
	SCR_1 &= ~SCR_TE & ~SCR_RE;

	/* CKE0/1 = 0b00
	 * set clock mode to internal clock + release SCK pin */
	SCR_1 &= ~SCR_CKE0 & ~SCR_CKE1;

	/* no parity
	 * 8 data bits
	 * 1 stop bit
	 * async communication
	 *
	 * speed bits are set by set_baudrate()
	 */
	SMR_1 = 0;

	/* set to normal operation */
	SCMR_1 = 0;

	if (set_baudrate(baudrate)) {
		return 1;
	}

	/* wait at least 1 bit interval until setting TE/RE TIE/RIE bits */
	usleep(1000);

	SCR_1 |= SCR_TE | SCR_RE;

	if (enable_interupts)
		SCR_1 |= SCR_TIE | SCR_RIE | SCR_TEIE;

	return 0;
}

void uart_putc(const char c) {
	/* wait until transmit register is empty */
	while (!(SSR_1 & SSR_TDRE))
		;

	TDR_1 = c;

	/* clear register empty bit */
	SSR_1 &= ~SSR_TDRE;
}

void uart_puts(const char *str) {
	int len = strlen(str);
	for (short i=0; i<len; i++) {
		uart_putc(str[i]);
	}
}

void uart_enable_rx() {
	SCR_1 |= SCR_RIE | SCR_RE;
	eri1_irq();
}

static uint8_t receive_buffer[UART_RXBUFFERSIZE];
static uint8_t transmit_buffer[UART_TXBUFFERSIZE];

static struct ringbuffer_t txring = {
	.start = transmit_buffer,
	.last = transmit_buffer + UART_TXBUFFERSIZE - 1,
	.read = transmit_buffer,
	.write = transmit_buffer,
	.status = 0,
};

static struct ringbuffer_t rxring = {
	.start = receive_buffer,
	.last = receive_buffer + UART_RXBUFFERSIZE - 1,
	.read = receive_buffer,
	.write = receive_buffer,
	.status = 0,
};

/* TODO: error handling? */
void eri1_irq() {
	uart_putc('E');
	if (SSR_1 & SSR_ORER) {
		SSR_1 &= ~(SSR_ORER | SSR_RDRF);
	}
	if (SSR_1 & SSR_PER) {
		SSR_1 &= ~SSR_PER;
	}
	if (SSR_1 & SSR_FER) {
		SSR_1 &= ~SSR_FER;
	}
	if (SSR_1 & SSR_RDRF) {
		SSR_1 &= ~(SSR_RDRF);
	}
}

static uint8_t rdr;

void rxi1_irq() {
	uart_putc('r');
	if (SSR_1 & SSR_ORER) {
		SSR_1 &= ~(SSR_ORER | SSR_RDRF);
		return;
	}
	if (SSR_1 & SSR_PER) {
		SSR_1 &= ~SSR_PER;
		return;
	}
	if (SSR_1 & SSR_FER) {
		SSR_1 &= ~SSR_FER;
		return;
	}
	if (SSR_1 & SSR_RDRF) {
		uart_putc('R');
		rdr = RDR_1;
	}
	SSR_1 & ~(SSR_RDRF | SSR_ORER | SSR_PER | SSR_FER);
}

void debug_irq() {
	uart_puts("\r\nSCR: ");
	uart_put_u16(SCR_1);
	uart_puts("\r\nSSR: ");
	uart_put_u16(SSR_1);
}

/* called when transfered one byte */
void txi1_irq() {
	if (!ring_is_readable(&rxring))
		return;
}

int uart_getc(char *ch) {
	int ret;
	if (!ring_is_readable(&rxring)) {
		*ch = 0xa8;
		return 1;
	}
	SCR_1 &= ~SCR_RIE;
	ret = ringbuffer_read(&rxring, ch);
	SCR_1 |= SCR_RIE;

	return ret;
}

int uart_readable() {
	return ring_is_readable(&rxring);
}

static inline uint8_t getlow(uint8_t value) {
	value = value & 0xf;
	if (value < 10)
		return '0' + value;
	else
		return 'a' + value - 10;
}

void uart_put_u8(uint8_t value) {
	uart_putc(getlow(value >> 4));
	uart_putc(getlow(value));
}

void uart_put_u16(uint16_t value) {
	uart_putc(getlow((value >> 12) & 0xf));
	uart_putc(getlow((value >> 8) & 0xf));
	uart_putc(getlow((value >> 4) & 0xf));
	uart_putc(getlow(value & 0xf));
}

void uart_put_u32(uint32_t value) {
	uart_put_u16(value >> 16);
	uart_put_u16(value & 0xffff);
}

void uart_put_pointer(void *value) {
	uart_put_u32((uint32_t)value);
}

static void uart_print_ringbuffer(struct ringbuffer_t *ring) {
	uart_puts("=ringbuffer\r\n");
	uart_puts("po ");
	uart_put_pointer(ring);
	uart_puts("st ");
	uart_put_pointer(ring->start);
	uart_puts("la ");
	uart_put_pointer(ring->last);
	uart_puts("rd ");
	uart_put_pointer(ring->read);
	uart_puts("wr ");
	uart_put_pointer(ring->write);
}

void uart_print_rx_ringbuffer() {
	uart_print_ringbuffer(&rxring);
}

void uart_print_tx_ringbuffer() {
	uart_print_ringbuffer(&txring);
}

void uart_read_poll() {
	int uartread = 10;
	while (uartread--) {
		if (SSR_1 & SSR_RDRF) {
			uart_putc(RDR_1);
			SSR_1 &= ~(SSR_ORER | SSR_FER | SSR_PER | SSR_RDRF);
		}
	}
}
