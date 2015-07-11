
#ifndef POWER_H
#define POWER_H

#define SBYCR       (*(volatile unsigned char*)	(0xffff84)) /* Standby control register */
#define LPWRCR      (*(volatile unsigned char*)	(0xffff85)) /* Low power control register */
#define MSTPCRH     (*(volatile unsigned char*)	(0xffff86)) /* Module stop control register H */
#define MSTPCRL     (*(volatile unsigned char*)	(0xffff87)) /* Module stop control register L */

/* module stop control register */
#define MSTPCRH_MSTP15 (1 << 7) /* reserved */
#define MSTPCRH_MSTP14 (1 << 6) /* Data transfer controller (DTC) */
#define MSTPCRH_MSTP13 (1 << 5) /* 16-bit free-running timer (FRT) */
#define MSTPCRH_MSTP12 (1 << 4) /* 8-bit timers (TMR_0, TMR1) */
#define MSTPCRH_MSTP11 (1 << 3) /* 8-bit PWM timer (PWM), 14-bit PWM timer(PWMX) */
#define MSTPCRH_MSTP10 (1 << 2) /* D/A converter */
#define MSTPCRH_MSTP9  (1 << 1) /* A/D converter */
#define MSTPCRH_MSTP8  (1 << 0) /* 8-bit timers (TMR_X, TMR_Y), timer connection*/
#define MSTPCRL_MSTP7  (1 << 7) /* Serial communication interface_0 (SCI_0) */
#define MSTPCRL_MSTP6  (1 << 6) /* Serial communication interface_1 (SCI_1) */
#define MSTPCRL_MSTP5  (1 << 5) /* Serial communication interface_2 (SCI_2) */
#define MSTPCRL_MSTP4  (1 << 4) /* I2C bus interface_0 (IIC_0) */
#define MSTPCRL_MSTP3  (1 << 3) /* I2C bus interface_1 (IIC_1) */
#define MSTPCRL_MSTP2  (1 << 2) /* Host interface (XBS),
                                   keyboard buffer controller,
                                   keyboard matrix interrupt mask register (KMIMR)
                                   keyboard matrix interrupt mask register A (KMIMRA)
                                   port 6 pull-up MOS control register (KMPCR) */
#define MSTPCRL_MSTP1  (1 << 1) /* no operations will change */
#define MSTPCRL_MSTP0  (1 << 0) /* Host interface (LPC)
                                   wake-up even interupt mask register B (WUEMRB) */
/* module stop control register function names */
#define MSTPCRH_MSTP15  (1 << 7) /* reserved */
#define MSTPCRH_DTC     (1 << 6) /* Data transfer controller (DTC) */
#define MSTPCRH_FRT     (1 << 5) /* 16-bit free-running timer (FRT) */
#define MSTPCRH_TMR01   (1 << 4) /* 8-bit timers (TMR_0, TMR1) */
#define MSTPCRH_PWM     (1 << 3) /* 8-bit PWM timer (PWM), 14-bit PWM timer(PWMX) */
#define MSTPCRH_DAC     (1 << 2) /* D/A converter */
#define MSTPCRH_ADC     (1 << 1) /* A/D converter */
#define MSTPCRH_TMRXY   (1 << 0) /* 8-bit timers (TMR_X, TMR_Y), timer connection*/
#define MSTPCRL_SCI0    (1 << 7) /* Serial communication interface_0 (SCI_0) */
#define MSTPCRL_SCI1    (1 << 6) /* Serial communication interface_1 (SCI_1) */
#define MSTPCRL_SCI2    (1 << 5) /* Serial communication interface_2 (SCI_2) */
#define MSTPCRL_IIC0    (1 << 4) /* I2C bus interface_0 (IIC_0) */
#define MSTPCRL_IIC1    (1 << 3) /* I2C bus interface_1 (IIC_1) */
#define MSTPCRL_XBS_KBD (1 << 2) /* Host interface (XBS),
                                   keyboard buffer controller,
                                   keyboard matrix interrupt mask register (KMIMR)
                                   keyboard matrix interrupt mask register A (KMIMRA)
                                   port 6 pull-up MOS control register (KMPCR) */
#define MSTPCRL_NOP     (1 << 1) /* no operations will change */
#define MSTPCRL_LPC     (1 << 0) /* Host interface (LPC)
                                   wake-up even interupt mask register B (WUEMRB) */


#endif /* POWER_H */
