
#include "lpc.h"
#include "power.h"
#include "common.h"

void enable_lpc(int channel) {
	/* put out of shutdown */
	MSTPCRH &= ~MSTPCRL_LPC;
}

/* only channel 3 has a variable address. channel 1 & 2 has fixed addresses */
void setlpc_channel3_address(uint16_t address, uint8_t twr_enable) {
	uint8_t val;

	LPC_LADR3H = address >> 8;
	
	/* lower 8 bit */
	val = (address & 0xff);

	/* bit 2 is reseved - recommend to write only 0 into */
	val &= ~(1 << 2);

	/* bit 0 is twr */
	if (twr_enable)
		val |= (1 << 0);
	else
		val &= ~(1 << 0);

	LPC_LADR3L = val;
}

