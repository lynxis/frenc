
#include "common.h"

extern uint8_t data;
extern uint8_t rom_data;
extern uint8_t bss;
extern uint8_t ebss;

void init() {
	uint8_t *src;
	uint8_t *dest;
	unsigned int len;

	src = &rom_data;
	dest = &data;
	while (len--)
		*dest++ = *src++;

	dest = &bss;
	len = &ebss - &bss;
	while (len--)
		*dest++ = 0;
}
