/*
 * LED.c
 *
 * Created: 8/29/2026 6:57:00 PM
 *  Author: sword
 */

#include "LED.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO.h"

#define DIO_voidSetPinDirection MDIO_voidInitPin
#define DIO_voidSetPinValue     MDIO_voidSetPinValue
#define PIN_OUTPUT              DIO_OUTPUT
#define PIN_HIGH                DIO_HIGH
#define PIN_LOW                 DIO_LOW

void LED_INIT(u8 color){
	switch (color) {
		case GREEN_LED:
		DIO_voidSetPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, PIN_OUTPUT);
		break;
		case YELLOW_LED:
		DIO_voidSetPinDirection(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_OUTPUT);
		break;
		case RED_LED:
		DIO_voidSetPinDirection(RED_LED_PORT, RED_LED_PIN, PIN_OUTPUT);
		break;
		case ALL_LED:
		DIO_voidSetPinDirection(GREEN_LED_PORT, GREEN_LED_PIN, PIN_OUTPUT);
		DIO_voidSetPinDirection(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_OUTPUT);
		DIO_voidSetPinDirection(RED_LED_PORT, RED_LED_PIN, PIN_OUTPUT);
		break;
	}
}

void LED_ON(u8 color){
	switch (color) {
		case GREEN_LED:
		DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, PIN_HIGH);
		break;
		case YELLOW_LED:
		DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_HIGH);
		break;
		case RED_LED:
		DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, PIN_HIGH);
		break;
		case ALL_LED:
		DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, PIN_HIGH);
		DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_HIGH);
		DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, PIN_HIGH);
		break;
	}
}

void LED_OFF(u8 color){
	switch (color) {
		case GREEN_LED:
		DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, PIN_LOW);
		break;
		case YELLOW_LED:
		DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_LOW);
		break;
		case RED_LED:
		DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, PIN_LOW);
		break;
		case ALL_LED:
		DIO_voidSetPinValue(GREEN_LED_PORT, GREEN_LED_PIN, PIN_LOW);
		DIO_voidSetPinValue(YELLOW_LED_PORT, YELLOW_LED_PIN, PIN_LOW);
		DIO_voidSetPinValue(RED_LED_PORT, RED_LED_PIN, PIN_LOW);
		break;
	}
}
