/*
 * LM35.h
 *
 *  Created on: Sep 2, 2026
 *      Author: Nour Reda
 */

#ifndef HAL_HLM35_LM35_H_
#define HAL_HLM35_LM35_H_

#define LM35_CHANNEL ADC_CHANNEL0

void HLM35_voidInit      ();
void HLM35_voidStartRead ();
u16 HLM35_u16GetTemp     ();
void HLM35_voidCallBack  (void);


#endif /* HAL_HLM35_LM35_H_ */
