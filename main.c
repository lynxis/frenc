
#include "common.h"
#include "sleep.h"
#include "serial.h"
#include "power.h"
#include "gpio.h"

void led_caps(short state) {
	if (state)
		P2DR &= ~(1 << 7);
	else
		P2DR |= (1 << 7);
}

void led_num(short state) {
	if (state)
		P2DR &= ~(1 << 5);
	else
		P2DR |= (1 << 5);
}

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
	P2DDR = 0xff; /* all ports are outputs */
	P4DDR = ((1 << 0) | (1 << 3) | 1 << 4);
	P9DDR = (1 << 5);

	P8DDR = (1 << 4); /* TXD1 output */

	XP_PORT_DATA &= ~(1 << XP_OE);

	led_caps(0);
	led_num(0);

	int ret = setup_serial(B9600, 1);
	while(ret) {
		led_num(1);
	}

	led_num(0);
	led_caps(0);

	for(int i=0; i<5; i++) {
		led_num(1);
		sleep(1);
		led_num(0);
		sleep(1);
	}

	power_board();

	while(1) {
		uart_puts("yip", 3);
		led_caps(1);
		send_pmh(2, "\x02\x0f\x90", 3);
		sleep(1);

		led_caps(0);
		send_pmh(2, "\x02\x0f\x90", 3);
		sleep(1);

	}
}
