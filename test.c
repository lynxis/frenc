
#include "test.h"

#include "common.h"
#include "serial.h"

void print_size_u8() {
	int i = sizeof(uint8_t);
	uart_puts("Size of 8", 9);
	while (i--) {
		uart_putc('Q');
	}
}

void print_size_u16() {
	int i = sizeof(uint16_t);
	uart_puts("Size of 16", 10);
	while (i--) {
		uart_putc('W');
	}
}

void print_size_u32() {
	int i = sizeof(uint32_t);
	uart_puts("Size of 32", 10);
	while (i--) {
		uart_putc('E');
	}
}
