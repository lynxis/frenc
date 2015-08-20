
#include "common.h"
#include "sleep.h"
#include "serial.h"
#include "power.h"
#include "gpio.h"

#include "adc.h"
#include "led.h"
#include "pmh4.h"

#include "test.h"

void power_board() {
	/* !mainoff */
	P2DR |= (1 << 4);

	/* -KBRC */
	/* FAN On */
	/* -batlow */
	P4DR |= (1 << 0) | (1 << 4) | (1 << 3);

	/* -pwrsw_h8s */
	P9DR |= (1 << 5);
	sleep(2);
	P9DR &= ~(1 << 5);
	sleep(2);
	P9DR |= (1 << 5);
}

int main() {
	P2DDR = 0xf0; /* -MAINOFF  -LEDNUMPAD -BAYLED -LEDCAPSLOCK */
	P4DDR = ((1 << 0) | (1 << 3) | 1 << 4); /* -KBRC -BATLOW FANON */
	P9DDR = (1 << 5);

	P8DDR = (1 << 1) | (1 << 4); /* TXD1 output */

	led_caps(0);
	led_num(0);
	for(int i=0; i<3; i++) {
		led_caps(1);
		sleep(1);
		led_caps(0);
		sleep(1);
	}

	int ret = setup_serial(B9600, 1);
	while(ret) {
		led_num(1);
	}

	print_size_u8();
	print_size_u16();
	print_size_u32();
	print_size_pointer();
	dump_memory((void *)0xffe080, 3*32);

	led_num(0);
	led_caps(0);
	enable_dac(0, 1);
	enable_dac(1, 1);
	set_dac(0, 120);
	set_dac(1, 120);
	uart_print_rx_ringbuffer();
	uart_puts("TX\n");
	uart_print_tx_ringbuffer();
	test_ringbuffer();

	for(int i=0; i<5; i++) {
		led_num(1);
		sleep(1);
		led_num(0);
		sleep(1);
	}

	power_board();
  uart_enable_rx();

	while(1) {
		uart_puts("yip\r\n");
		//while (uart_readable()) {
		//	char c;
		//	uart_puts("rd:", 3);
		//	if (uart_getc(&c))
		//		break;
		//	uart_putc(c);
		//}
		//uart_read_poll();
		
		debug_irq();
		led_caps(1);
		sleep(1);

		led_caps(0);
		sleep(1);
	}
	uart_puts("NEVER");
	uart_puts("NEVER");
	uart_puts("NEVER");
	uart_puts("NEVER");
}
