
#include "sleep.h"

void sleep1s() {
	for (unsigned int j=0; j<65535; j++)
		;
	for (unsigned int j=0; j<65535; j++)
		;
}

void sleep(int seconds) {
	while(seconds-- > 0)
		sleep1s();
}

/* 1useconds => real 9useconds */
void usleep(int useconds) {
	while(useconds-- > 0)
		;
}

