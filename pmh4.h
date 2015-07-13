
/* data direction must be set to output seperate*/

/* pin on the port */
#define XP_CLK 0
#define XP_DATA 1
#define XP_LE 2
#define XP_OE 3
#define XP_PORT_DATA P2DR
#define XP_PORT_DIRECTION P2DDR

void send_pmh(int sleep_us, char *message, int len);
