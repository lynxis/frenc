
#ifndef TEST_H
#define TEST_H

#include "common.h"

void print_size_u8();
void print_size_u16();
void print_size_u32();
void print_size_int();

void print_size_pointer();
void dump_memory(uint8_t *start, int len);

void test_ringbuffer();
#endif /* TEST_H */
