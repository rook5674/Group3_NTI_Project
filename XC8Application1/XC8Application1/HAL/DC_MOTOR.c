/*
 * DC_MOTOR.c
 *
 *  Created on: Sep 3, 2026
 *      Author: dell
 */
#include "../MCAL/DIO_TYPES.h"
#include "../MCAL/DIO_REG.h"
#include "../MCAL/DIO.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAl/Timer.h"
#include "DC_MOTOR.h"

void DcMotor_voidInit (void) {
	MDIO_voidInitPin(MOTOR_PORT_A, MOTOR_PIN_A, DIO_OUTPUT);
	MDIO_voidInitPin(MOTOR_PORT_B, MOTOR_PIN_B, DIO_OUTPUT);
}

void DcMotor_voidCW (void) {
	MDIO_voidSetPinValue(MOTOR_PORT_A, MOTOR_PIN_A, DIO_HIGH);
	MDIO_voidSetPinValue(MOTOR_PORT_B, MOTOR_PIN_B, DIO_LOW);
}

void DcMotor_voidCCW (void) {
	MDIO_voidSetPinValue(MOTOR_PORT_A, MOTOR_PIN_A, DIO_LOW);
	MDIO_voidSetPinValue(MOTOR_PORT_B, MOTOR_PIN_B, DIO_HIGH);
}

void DcMotor_voidStop (void) {
	MDIO_voidSetPinValue(MOTOR_PORT_A, MOTOR_PIN_A, DIO_LOW);
	MDIO_voidSetPinValue(MOTOR_PORT_B, MOTOR_PIN_B, DIO_LOW);
}

void DcMotor_voidSetSpeed (u8 A_u8Speed) {
	Timer0_voidSetDutyCycle(A_u8Speed);
}
