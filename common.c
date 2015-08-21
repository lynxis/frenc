
#include "common.h"

size_t strlen(const char *s) {
	size_t ret = 0;
	while(*s++)
		ret++;
	return ret;
}

/* TODO: replace this by asm routine */
void *memset(void *s, int c, size_t n) {
	uint8_t *tmp = s;
	while (n--)
		*tmp++ = c;
	return s;
}
