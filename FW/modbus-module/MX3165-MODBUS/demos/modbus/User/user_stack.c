#include "user_stack.h"


void rb_initialize(user_ring_buffer_t* pringbuff, uint8_t* buff, uint16_t length)
{
	pringbuff->pbuff = buff;
	pringbuff->pend  = buff + length;
	pringbuff->wp = buff;
	pringbuff->rp = buff;
	pringbuff->length = length;
	pringbuff->flagoverflow = 0;
}

void rb_clear(user_ring_buffer_t* pringbuff)
{
 	pringbuff->wp = pringbuff->pbuff;
	pringbuff->rp = pringbuff->pbuff;
	pringbuff->flagoverflow = 0;
}


/**
  * @brief  压入单字节到缓冲区
  * @param  pRingBuff：待处理的ringbuffer
  *         value：压入的数据
  * @note   
  * @retval void
  */	
void rb_push(user_ring_buffer_t* pringbuff, uint8_t value)
{
    uint8_t* wp_next = pringbuff->wp + 1;
    if( wp_next == pringbuff->pend ) {
	wp_next -= pringbuff->length; // Rewind pointer when exceeds bound
    }
    if( wp_next != pringbuff->rp ) {
	*pringbuff->wp = value;
	pringbuff->wp = wp_next;
    } else {
	pringbuff->flagoverflow = 1;
    }
}

/**
  * @brief  压出单字节到缓冲区
  * @param  pRingBuff：待处理的ringbuffer   
  * @note   
  * @retval 压出的数据
  */	
uint8_t rb_pop(user_ring_buffer_t *pringbuff)
{
    if( pringbuff->rp == pringbuff->wp ) 
        return 0; // empty
  
    uint8_t ret = *(pringbuff->rp++);
    if( pringbuff->rp == pringbuff->pend ) {
	pringbuff->rp -= pringbuff->length; // Rewind pointer when exceeds bound
    }
    return ret;
}

/**
  * @brief  获取缓冲区尚未处理的字节数
  * @param  pRingBuff：待处理的ringbuffer   
  * @note   
  * @retval 待处理的字节数
  */
uint16_t rb_get_count(const user_ring_buffer_t *pringbuff)
{
    return (pringbuff->wp - pringbuff->rp + pringbuff->length) % pringbuff->length;
}

/**
  * @brief  判断缓冲区是否为空
  * @param  pRingBuff：待处理的ringbuffer   
  * @note   
  * @retval 空为1；否则为0
  */
int8_t rb_is_empty(const user_ring_buffer_t *pringbuff)
{
    return pringbuff->wp == pringbuff->rp; 
}

/**
  * @brief  判断缓冲区是否空
  * @param  pRingBuff：待处理的ringbuffer   
  * @note   
  * @retval 满为1；否则为0
  */
int8_t rb_is_full(const user_ring_buffer_t *pringbuff)
{
    return (pringbuff->rp - pringbuff->wp + pringbuff->length - 1) % pringbuff->length == 0;
}


