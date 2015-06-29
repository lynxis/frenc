

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
#endif

#define P1DDR	((volatile unsigned char*)	(0xffffb0)) /* Port 1 Data Direction Register */
#define P2DDR	((volatile unsigned char*)	(0xffffb1)) /* Port 2 Data Direction Register */
#define P1DR	((volatile unsigned char*)	(0xffffb2)) /* Port 1 Data Register */
#define P2DR	((volatile unsigned char*)	(0xffffb3)) /* Port 2 Data Register */

#define PDDDR ((volatile unsigned char*)  (0xffff4f)) /* Port D Data Direction Register */
#define PDODR ((volatile unsigned char*)  (0xffff4d)) /* Port D Data Register */


int main() {

  *P2DDR |= ((1 << 5) | (1 << 7));
  int output = *P2DDR;
  int data = *P2DR;
  while (1) {
    /* enable output for p25, p27 */
    *P2DR &= ~(1 << 5);
    *P2DR &= ~(1 << 7);
    output = *P2DDR;
    data = *P2DR;
    output;
    data;
    for (unsigned int j=0; j<65535; j++)
        ;
    *P2DR |= (1 << 5);
    *P2DR |= (1 << 7);
    output = *P2DDR;
    data = *P2DR;
    output;
    data;

    for (unsigned int j=0; j<65535; j++)
        ;
  }
}
