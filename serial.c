
#include <common.h>
#include <serial.h>

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

	/* wait at least 1 bit interval until setting TE/RE T1E/R1E bits */
	usleep(1000);

	SCR_1 |= SCR_TE | SCR_RE;

	if (enable_interupts)
		SCR_1 |= SCR_TIE | SCR_RIE | SCR_TEIE;

	return 0;
}

void uart_putc(const char c) {
	led_num(1);
	/* wait until transmit register is empty */
	while (!(SSR_1 & SSR_TDRE))
		;
	led_num(0);

	TDR_1 = c;

	/* clear register empty bit */
	SSR_1 &= ~SSR_TDRE;
}

