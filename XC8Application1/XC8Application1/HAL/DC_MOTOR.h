/*
 * DC_MOTOR.h
 *
 *  Created on: Sep 3, 2026
 *      Author: dell
 */

#ifndef DC_MOTOR_DC_MOTOR_H_
#define DC_MOTOR_DC_MOTOR_H_


#define MOTOR_PORT_A  DIO_PORTB
#define MOTOR_PIN_A   DIO_PIN0
#define MOTOR_PORT_B  DIO_PORTB
#define MOTOR_PIN_B   DIO_PIN1

void DcMotor_voidInit (void) ;
void DcMotor_voidCW   (void) ;
void DcMotor_voidCCW  (void) ;
void DcMotor_voidStop (void) ;
void DcMotor_voidSetSpeed (u8 A_u8Speed);

#endif /* DC_MOTOR_DC_MOTOR_H_ */
