
#include "lpc.h"
#include "power.h"
#include "common.h"

void enable_lpc(int channel) {
	/* put out of module disable */
	MSTPCRH &= ~MSTPCRL_LPC;

}


/* start up process
 *  chanenl3 set address
 *  set enable channel (1,2 or 3)
 *  set if (GA20E, PMEE, LSMIE, and LSCIE)
 *  set if (SDWNE, IEDIR).
 *  as a precaution, clear the interrupt flags (LRST, SDWN, ABRT, OBF). Read IDR or TWR15 to clear IBF.
 *  Set interrupt enable bits (IBFIE3 to IBFIE1, ERRIE) as necessary.
 */




/* only channel 3 has a variable address. channel 1 & 2 has fixed addresses */
void lpc_set_channel3_address(uint16_t address, uint8_t twr_enable) {
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

