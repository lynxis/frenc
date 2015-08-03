
#ifndef COMMON_H
#define COMMON_H

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
#endif

#define BIT(x) (1 << x)

#endif /* COMMON_H */
