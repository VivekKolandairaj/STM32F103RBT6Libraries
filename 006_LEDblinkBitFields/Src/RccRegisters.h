/*
 * RccRegisters.h
 *
 *  Created on: Jul 9, 2021
 *      Author: Vivek
 */

#ifndef RCCREGISTERS_H_
#define RCCREGISTERS_H_

#include <stdint.h>

//base address of the RCC register
#define RCCBASEADDRESS       0x40021000
//offset address of the RCC_APB2ENR register
#define RCCAPB2ENROFFSET 0x18

//bit fields of the RCC_APB2ENR register
//see page 113 of the reference manual
typedef struct
{

	uint32_t afio_en: 1;
	uint32_t reserved1: 1;
	uint32_t iopa_en: 1;
	uint32_t iopb_en: 1;
	uint32_t iopc_en: 1;
	uint32_t iopd_en: 1;
	uint32_t iope_en: 1;
	uint32_t iopf_en: 1;
	uint32_t iopg_en: 1;
	uint32_t adc1_en: 1;
	uint32_t adc2_en: 1;
	uint32_t tim1_en: 1;
	uint32_t spi1_en: 1;
	uint32_t tim8_en: 1;
	uint32_t usart1_en: 1;
	uint32_t adc3_en: 1;
	uint32_t reserved2: 3;
	uint32_t tim9_en: 1;
	uint32_t tim10_en: 1;
	uint32_t tim11_en: 1;
	uint32_t reserved3:10;


}RCC_APB2ENR_t;


#endif /* RCCREGISTERS_H_ */
