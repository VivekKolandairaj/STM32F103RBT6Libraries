/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Vivek. K
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
//Blink 2 Led's connected to PB8, and PB9 of the board
#include <stdint.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

//function prototype for the delay function
void myDelay();

int main(void)
{
	//RCC_APB2ENR address is 0x4002_1018
	uint32_t volatile *const pRccApb2Enr = (uint32_t *) 0x40021018;
	//GPIOB_CRH address is 0x4001_0C04
	uint32_t volatile *const pGpiobCrh   = (uint32_t *) 0x40010C04;
	//GPIOB_ODR address is 0x4001_0C0C
	uint32_t volatile *const pGpiobOdr   = (uint32_t *) 0x40010C0C;

	//enable the port B peripheral clock, IOPBEN = 1
	*pRccApb2Enr |= (1 << 3);

	//configure PB9 as low speed output, Mode9[1:0] at bit positions 5 and 4
	//should be 10
	*pGpiobCrh |=  (1 << 5);
	*pGpiobCrh &= ~(1 << 4);
	//configure PB8 as ow speed output, Mode8[1:0] at bit positions 1 and 0
	//should be 10
	*pGpiobCrh |=  (1 << 1);
	*pGpiobCrh &= ~(1 << 0);

	//configure PB9 as output push pull
	//CNF9[1:0] at bit positions 7 and 6 should be 00
	*pGpiobCrh &= ~(3 << 6);

	//configure PB8 as output push pull
	//CNF8[1:0] at bit positions 3 and 2 should be 00
	*pGpiobCrh &= ~(3 << 2);

	//set or reset bit positions 9 and 8 of the GPIOB_ODR forever
	/* Loop forever */
	while(1){

		//set bit 9, reset bit 8
		*pGpiobOdr |=  (1 << 9);
		*pGpiobOdr &= ~(1 << 8);

		//delay
		myDelay();

		//reset bit 9, set bit 8
		*pGpiobOdr &=  ~(1 << 9);
		*pGpiobOdr |=   (1 << 8);

		//delay
		myDelay();


	}
}


//definition of the delay function
void myDelay(){

	for(uint32_t volatile i = 0; i < 200000; i++);
	//waste clock cycles
}



