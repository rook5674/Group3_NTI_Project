#ifndef LCD_H_
#define LCD_H_

#define F_CPU 8000000UL
#include <util/delay.h>
#include "../MCAL/DIO.h"
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#define LCD_CONTROL_PORT  DIO_PORTC
#define LCD_DATA_PORT     DIO_PORTD

#define LCD_RS_PIN  DIO_PIN0
#define LCD_RW_PIN  DIO_PIN1
#define LCD_E_PIN   DIO_PIN2

#define LCD_D0_PIN  DIO_PIN0
#define LCD_D1_PIN  DIO_PIN1
#define LCD_D2_PIN  DIO_PIN2
#define LCD_D3_PIN  DIO_PIN3
#define LCD_D4_PIN  DIO_PIN4
#define LCD_D5_PIN  DIO_PIN5
#define LCD_D6_PIN  DIO_PIN6
#define LCD_D7_PIN  DIO_PIN7

#define PORT_OUTPUT 0xFF
#define PIN_HIGH    DIO_HIGH
#define PIN_LOW     DIO_LOW

#define HIGH 1
#define LOW  0

#define LCD_CLR                   0x01
#define LCD_HOME                  0x02
#define LCD_SHIFT_RIGHT           0X1C
#define LCD_SHIFT_LEFT            0X18
#define LCD_FUN_SET_TWOLINE_5x8   0x38
#define LCD_FUN_SET_TWOLINE_5x11  0x3C
#define LCD_DIS_ON_SETUP          0x0F
#define lcd_DisplayOn_CursorOff   0x0C
#define lcd_DisplayOn_CursorOn    0x0E
#define lcd_DisplayOff_CursorOff  0x08
#define LCD_EntryMode             0x06



void LCD_Command(u8 comm);
void LCD_Data(u8 data);
void LCD_Init(void);
void LCD_SendString(const u8 *Str);
void LCD_MoveCursor(u8 row, u8 col);
void create_custome(u8 *Str, u8 custom_number);
#endif
