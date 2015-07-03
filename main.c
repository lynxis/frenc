

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
#endif

#define P1DDR	((volatile unsigned char*)	(0xffffb0)) /* Port 1 Data Direction Register */
#define P2DDR	((volatile unsigned char*)	(0xffffb1)) /* Port 2 Data Direction Register */
#define P1DR	((volatile unsigned char*)	(0xffffb2)) /* Port 1 Data Register */
#define P2DR	((volatile unsigned char*)	(0xffffb3)) /* Port 2 Data Register */
#define P3DDR	((volatile unsigned char*)	(0xffffb4)) /* Port 3 Data Direction Register */
#define P4DDR	((volatile unsigned char*)	(0xffffb5)) /* Port 4 Data Direction Register */
#define P3DR	((volatile unsigned char*)	(0xffffb6)) /* Port 3 Data Register */
#define P4DR	((volatile unsigned char*)	(0xffffb7)) /* Port 4 Data Register */
#define P5DDR	((volatile unsigned char*)	(0xffffb8)) /* Port 5 Data Direction Register */
#define P6DDR	((volatile unsigned char*)	(0xffffb9)) /* Port 6 Data Direction Register */
#define P5DR	((volatile unsigned char*)	(0xffffba)) /* Port 5 Data Register */
#define P6DR	((volatile unsigned char*)	(0xffffbb)) /* Port 6 Data Register */
#define PBODR	((volatile unsigned char*)	(0xffffbc)) /* Port B Output Direction Register */
#define P8DDR	((volatile unsigned char*)	(0xffffbd)) /* Port 8 Data Direction Register (write) */
#define PBPIN	((volatile unsigned char*)	(0xffffbd)) /* Port B ????????????? (read) */
#define PBDDR	((volatile unsigned char*)	(0xffffbe)) /* Port B Data Direction Register (write) */
#define P7PIN	((volatile unsigned char*)	(0xffffbe)) /* Port 7 ????????????? (read) */
#define P8DR	((volatile unsigned char*)	(0xffffbf)) /* Port 8 Data Register */
#define P9DDR	((volatile unsigned char*)	(0xffffc0)) /* Port 9 Data Direction Register */
#define P9DR	((volatile unsigned char*)	(0xffffc1)) /* Port 9 Data Register */
#define PDDDR ((volatile unsigned char*)  (0xffff4f)) /* Port D Data Direction Register */
#define PDODR ((volatile unsigned char*)  (0xffff4d)) /* Port D Data Register */

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

void led_caps(short state) {
  if (state)
    *P2DR &= ~(1 << 7);
  else
    *P2DR |= (1 << 7);
}

void led_num(short state) {
  if (state)
    *P2DR &= ~(1 << 5);
  else
    *P2DR |= (1 << 5);
}

void power_board() {
  /* !mainoff */
  *P2DR |= (1 << 4);

  /* FAN On */
  *P4DDR = (1 << 4);
  *P4DR |= (1 << 4);

  /* -pwrsw_h8s */
  *P9DDR = (1 << 5);

  *P9DR |= (1 << 5);
  sleep(2);
  *P9DR &= ~(1 << 5);
  sleep(2);
  *P9DR |= (1 << 5);
}

int main() {
  *P2DDR = ((1 << 4) | (1 << 5) | (1 << 7));
  led_num(1);
  led_caps(1);

  for(int i=0; i<5; i++) {
    led_num(1);
    sleep(1);
    led_num(0);
    sleep(1);
  }

  power_board();

  for(int i=0; i<5; i++) {
    led_caps(1);
    sleep(1);
    led_caps(0);
    sleep(1);
  }

}
