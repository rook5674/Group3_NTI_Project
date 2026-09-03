#ifndef TIMER_H_
#define TIMER_H_

#include "../LIB/STD_TYPES.h"

/* Initialize Timer0 in Fast PWM mode */
void Timer0_voidInit(void);

/* Set PWM duty cycle from 0% to 100% */
void Timer0_voidSetDutyCycle(u8 A_u8DutyCycle);

#endif /* TIMER_H_ */
