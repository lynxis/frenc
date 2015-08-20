
#ifndef IRQS_H
#define IRQS_H

#define ICRA	(*(volatile unsigned char*)  (0xfffee8)) /* Interupt control register A */
#define ICRB	(*(volatile unsigned char*)  (0xfffee9)) /* Interupt control register B */
#define ICRC	(*(volatile unsigned char*)  (0xfffeea)) /* Interupt control register C */
#define ISR		(*(volatile unsigned char*)  (0xfffeeb)) /* IRQ status register */
#define ISCRH	(*(volatile unsigned char*)  (0xfffeec)) /* IRQ sense control register H */
#define ISCRL	(*(volatile unsigned char*)  (0xfffeed)) /* IRQ sense control register L */
#define WUEMRB	(*(volatile unsigned char*)  (0xfffe44)) /* Wakeup event interrupt mask register B */
#define ABRKCR	(*(volatile unsigned char*)  (0xfffef4)) /* Address break control register */
#define BARA	(*(volatile unsigned char*)  (0xfffef5)) /* Break address register A */
#define BARB	(*(volatile unsigned char*)  (0xfffef6)) /* Break address register B */
#define BARC	(*(volatile unsigned char*)  (0xfffef7)) /* Break address register C */
#define IER		(*(volatile unsigned char*)  (0xffffc2)) /* Interrupt enable register */
#define KMIMR	(*(volatile unsigned char*)  (0xfffff1)) /* Keyboard matrix interrupt register 6 */
#define KMIMRA	(*(volatile unsigned char*)  (0xfffff2)) /* Keyboard matrix interrupt register A */

#endif /* IRQS_H */
