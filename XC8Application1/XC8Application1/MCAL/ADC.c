/*
 * ADC.c
 *
 *  Created on: Sep 1, 2026
 *      Author: Nour Reda
 */
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include "ADC.h"

void (*ADCPtr)(void);

void MADC_voidInit               (u8 A_u8Prescaler,u8 A_u8Ref){
	switch (A_u8Ref){
	case REF_AREF:
		CLR_BIT(ADMUX,6);
		CLR_BIT(ADMUX,7);
		break;
	case REF_AVCC:
			SET_BIT(ADMUX,6);
			CLR_BIT(ADMUX,7);
			break;
	case REF_INTERNAL:
			SET_BIT(ADMUX,6);
			SET_BIT(ADMUX,7);
			break;
	}

	switch (A_u8Prescaler){
		case ADC_PRESCALER_2:
			CLR_BIT(ADCSRA,0);
			CLR_BIT(ADCSRA,1);
			CLR_BIT(ADCSRA,2);
			break;
		case ADC_PRESCALER_4:
			CLR_BIT(ADCSRA,0);
			SET_BIT(ADCSRA,1);
			CLR_BIT(ADCSRA,2);
					break;
		case ADC_PRESCALER_8:
			SET_BIT(ADCSRA,0);
			SET_BIT(ADCSRA,1);
			CLR_BIT(ADCSRA,2);
					break;
		case ADC_PRESCALER_16:
			CLR_BIT(ADCSRA,0);
			CLR_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,2);
					break;
		case ADC_PRESCALER_32:
			SET_BIT(ADCSRA,0);
			CLR_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,2);
					break;
		case ADC_PRESCALER_64:
			CLR_BIT(ADCSRA,0);
			SET_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,2);
			       break;
		case ADC_PRESCALER_128:
			SET_BIT(ADCSRA,0);
			SET_BIT(ADCSRA,1);
			SET_BIT(ADCSRA,2);
					break;

	}
	SET_BIT(ADCSRA,7);
#if ADC_INTERRUPT_ENABLE == 1
	SET_BIT(ADCSRA,3);
	SET_BIT(SREG,7);
#endif

}
void MADC_voidStartConversion    (u8 A_u8ChannelNumber){
	switch (A_u8ChannelNumber){
	case ADC_CHANNEL0:
		CLR_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		break;
	case ADC_CHANNEL1:
		SET_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		break;
	case ADC_CHANNEL2:
		CLR_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		break;
	case ADC_CHANNEL3:
		SET_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		CLR_BIT(ADMUX,2);
		break;
	case ADC_CHANNEL4:
		CLR_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
	    break;
	case ADC_CHANNEL5:
		SET_BIT(ADMUX,0);
		CLR_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		break;
	case ADC_CHANNEL6:
		CLR_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		break;
	case ADC_CHANNEL7:
		SET_BIT(ADMUX,0);
		SET_BIT(ADMUX,1);
		SET_BIT(ADMUX,2);
		break;
	}
	SET_BIT(ADCSRA,6);
}
u16  MADC_u16ReadDataUsingInterrupt (void){
	return ADC;
}
u16  MADC_u16ReadDataUsingPolling   (void){
	while (READ_BIT(ADCSRA,4)==0);
	SET_BIT(ADCSRA,4);
	return ADC;
}
void MADC_voidCallBack(void (*fptr) (void)){
	ADCPtr=fptr;
}
void __vector_16 (void)__attribute__((signal)) ;
void __vector_16 (void){
	ADCPtr();
}
