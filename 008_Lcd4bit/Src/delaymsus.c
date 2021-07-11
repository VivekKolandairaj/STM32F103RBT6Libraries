/*
 * delaymsus.c
 *
 *  Created on: 11-Jul-2021
 *      Author: Vivek
 */


#include "delaymsus.h"
#include <stdint.h>

//definition of the msec_delay() function
void msec_delay(uint16_t delay){

	for(; delay > 0; delay --){
			for(uint8_t volatile i = 0; i <=168; i++);
		}//waste clock cycles

}

//definition of the usec_delay() function
void usec_delay(uint16_t delay){

//not yet implemented

}

