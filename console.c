
#include "common.h"
#include "serial.h"

static char line_buffer[128];

/* set line and length. line includes \n*/
int getline(char **line, int *length) {
	for (int i=0; i < ARRAY_SIZE(line_buffer); i++) {
		while (uart_getc(&line_buffer[i]))
			;

		if (line_buffer[i] == '\n') {
			*line = line_buffer;
			*length = i;
			return 0;
		} else if (line_buffer[i] == '\0') {
			return 1;
		}
	}
	return -1;
}
