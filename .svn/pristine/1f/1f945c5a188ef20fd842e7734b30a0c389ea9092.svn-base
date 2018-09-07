#ifndef __USER_STACK_H__
#define __USER_STACK_H__

#include "stdint.h"

typedef struct {
	uint8_t* pbuff;
	uint8_t* pend;  // pBuff + legnth
	uint8_t* wp;    // Write Point
	uint8_t* rp;    // Read Point
	uint16_t length;
	uint8_t  flagoverflow; // set when buffer overflowed
}user_ring_buffer_t;


void rb_initialize(user_ring_buffer_t* pringbuff, uint8_t* buff, uint16_t length);
void rb_clear(user_ring_buffer_t* pringbuff);
void rb_push(user_ring_buffer_t* pringbuff, uint8_t value);
uint8_t rb_pop(user_ring_buffer_t *pringbuff);
uint16_t rb_get_count(const user_ring_buffer_t *pringbuff);
int8_t rb_is_empty(const user_ring_buffer_t *pringbuff);
int8_t rb_is_full(const user_ring_buffer_t *pringbuff);





#endif
