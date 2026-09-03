/*
 * BIT_MATH.h
 *
 *  Created on: 2 Sep 2026
 *      Author: Frenk
 */

#ifndef LIB_BIT_MATH_H_
#define LIB_BIT_MATH_H_


#define SET_BIT(REG, BIT)   ((REG) |= (1 << (BIT)))
#define CLR_BIT(REG, BIT)   ((REG) &= ~(1 << (BIT)))
#define TOG_BIT(REG, BIT)   ((REG) ^= (1 << (BIT)))
#define READ_BIT(REG, BIT)   (((REG) >> (BIT)) & 0x01) //shifts the bit we want to the right (bit) times and then AND it with 1



#endif /* LIB_BIT_MATH_H_ */
