#ifndef TIMER_REG_H_
#define TIMER_REG_H_

#include "../LIB/STD_TYPES.h"

/* Timer/Counter Control Register */
#define TCCR0   (*(volatile u8*)0x53)

/* Output Compare Register */
#define OCR0    (*(volatile u8*)0x5C)

/* Timer/Counter Register */
#define TCNT0   (*(volatile u8*)0x52)


/* Bit Definitions for TCCR0 */
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6


#endif /* TIMER_REG_H_ */
