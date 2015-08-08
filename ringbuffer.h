
#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#include "common.h"

struct ringbuffer_t {
  uint8_t *start;
  uint8_t *last;
  uint8_t *read;
  uint8_t *write;
  uint8_t status;
};

#define BUFFER_EMPTY 1;
#define RING_OVERFLOW BIT(0)

int ringbuffer_read(struct ringbuffer_t *ring, uint8_t *read);
int ringbuffer_write(struct ringbuffer_t *ring, uint8_t write);
inline int ring_is_readable(struct ringbuffer_t *ring);

#endif /* RINGBUFFER_H */
