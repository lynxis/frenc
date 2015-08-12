
#ifndef COMMON_H
#define COMMON_H

typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long uint32_t;
typedef unsigned long size_t;

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(a) (sizeof (a) / sizeof ((a)[0]))
#endif

#define BIT(x) (1 << x)

size_t strlen(const char *s);

#endif /* COMMON_H */
