/*
 * LED.h
 *
 * Created: 8/29/2026 6:35:17 PM
 *  Author: sword
 */

#include "../MCAL/DIO.h"
#include "../LIB/STD_TYPES.h"

#ifndef LED_H_
#define LED_H_

#define GREEN_LED_PORT  DIO_PORTA
#define YELLOW_LED_PORT DIO_PORTA
#define RED_LED_PORT    DIO_PORTA

#define GREEN_LED_PIN   DIO_PIN3 // ghayart de aashan el conflict ma3 el adc channel 0
#define YELLOW_LED_PIN  DIO_PIN1
#define RED_LED_PIN     DIO_PIN2

void LED_INIT(u8 color);
void LED_ON(u8 color);
void LED_OFF(u8 color);

#define GREEN_LED  0
#define YELLOW_LED 1
#define RED_LED    2
#define ALL_LED    3

#endif
