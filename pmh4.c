
#include "gpio.h"
#include "sleep.h"
#include "pmh4.h"

/* send a simple hello to the board
 * 1 / (sleep_us*2) = frequency.
 */


/* bit bang the XP (extra protocol? :)
 *
 * The protocol use a data and a clock line. It's unidirectional.
 * Transmit one bit per clock cycle.
 * After all bytes are send, shortly pulse the LE pin to high.
 * OE is Low as long we are talking to the chip
 */
void send_pmh(int sleep_us, char *message, int len) {
	/* OE must be low all the time */
	XP_PORT_DATA &= ~(1 << XP_OE);

	/* message loop - transmit byte by byte */
	for (short i=0; i < len; i++) {

		/* byte loop - transmit bit by bit */
		for (short j=7; j >= 0; j--) {
			XP_PORT_DATA &= ~(1 << XP_CLK); /* clk low */

			if (message[i] & (1 << j)) {
				XP_PORT_DATA |= (1 << XP_DATA);
			} else {
				XP_PORT_DATA &= ~(1 << XP_DATA);
			}
			usleep(sleep_us);

			XP_PORT_DATA |= (1 << XP_CLK); /* clk high */
			usleep(sleep_us);
		}
	}

	/* latch enable is an end of transmission latch. Only pulsed shortly */
	usleep(1);
	XP_PORT_DATA &= ~(1 << XP_LE);
	usleep(1);
	XP_PORT_DATA |= (1 << XP_LE);
}

