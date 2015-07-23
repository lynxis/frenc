
#ifndef ADC_H
#define ADC_H

/* have to add adc because of dublicate register name DACR for PWMX and ADC */
#define ADC_DADR0		(*(volatile unsigned char*) (0xfffff8)) /* D/A data register 0 */
#define ADC_DADR1		(*(volatile unsigned char*) (0xfffff9)) /* D/A data register 1 */
#define ADC_DACR		(*(volatile unsigned char*) (0xfffffa)) /* D/A control register */
int enable_dac(uint8_t channel, uint8_t enable);
void set_dac(uint8_t channel, uint8_t value);

#endif /* ADC_H */
