/*
 * TIMER.c
 *
 * Timer0 - Fast PWM
 * ATmega32
 */

#include "../LIB/STD_TYPES.h"
#include "TIMER.h"
#include "TimerReg.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO.h"
#include "../MCAL/DIO_REG.h"


void Timer0_voidInit(void)
{
    /*
     * Timer0 Fast PWM Mode
     *
     * WGM00 = 1
     * WGM01 = 1
     *
     * Non-Inverting PWM
     *
     * COM01 = 1
     * COM00 = 0
     *
     * Prescaler = 64
     */

        MDIO_voidInitPin(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
    SET_BIT(TCCR0, WGM00);
    SET_BIT(TCCR0, WGM01);

    SET_BIT(TCCR0, COM01);
    CLR_BIT(TCCR0, COM00);

    /* Prescaler = 64 */
    SET_BIT(TCCR0, CS00);
    SET_BIT(TCCR0, CS01);
    CLR_BIT(TCCR0, CS02);

    /* Initial duty cycle = 0% */
    OCR0 = 0;
}


void Timer0_voidSetDutyCycle(u8 A_u8DutyCycle)
{
    /*
     * Duty Cycle = 0 --> OCR0 = 0
     * Duty Cycle = 100 --> OCR0 = 255
     */

    if (A_u8DutyCycle >= 255)
    {
        OCR0 = 255;
    }
    else
    {
        OCR0 =  A_u8DutyCycle;
    }
}
