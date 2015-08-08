
#include "gpio.h"
#include "led.h"

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
