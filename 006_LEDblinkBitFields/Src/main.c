/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Vivek. K
 * @brief          : modification of 003_LEDblink project using bit fields
 * 					 toggle LED connected to PB13
 ******************************************************************************
 */

//connections for stlink v2 in my development board
//PA 13 --> SWDIO. Pin 7 JTAG connector
//PA 14 --> SWCLK. Pin 9 JTAG connector
//3.3 v supply.    Pin 2 JTAG connector
//GND.             Pin 4, 6, 8, ... 20 JTAG connector

#include <stdint.h>
#include "RccRegisters.h"
#include "GpioxRegisters.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


//function prototype for the millisecond delay function
void msec_delay(uint16_t delay);

int main(void)
{
    //create pointer to the RCC_APB2ENR register
	RCC_APB2ENR_t volatile * const pRccApb2Enr = (RCC_APB2ENR_t*) (RCCBASEADDRESS + RCCAPB2ENROFFSET);
	//create pointer to the GPIOx_CRH register
	GPIOx_CRH_t volatile * const pGpiobCrh = (GPIOx_CRH_t*)(GPIOPORTBADDRESS + GPIOXCRHOFFSET);
	//create pointer to the GPIOx_ODR register
	GPIOx_ODR_t volatile * const pGpiobOdr = (GPIOx_ODR_t*)(GPIOPORTBADDRESS + GPIOXODROFFSET);

	//enable the port b clock
	pRccApb2Enr->iopb_en = 1;

	//configure PB13 as low speed push pull output
	pGpiobCrh->cnf13  = 0; //00 means output push pull
	pGpiobCrh->mode13 = 2; //low speed output

	/* Loop forever */
	while(1){

		//set PB13
		pGpiobOdr->odr13 = 1;

		//delay by 1 second
		msec_delay(1000);

		//clear PB13
		pGpiobOdr->odr13 = 0;

		//delay by 1 second
		msec_delay(1000);
	}
}

//function definition for the millisecond delay function
void msec_delay(uint16_t delay)
{
	for(; delay > 0; delay --){
		for(uint8_t volatile i = 0; i <=168; i++);
	}

}
