/*
 * LCD.c
 *
 * Created: 8/8/2026 6:44:44 PM
 *  Author: sword
 */

#include "LCD.h"
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/DIO.h"

#define DIO_voidSetPortDirection MDIO_voidInitPort
#define DIO_voidSetPinValue      MDIO_voidSetPinValue
#define DIO_voidSetPortValue     MDIO_voidSetPortValue

void LCD_Init(void){
	DIO_voidSetPortDirection(LCD_CONTROL_PORT, PORT_OUTPUT);
	DIO_voidSetPortDirection(LCD_DATA_PORT, PORT_OUTPUT);
	_delay_ms(40);
	LCD_Command(LCD_FUN_SET_TWOLINE_5x8);
	LCD_Command(lcd_DisplayOn_CursorOff);
	LCD_Command(LCD_CLR);
}

void LCD_Command(u8 comm){
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, PIN_LOW);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, PIN_LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT, comm);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, PIN_LOW);
}

void LCD_Data(u8 data){
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RS_PIN, PIN_HIGH);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_RW_PIN, PIN_LOW);

	DIO_voidSetPortValue(LCD_DATA_PORT, data);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, PIN_HIGH);
	_delay_ms(2);
	DIO_voidSetPinValue(LCD_CONTROL_PORT, LCD_E_PIN, PIN_LOW);
}

void LCD_SendString(const u8 *Str) {
	u8 i = 0;
	while (Str[i] != '\0') {
		LCD_Data(Str[i]);
		i++;
	}
}

void LCD_MoveCursor(u8 row, u8 col) {
	u8 address;
	if (row == 0) {
		address = 0x80 + col;
	} else {
		address = 0xC0 + col;
	}
	LCD_Command(address);
}

void LCD_STORE_CUST_CHAR(u8* arr_char, u8 no) {
	if (no < 8) {
		LCD_Command(0x40 + (no * 8));

		for (u8 i = 0; i < 8; i++) {
			LCD_Data(arr_char[i]);
		}

		LCD_Command(0x80);
	}
}
