/*
 * LM35.c
 *
 *  Created on: Sep 2, 2026
 *      Author: Nour Reda
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/ADC.h"
#include "LM35.h"


static u16 L_u16Temp;

void HLM35_voidInit(){
   MADC_voidInit(ADC_PRESCALER_64,REF_INTERNAL);
   MADC_voidCallBack(HLM35_voidCallBack);
}
void HLM35_voidStartRead(){
	MADC_voidStartConversion(LM35_CHANNEL);
}
void HLM35_voidCallBack  (void){
	L_u16Temp =  MADC_u16ReadDataUsingInterrupt()*0.25;
}
u16 HLM35_u16GetTemp(){
	return L_u16Temp;
}

