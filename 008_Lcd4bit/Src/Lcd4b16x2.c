/*
 * Lcd4b16x2.c
 *
 *  Created on: Jul 11, 2021
 *      Author: Vivek
 */

#include "Lcd4b16x2.h"
#include "delaymsus.h"
#include "GpioxRegisters.h"
#include <stdint.h>

//create pointer to the GPIOx_ODR register
GPIOb_ODR_t volatile * const pGpiobOdr = (GPIOb_ODR_t*)(GPIOPORTBADDRESS + GPIOXODROFFSET);

//definition of the LCD_init() function
void LCD_init(){

	msec_delay(20); //delay 20ms
	LCD_cmd(0x02);  //0x02 for 4 bit 1 line mode
	LCD_cmd(0x28);  //0x28 for 4 bit 2 lines mode
	LCD_cmd(0x0C);  //0x0C for display on cursor off
	LCD_cmd(0x06);  //0x06 for auto increment cursor
	LCD_cmd(0x01);  //0x01 for clear display
	LCD_cmd(0x80);  //0x80 starting address of line 1
}

//definition of the LCD_cmd() function
void LCD_cmd(uint8_t command){
	pGpiobOdr->nibble = command >> 4; //right shift command by 4 bits and assign it to PB8to11
	pGpiobOdr->odr13 = 0; //Clear RS
	pGpiobOdr->odr12 = 1; //drive E from high to low
	msec_delay(1);
	pGpiobOdr->odr12 = 0;
	msec_delay(5);//high period should be at least 1ms
	msec_delay(10);//introduce a short delay

	pGpiobOdr->nibble = command & 0x0F;  //bitwise and command with bit mask 0x0F and assign it to PB8to11
	pGpiobOdr->odr12 = 1;//drive E from high to low
	msec_delay(1);
	pGpiobOdr->odr12 = 0;
	msec_delay(5); //high period should be at least 1ms
	msec_delay(10);//introduce a short delay

}

//definition of the LCD_char() function
void LCD_char(uint8_t my_character){

	pGpiobOdr->nibble = my_character >> 4; //right shift my_character by 4 bits and assign it to PB8to11
	pGpiobOdr->odr13 = 1; //set RS
	pGpiobOdr->odr12 = 1;//drive E from high to low
	msec_delay(1); //1ms delay
	pGpiobOdr->odr12 = 0;
	msec_delay(5);  //high period should be at least 1ms
	msec_delay(10); //introduce a short delay

	pGpiobOdr->nibble = my_character & 0x0F; //bitwise and command with bit mask 0x0F and assign it to PB8to11
	pGpiobOdr->odr12 = 1; //drive E from high to low
	msec_delay(1); //1ms delay
	pGpiobOdr->odr12 = 0;
	msec_delay(5);//high period should be at least 1ms
	msec_delay(10);//introduce a short delay
}


//definition of the LCD_string() function
void LCD_string(volatile char* my_string){

	//use a for loop to iterate through the elements of the string
	//send each character to the LCD_char() function
	for(uint8_t volatile i = 0; my_string[i] != '\0'; i++){
		LCD_char(my_string[i]);
	}

}
