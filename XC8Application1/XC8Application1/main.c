/*
 * main.c
 *
 * Created: 9/2/2026 2:01:35 PM
 *  Author: sword
 */ 

#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdio.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "MCAL/DIO.h"
#include "HAL/LCD.h"
#include "HAL/LED.h"
#include "HAL/DC_MOTOR.h"
#include "HAL/LM35.h"
#include "MCAL/Timer.h"

int main(void)
{
	//the temp at which the system cools is when c is higher than 25. at temps lower than 20 the system heats 
	DcMotor_voidInit();
	LED_INIT(YELLOW_LED);
	LED_INIT(GREEN_LED);
	LCD_Init();
	HLM35_voidInit();
	Timer0_voidInit();
	u8 state=0;
	u8 tempLast;
    while(1)
    {
	HLM35_voidStartRead();
	_delay_ms(30);
	u8 temp = HLM35_u16GetTemp();
	if(temp>=26){
		LED_OFF(YELLOW_LED);
		LED_ON(GREEN_LED);
		if(state!=1){
		LCD_Command(LCD_CLR);
		LCD_MoveCursor(0, 0);
		LCD_SendString("Cooling");
		state=1;
		}
		if(temp>45){
			DcMotor_voidCCW();
			DcMotor_voidSetSpeed(255);
		}
		else{
			f32 motorSpeed =  9.21*temp - 159.5;//function to linearly increase speed up until temp =45
			DcMotor_voidCCW();
			DcMotor_voidSetSpeed(motorSpeed);
		}
	
    }
	else if(temp<=19){
		LED_OFF(YELLOW_LED);
		LED_ON(GREEN_LED);
		if(state!=2){
			LCD_Command(LCD_CLR);
			LCD_MoveCursor(0, 0);
			LCD_SendString("Heating");
			state =2;
		}
		if(temp<5){
			DcMotor_voidCW();
			DcMotor_voidSetSpeed(225);
		}
		else{
			f32 motorSpeed = -12.5*temp + 317.5;//function to linearly increase speed up until temp =5
			DcMotor_voidCW();
			DcMotor_voidSetSpeed(motorSpeed);
		}
	}
	
	else{
		DcMotor_voidStop();
		LED_ON(YELLOW_LED);
		LED_OFF(GREEN_LED);
		if(state!=3){
			LCD_Command(LCD_CLR);
			LCD_MoveCursor(0, 0);
			LCD_SendString("Inactive");
			state=3;
		}
	}
	if(temp!=tempLast){
	LCD_MoveCursor(1, 0);
	LCD_SendString("Temp: ");

	LCD_MoveCursor(1, 6);
	LCD_SendString("   ");

	char tempStr[4];
	sprintf(tempStr, "%d", temp);

	LCD_MoveCursor(1, 6);
	LCD_SendString(tempStr);

	LCD_SendString(" C");
	}
	tempLast=temp;
}
}