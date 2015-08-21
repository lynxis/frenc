
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

int strcmp(const char *s1, const char *s2) {
	while (*s1 && *s2) {
		if (*s1 != *s2) {
			return 1;
		}
		s1++;
		s2++;
	}
	if (*s1 == 0 && *s2 == 0) {
		return 0;
	}
	return 1;
}

int strncmp(const char *s1, const char *s2, size_t n) {
	while (n--) {
		if (*s1 == 0 && *s2 == 0) {
			return 0;
		} else if (*s1 != *s2) {
			return 1;
		}
		s1++;
		s2++;
	}
	return 0;
}
