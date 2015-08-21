
#include "common.h"
#include "sleep.h"
#include "xmodem.h"

#define WAITING_TO_START	0
#define WAITING_FOR_SEQ		1
#define WAITING_FOR_CMPL	2
#define RECEIVING_DATA		3
#define WAITING_FOR_CRC		4
#define WAITING_FOR_SOH		5
#define DROP_UNTIL_SOH_ACK	6
#define DROP_UNTIL_SOH_NAK	7
#define STOP			8

#define XMODEM_SOH          0x01 /* Start Of Header */
#define XMODEM_EOT          0x04 /* End Of Transmission */
#define XMODEM_ACK          0x06 /* Acknowledge (positive) */
#define XMODEM_DLE          0x10 /* Data Link Escape */
#define XMODEM_XON          0x11 /* Transmit On */
#define XMODEM_XOFF         0x13 /* Transmit Off */
#define XMODEM_NAK          0x15 /* Negative Acknowledge */
#define XMODEM_SYN          0x16 /* Synchronous idle */
#define XMODEM_CAN          0x18 /* Cancel */

void xmodem_receive() {
	uint8_t ch;
	int len = 0;
	uint8_t seq = 0;
	uint8_t crc = 0;
	uint8_t input_buffer[128];
	int state = WAITING_TO_START;

	while (state != STOP) {
		for (int i=0; state == WAITING_TO_START; i++) {
			uart_putc(XMODEM_ACK);
			sleep(1);
			while (uart_readable()) {
				uart_getc((char *)&ch);
				if (ch == XMODEM_SOH) {
					state = WAITING_FOR_SEQ;
				}
			}
			if (i <= 10) {
				uart_putc(XMODEM_CAN);
				uart_putc(XMODEM_CAN);
				uart_puts("Aborting");
				return;
			}
		}

		while (state == WAITING_FOR_SOH) {
			while (!uart_readable());
			uart_getc((char *)&ch);
			if (ch == XMODEM_SOH) {
				state = WAITING_FOR_SEQ;
			}
		}

		while (state == WAITING_FOR_SEQ) {
			while (!uart_readable());
			uart_getc((char *)&ch);
			if (seq+1 == ch) {
				seq++;
				state = WAITING_FOR_CMPL;
			} else if (seq == ch) {
				state = DROP_UNTIL_SOH_ACK;
			} else {
				state = DROP_UNTIL_SOH_NAK;
			}
		}

		while (state == WAITING_FOR_CMPL) {
			for (int i=0; !uart_readable(); i++) {
				sleep(1);
				if (i == 10) {
					uart_putc(XMODEM_CAN);
					uart_putc(XMODEM_CAN);
					uart_puts("Aborting");
					return;
				}
			}
			uart_getc((char *)&ch);
			if (ch == ((255 & seq) ^ 255)) {
				state = RECEIVING_DATA;
			} else {
				state = DROP_UNTIL_SOH_NAK;
			}
		}

		while (state == DROP_UNTIL_SOH_ACK || state == DROP_UNTIL_SOH_NAK) {
			while (!uart_readable()) {
			}
			len++;
			if (len == 129) {
				if (state == DROP_UNTIL_SOH_ACK)
					uart_putc(XMODEM_ACK);
				else if (state == DROP_UNTIL_SOH_NAK)
					uart_putc(XMODEM_NAK);
				state = WAITING_FOR_SOH;
			}
		}

		while (state == RECEIVING_DATA) {
			while (!uart_readable()) {
			}
			uart_getc((char *) &ch);
			input_buffer[len] = ch;
			len++;
			if (len == 128)
				state = WAITING_FOR_CRC;
		}

		while (state == WAITING_FOR_CRC) {
			while (!uart_readable()) {
			}
			uart_getc((char *) &ch);
			crc = 0;
			for (int i=0; i< len; i++) {
				crc += input_buffer[i];
			}
			if (crc == ch) {
				uart_putc(XMODEM_ACK);
			} else {
				uart_putc(XMODEM_NAK);
			}
			state = WAITING_FOR_SOH;
		}
	}
}
