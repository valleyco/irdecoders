/*
 * main.cpp
 *
 *  Created on: 7 Feb 2019
 *      Author: david
 */
#include <stdio.h>
#include "IrNecDecoder.h"
#include "NecDecoder.h"

int main() {

	uint8_t data[] = { 16, 8, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
			3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 3, 1, 1, 1, 3, 1, 1,
			1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 3, 1, 1, 1, 3, 1, 3, 1, 3, 1, 1, 1,
			3, 1 };
	int timing[] = { 9380, 4660, 560, 620, 580, 600, 580, 600, 560, 580, 600,
			580, 580, 600, 580, 580, 580, 600, 580, 1740, 560, 1740, 580, 1740,
			580, 1740, 560, 1720, 600, 1740, 580, 1740, 560, 1760, 540, 1760,
			580, 580, 580, 1740, 580, 600, 560, 600, 540, 620, 580, 1720, 600,
			600, 580, 580, 580, 1720, 600, 580, 560, 1740, 600, 1740, 560, 1740,
			580, 600, 580, 1740, 560 };
	IrNecDecoder ir;
	/*
	for (uint16_t i = 0; i < sizeof data; i++) {
		int d = (timing[i] + 50) / 575;
		if (d != data[i]) {
			printf("%i is wrong", i);
		} else {
			printf(".");
		}
	}
*/
	for (uint16_t i = 0; i < sizeof data; i++) {
		IrNecDecoder::Data* result = ir.decode(timing[i]);
		if (result != NULL) {
			printf("address:%i,cmd:%i",(int)result->getAddress(),(int)result->getCmd());
		}

	}
}
