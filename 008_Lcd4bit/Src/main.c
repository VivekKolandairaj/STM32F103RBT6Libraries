/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Displaying "Embedded Systems Laboratory" in a 16x2 LCD
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "RccRegisters.h"
#include "GpioxRegisters.h"
#include "Lcd4b16x2.h"
#include "delaymsus.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


int main(void)
{
	//create pointer to the RCC_APB2ENR register
	RCC_APB2ENR_t volatile * const pRccApb2Enr = (RCC_APB2ENR_t*) (RCCBASEADDRESS + RCCAPB2ENROFFSET);
	//create pointer to the GPIOx_CRH register
	GPIOx_CRH_t volatile * const pGpiobCrh = (GPIOx_CRH_t*)(GPIOPORTBADDRESS + GPIOXCRHOFFSET);

        	//enable the port b clock
			pRccApb2Enr->iopb_en = 1;

			//PB8 PB9 PB10 PB11 PB12 PB13 of MCU are connected to
			//D4  D5  D6   D7   E    RS   of 16x2 LCD

			//configure PB8, PB9, PB10, PB11, PB12, and PB13 as low speed push pull output
			pGpiobCrh->cnf8  = 0; //00 means output push pull
			pGpiobCrh->mode8 = 2; //low speed output
			pGpiobCrh->cnf9  = 0; //00 means output push pull
			pGpiobCrh->mode9 = 2; //low speed output
			pGpiobCrh->cnf10  = 0; //00 means output push pull
			pGpiobCrh->mode10 = 2; //low speed output
			pGpiobCrh->cnf11  = 0; //00 means output push pull
			pGpiobCrh->mode11 = 2; //low speed output
			pGpiobCrh->cnf12  = 0; //00 means output push pull
			pGpiobCrh->mode12 = 2; //low speed output
			pGpiobCrh->cnf13  = 0; //00 means output push pull
			pGpiobCrh->mode13 = 2; //low speed output

			//initialize the LCD
			LCD_init();
			//the string to be displayed in line 1
			volatile char* line1 = {"Embedded Systems"};
			//display the above string in line 1 of the LCD
			LCD_cmd(0x80); //line 1 starting address
			LCD_string(line1);

			//the string to be displayed in line 2
			volatile char* line2 = {"Laboratory"};
			//display the string in line 2 of the LCD
			LCD_cmd(0xC0); //line 2 starting address
			LCD_string(line2);

    /* Loop forever */
	for(;;){
		//LCD_cmd(0x80);
		//LCD_string("WTF");
	}
}

