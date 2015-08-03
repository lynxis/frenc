
#include "common.h"
#include "ringbuffer.h"

static inline void increase_read_pointer(struct ringbuffer_t *ring) {
	if (ring->read == ring->last)
		ring->read = ring->start;
	else
		ring->read++;
}

static inline void increase_write_pointer(struct ringbuffer_t *ring) {
	volatile void *next_element;
	if (ring->write == ring->last)
		next_element = ring->start;
	else
		next_element = ring->write + 1;

	/* check if ringbuffer overflows */
	if (ring->read == next_element) {
		/* overflow - we will loose one slot here, because of implementation */
		ring->status |= RING_OVERFLOW;
		if (next_element == ring->last)
			ring->read = ring->start;
		else
			ring->read++;
	}

	ring->write = (void *)next_element;
	*ring->write = 0;
}

int ringbuffer_read(struct ringbuffer_t *ring, uint8_t *read) {
	if (!ring_is_readable(ring))
		return -BUFFER_EMPTY;
	*read = *ring->read;
	increase_read_pointer(ring);
	return 0;
}

int ringbuffer_write(struct ringbuffer_t *ring, uint8_t write) {
	*ring->write = write;
	increase_write_pointer(ring);
	return 0;
}
