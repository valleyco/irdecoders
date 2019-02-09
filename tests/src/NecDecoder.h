/*
 * NecDecoder.h
 *
 *  Created on: 9 Feb 2019
 *      Author: david
 */

#ifndef SRC_NECDECODER_H_
#define SRC_NECDECODER_H_

#include <stdint.h>

class NecDecoder {
private:
	const uint16_t pulse_unit = 575;
	enum State {
		START_WAIT, START_HIGH, START_LOW, DATA_HIGH, DATA_LOW, END_HIGH
	} state;
	uint8_t data[4];
	uint8_t pos;
	uint8_t mask;
public:
	NecDecoder() :
			state(START_WAIT), pos(0), mask(0) {
	}
	;
	uint8_t* decode(int length) {
		uint8_t span = (length + pulse_unit / 2) / pulse_unit;
		switch (state) {
		case START_WAIT:
			state = START_HIGH;
			break;
		case START_HIGH:
			if (span == 16) {
				state = START_LOW;
			} else {
				state = START_WAIT;
			}
			break;
		case START_LOW:
			if (span == 8) {
				mask = 1;
				pos = 0;
				data[0] = 0;
				state = DATA_HIGH;
			} else {
				state = START_WAIT;
			}
			break;
		case DATA_HIGH:
			if (span == 1) {
				state = DATA_LOW;
			} else {
				state = START_WAIT;
			}
			break;
		case DATA_LOW:
			if (span == 3) {
				data[pos] |= mask;
			} else if (span != 1) {
				state = START_WAIT;
				break;
			}
			if (mask == 0x80) {
				if (pos == 3) { // END OF PACKET
					state = END_HIGH;
					break;
				}
				pos++;
				mask = 1;
				data[pos] = 0;
			} else {
				mask <<= 1;
			}
			state = DATA_HIGH;
			break;
		case END_HIGH:
			state = START_WAIT;
			if (span == 1) {
				return data;
			}
			break;

		}
		return NULL;
	}

};

#endif /* SRC_NECDECODER_H_ */
