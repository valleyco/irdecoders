/*
 * TadDecoder.h
 *
 *  Created on: 9 Feb 2019
 *      Author: david
 */

#ifndef SRC_TADDECODER_H_
#define SRC_TADDECODER_H_
#include <stdint.h>

class TadDecoder {
	const static uint16_t pulse_unit = 638;
	const static uint16_t packet_length = 8;
	enum State {
		START_WAIT, START_HIGH, START_LOW, DATA_HIGH, DATA_LOW, END_HIGH
	} state;
	uint8_t data[packet_length];
	uint8_t pos;
	uint8_t mask;
	uint8_t expected;

public:
	TadDecoder() :
			state(START_WAIT), pos(0), mask(0), expected(0) {

	}
	uint8_t* decode(int length) {
		uint8_t span = (length + pulse_unit / 2) / pulse_unit;
		switch (state) {
		case START_WAIT:
			state = START_HIGH;
			break;
		case START_HIGH:
			if (span == 13) {
				state = START_LOW;
			} else {
				state = START_WAIT;
			}
			break;
		case START_LOW:
			if (span == 7) {
				mask = 1;
				pos = 0;
				data[0] = 0;
				state = DATA_HIGH;
			} else {
				state = START_WAIT;
			}
			break;
		case DATA_HIGH:
			if (span == 3) {
				expected = 1;
				state = DATA_LOW;
			} else if (span == 1) {
				expected = 3;
				state = DATA_LOW;
			} else {
				state = START_WAIT;
			}
			break;
		case DATA_LOW:
			if (span != expected) {
				state = START_WAIT;
				break;
			}
			if (span == 3) {
				data[pos] |= mask;
			}
			if (mask == 0x80) {
				pos++;
				if (pos == packet_length) { // END OF PACKET
					state = END_HIGH;
					break;
				}
				data[pos] = 0;
				mask = 1;
			} else {
				mask <<= 1;
			}
			state = DATA_HIGH;
			break;
		case END_HIGH:
			state = START_WAIT;
			if (span == 3) {
				return data;
			}
			break;
		}
		return NULL;
	}
};

#endif /* SRC_TADDECODER_H_ */
