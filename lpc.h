
#ifndef LPC_H
#define LPC_H

#define LPC_HICR0		(*(volatile unsigned char*) (0xffffFF)) /*  */
#define LPC_HICR0_LPC3E		(1 << 7)
#define LPC_HICR0_LPC2E		(1 << 6)
#define LPC_HICR0_LPC1E		(1 << 5)
#define LPC_HICR0_FGA20E	(1 << 4)
#define LPC_HICR0_SDWNE		(1 << 3)
#define LPC_HICR0_PMEE		(1 << 2)
#define LPC_HICR0_LSMIE		(1 << 1)
#define LPC_HICR0_LSCIE		(1 << 0)

#define LPC_HICR1		(*(volatile unsigned char*) (0xffffFF)) /*  */
#define LPC_HICR1_LPCBSY	(1 << 7)
#define LPC_HICR1_CLKREQ	(1 << 6)
#define LPC_HICR1_IRQBSY	(1 << 5)
#define LPC_HICR1_LRSTB		(1 << 4)
#define LPC_HICR1_SWNB		(1 << 3)
#define LPC_HICR1_PMEB		(1 << 2)
#define LPC_HICR1_LSMIB		(1 << 1)
#define LPC_HICR1_LSCIB		(1 << 0)

#define LPC_TMR0MW		(*(volatile unsigned char*) (0xfffe20)) /* Bidirectional data register  0MW */
#define LPC_TWR0SW		(*(volatile unsigned char*) (0xfffe20)) /* Bidirectional data register  0SW */
#define LPC_TWR1		(*(volatile unsigned char*) (0xfffe21)) /* Bidirectional data register  1 */
#define LPC_TWR2		(*(volatile unsigned char*) (0xfffe22)) /* Bidirectional data register  2 */
#define LPC_TWR3		(*(volatile unsigned char*) (0xfffe23)) /* Bidirectional data register  3 */
#define LPC_TWR4		(*(volatile unsigned char*) (0xfffe24)) /* Bidirectional data register  4 */
#define LPC_TWR5		(*(volatile unsigned char*) (0xfffe25)) /* Bidirectional data register  5 */
#define LPC_TWR6		(*(volatile unsigned char*) (0xfffe26)) /* Bidirectional data register  6 */
#define LPC_TWR7		(*(volatile unsigned char*) (0xfffe27)) /* Bidirectional data register  7 */
#define LPC_TWR8		(*(volatile unsigned char*) (0xfffe28)) /* Bidirectional data register  8 */
#define LPC_TWR9		(*(volatile unsigned char*) (0xfffe29)) /* Bidirectional data register  9 */
#define LPC_TWR10		(*(volatile unsigned char*) (0xfffe2a)) /* Bidirectional data register 10 */
#define LPC_TWR11		(*(volatile unsigned char*) (0xfffe2b)) /* Bidirectional data register 11 */
#define LPC_TWR12		(*(volatile unsigned char*) (0xfffe2c)) /* Bidirectional data register 12 */
#define LPC_TWR13		(*(volatile unsigned char*) (0xfffe2d)) /* Bidirectional data register 13 */
#define LPC_TWR14		(*(volatile unsigned char*) (0xfffe2e)) /* Bidirectional data register 14 */
#define LPC_TWR15		(*(volatile unsigned char*) (0xfffe2f)) /* Bidirectional data register 15 */

#define LPC_IDR3		(*(volatile unsigned char*) (0xfffe30)) /* Input data register 3 */
#define LPC_ODR3		(*(volatile unsigned char*) (0xfffe31)) /* Output data register 3 */
#define LPC_STR3		(*(volatile unsigned char*) (0xfffe32)) /* Status data register 3 */
#define LPC_LADR3H		(*(volatile unsigned char*) (0xfffe34)) /* LPC channel address register H */
#define LPC_LADR3L		(*(volatile unsigned char*) (0xfffe35)) /* LPC channel address register L */
#define LPC_SIRQCR0		(*(volatile unsigned char*) (0xfffe36)) /* SERIRQ control register 0 */
#define LPC_SIRQCR1		(*(volatile unsigned char*) (0xfffe37)) /* SERIRQ control register 1 */
#define LPC_IDR1		(*(volatile unsigned char*) (0xfffe38)) /* Input data register 1 */
#define LPC_ODR1		(*(volatile unsigned char*) (0xfffe39)) /* Output data register 1 */
#define LPC_STR1		(*(volatile unsigned char*) (0xfffe3a)) /* Status data register 1 */
#define LPC_IDR2		(*(volatile unsigned char*) (0xfffe3c)) /* Input data register 2 */
#define LPC_ODR2		(*(volatile unsigned char*) (0xfffe3d)) /* Output data register 2 */
#define LPC_STR2		(*(volatile unsigned char*) (0xfffe3e)) /* Status data register 2 */
#define LPC_HISEL		(*(volatile unsigned char*) (0xfffe3e)) /* Host interface select register */
#define LPC_HICR0		(*(volatile unsigned char*) (0xfffe3e)) /* Host interface control register 0 */
#define LPC_HICR1		(*(volatile unsigned char*) (0xfffe3e)) /* Host interface control register 1 */
#define LPC_HICR2		(*(volatile unsigned char*) (0xfffe3e)) /* Host interface control register 2 */
#define LPC_HICR3		(*(volatile unsigned char*) (0xfffe3e)) /* Host interface control register 3 */

#endif /* LPC_H */
