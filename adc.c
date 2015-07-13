
#include "adc.h"
#include "power.h"
#include "common.h"

static void disable_unused_pwm_module() {
	/* when no output channel is active disable module */
	if (!(ADC_DACR >> 5)) {
		MSTPCRH |= MSTPCRH_DAC;
	}
}

int enable_dac(uint8_t channel, uint8_t enable) {
	/* out of range */
	if (channel > 1)
		return -1;

	channel &= 0x3;

	if (enable) {
		/* pull dac out of halt state */
		MSTPCRH &= ~MSTPCRH_DAC;

		ADC_DACR |= channel << 6;
	} else {
		ADC_DACR &= ~(channel << 6);
	}

	disable_unused_pwm_module();

	return 0;
}

void set_dac(uint8_t channel, uint8_t value) {
	/* when module is disable dont do anything */
	if (MSTPCRH & MSTPCRH_DAC)
		return;

	/* the channel can be still disabled but register writes are ok */

	switch (channel) {
		case 0:
			ADC_DADR0 = value;
			break;
		case 1:
			ADC_DADR1 = value;
			break;
	}
}
