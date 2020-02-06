/*
 * ras.h
 *
 *  Created on: Oct 22, 2019
 *      Author: Nathanael Bhooshi
 */

#include <stdint.h>

#ifndef RAS_H_
#define RAS_H_

void rasInit(); // defined function from ras.c

void rasRead(uint32_t data[2]);
void ADCRead(uint32_t data[2]);

#endif /* RAS_H_ */
