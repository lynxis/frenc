
#include "test.h"

#include "common.h"
#include "serial.h"

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
