/*
 * GpioxRegisters.h
 *
 *  Created on: Jul 9, 2021
 *      Author: Vivek
 */

#ifndef GPIOXREGISTERS_H_
#define GPIOXREGISTERS_H_

#include <stdint.h>

//base addresses of the GPIOx registers
#define GPIOPORTAADDRESS 0x40010800
#define GPIOPORTBADDRESS 0x40010C00
#define GPIOPORTCADDRESS 0x40011000
#define GPIOPORTDADDRESS 0x40011400
#define GPIOPORTEADDRESS 0x40011800
#define GPIOPORTFADDRESS 0x40011C00
#define GPIOPORTGADDRESS 0x40012000

//offset addresses of the GPIOx registers
#define GPIOXCRLOFFSET  0x00
#define GPIOXCRHOFFSET  0x04
#define GPIOXIDROFFSET  0x08
#define GPIOXODROFFSET  0x0C
#define GPIOXBSRROFFSET 0x10
#define GPIOXBRROFFSET  0x14
#define GPIOXLCKROFFSET 0x18

//bit fields of the GPIOx_CRL register

typedef struct
{

	uint32_t mode0: 2;
	uint32_t cnf0 : 2;
	uint32_t mode1: 2;
	uint32_t cnf1 : 2;
	uint32_t mode2: 2;
	uint32_t cnf2 : 2;
	uint32_t mode3: 2;
	uint32_t cnf3 : 2;
	uint32_t mode4: 2;
	uint32_t cnf4 : 2;
	uint32_t mode5: 2;
	uint32_t cnf5 : 2;
	uint32_t mode6: 2;
	uint32_t cnf6 : 2;
	uint32_t mode7: 2;
	uint32_t cnf7 : 2;

}GPIOx_CRL_t;


//bit fields of the GPIOx_CRH register
typedef struct
{

	uint32_t mode8 : 2;
	uint32_t cnf8  : 2;
	uint32_t mode9 : 2;
	uint32_t cnf9  : 2;
	uint32_t mode10: 2;
	uint32_t cnf10 : 2;
	uint32_t mode11: 2;
	uint32_t cnf11 : 2;
	uint32_t mode12: 2;
	uint32_t cnf12 : 2;
	uint32_t mode13: 2;
	uint32_t cnf13 : 2;
	uint32_t mode14: 2;
	uint32_t cnf14 : 2;
	uint32_t mode15: 2;
	uint32_t cnf15 : 2;

}GPIOx_CRH_t;


//bit fields of the GPIOx_IDR register
typedef struct
{
	uint32_t idr0    :  1;
	uint32_t idr1    :  1;
	uint32_t idr2    :  1;
	uint32_t idr3    :  1;
	uint32_t idr4    :  1;
	uint32_t idr5    :  1;
	uint32_t idr6    :  1;
	uint32_t idr7    :  1;
	uint32_t idr8    :  1;
	uint32_t idr9    :  1;
	uint32_t idr10   :  1;
	uint32_t idr11   :  1;
	uint32_t idr12   :  1;
	uint32_t idr13   :  1;
	uint32_t idr14   :  1;
	uint32_t idr15   :  1;
	uint32_t reserved: 16;

}GPIOx_IDR_t;


//bit fields of the GPIOx_ODR register
typedef struct
{

	uint32_t odr0    :  1;
	uint32_t odr1    :  1;
	uint32_t odr2    :  1;
	uint32_t odr3    :  1;
	uint32_t odr4    :  1;
	uint32_t odr5    :  1;
	uint32_t odr6    :  1;
	uint32_t odr7    :  1;
	uint32_t odr8    :  1;
	uint32_t odr9    :  1;
	uint32_t odr10   :  1;
	uint32_t odr11   :  1;
	uint32_t odr12   :  1;
	uint32_t odr13   :  1;
	uint32_t odr14   :  1;
	uint32_t odr15   :  1;
	uint32_t reserved: 16;

}GPIOx_ODR_t;


//bit fields of the GPIOx_BSRR register
typedef struct
{
	uint32_t bs0 : 1;
	uint32_t bs1 : 1;
	uint32_t bs2 : 1;
	uint32_t bs3 : 1;
	uint32_t bs4 : 1;
	uint32_t bs5 : 1;
	uint32_t bs6 : 1;
	uint32_t bs7 : 1;
	uint32_t bs8 : 1;
	uint32_t bs9 : 1;
	uint32_t bs10: 1;
	uint32_t bs11: 1;
	uint32_t bs12: 1;
	uint32_t bs13: 1;
	uint32_t bs14: 1;
	uint32_t bs15: 1;
	uint32_t br0 : 1;
	uint32_t br1 : 1;
	uint32_t br2 : 1;
	uint32_t br3 : 1;
	uint32_t br4 : 1;
	uint32_t br5 : 1;
	uint32_t br6 : 1;
	uint32_t br7 : 1;
	uint32_t br8 : 1;
	uint32_t br9 : 1;
	uint32_t br10: 1;
	uint32_t br11: 1;
	uint32_t br12: 1;
	uint32_t br13: 1;
	uint32_t br14: 1;
	uint32_t br15: 1;


}GPIOx_BSRR_t;


//bit fields of the GPIOx_BRR register
typedef struct
{
	uint32_t br0 : 1;
	uint32_t br1 : 1;
	uint32_t br2 : 1;
	uint32_t br3 : 1;
	uint32_t br4 : 1;
	uint32_t br5 : 1;
	uint32_t br6 : 1;
	uint32_t br7 : 1;
	uint32_t br8 : 1;
	uint32_t br9 : 1;
	uint32_t br10: 1;
	uint32_t br11: 1;
	uint32_t br12: 1;
	uint32_t br13: 1;
	uint32_t br14: 1;
	uint32_t br15: 1;


}GPIOx_BRR_t;

//bit fields of the GPIOx_LCKR register

#endif /* GPIOXREGISTERS_H_ */
