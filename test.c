
#include "test.h"

#include "common.h"
#include "serial.h"
#include "ringbuffer.h"

void print_size_u8() {
	int i = sizeof(uint8_t);
	uart_puts("Size of 8");
	while (i--) {
		uart_putc('Q');
	}
}

void print_size_u16() {
	int i = sizeof(uint16_t);
	uart_puts("Size of 16");
	while (i--) {
		uart_putc('W');
	}
}

void print_size_u32() {
	int i = sizeof(uint32_t);
	uart_puts("Size of 32");
	while (i--) {
		uart_putc('E');
	}
}

void print_size_pointer() {
	int i = sizeof(uint32_t *);
	uart_puts("Size of 32p");
	while (i--) {
		uart_putc('R');
	}
}

void print_size_int() {
	int i = sizeof(int);
	uart_puts("Size of int");
	while (i--) {
		uart_putc('T');
	}
}

void dump_memory(uint8_t *start, int len) {
	uart_puts("memory dump\r\n");
	for (int i=0; i < len; i++) {
		uart_put_u8(*start);
		start++;
		if(i % 32 == 0) {
			uart_putc('\r');
			uart_putc('\n');
		} else if (i % 4 == 0) {
			uart_putc(' ');
		}
	}
	uart_puts("\r\nend\r\n");
}

static uint8_t test_buffer[8];

static struct ringbuffer_t testring = {
	.start = test_buffer,
	.last = test_buffer + 8 - 1,
	.read = test_buffer,
	.write = test_buffer,
	.status = 0,
};

static void print_ringbuffer(struct ringbuffer_t *ring) {
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


void test_ringbuffer() {
	uint16_t ret = 0;
	char ch = 0;
	uart_puts("ringbuffer test\r\n");
	uart_puts("\r\nringbuffer is empty. Check is_readable\r\n");
	uart_puts("should be 0000. is : ");
	uart_put_u16(ring_is_readable(&testring));
	uart_puts("\r\n");
	uart_puts("writing 4 bytes into ringbuffer (1234)\r\n");
	ringbuffer_write(&testring, '1');
	ringbuffer_write(&testring, '2');
	ringbuffer_write(&testring, '3');
	ringbuffer_write(&testring, '4');

	print_ringbuffer(&testring);

	uart_puts("check if ring is readable\r\n");
	uart_puts("check readable : ");
	uart_put_u16(ring_is_readable(&testring));
	uart_puts("\r\n");

	uart_puts("read out all avaiable bytes until ring isnt readable\r\n");
	while (ring_is_readable(&testring)) {
		uart_puts("read return code ");
		ret = ringbuffer_read(&testring, &ch);
		uart_put_u16(ret);
		uart_puts(" char is : ");
		uart_putc(ch);
		uart_puts("\r\n");
	}
	uart_puts("end reading variables\r\n");
	uart_puts("try to read even when ring isnt readable");
	uart_puts("read return code ");
	ret = ringbuffer_read(&testring, &ch);
	uart_put_u16(ret);
	uart_puts(" char is : ");
	uart_putc(ch);
	uart_puts("\r\n");
}
