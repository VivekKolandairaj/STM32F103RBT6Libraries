/*
 * Lcd4b16x2.h
 *
 *  Created on: Jul 10, 2021
 *      Author: Vivek
 *      Port B pins 8, 9, 10, and 11, are connected to the
 *      high order data pins D4, D5, D6, and D7 of the LCD
 *      Port B pin 12 is connected to the E pin of the LCD
 *      Port B pin 13 is connected to the RS pin of the LCD
 *
 */

#ifndef LCD4B16X2_H_
#define LCD4B16X2_H_

#include <stdint.h>

//function prototype for LCD initialization in
//4 bit, 2 lines mode
void LCD_init();

//function prototype for sending command to the LCD
void LCD_cmd(uint8_t command);

//function prototype for sending a character to the LCD
void LCD_char(uint8_t my_character);

//function prototype for sending a string to the LCD
void LCD_string(volatile char* my_string);


#endif /* LCD4B16X2_H_ */
