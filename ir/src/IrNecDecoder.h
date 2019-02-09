/*
 * IrNecDecoder.h
 *
 *  Created on: 7 Feb 2019
 *      Author: david
 */

#ifndef IRNECDECODER_H_
#define IRNECDECODER_H_

#include <stdint.h>

class IrNecDecoder {
public:

	class Data {
		uint8_t address;
		uint8_t cmd;
	public:
		Data(uint8_t address, uint8_t cmd) :
				address(address), cmd(cmd) {
		}
		inline uint8_t getAddress() {
			return address;
		}
		inline uint8_t getCmd() {
			return cmd;
		}

	};
private:

	enum States {
		START_1,
		START_2,
		ADDR_BIT_0_HIGH,
		ADDR_BIT_0_LOW,
		ADDR_BIT_1_HIGH,
		ADDR_BIT_1_LOW,
		ADDR_BIT_2_HIGH,
		ADDR_BIT_2_LOW,
		ADDR_BIT_3_HIGH,
		ADDR_BIT_3_LOW,
		ADDR_BIT_4_HIGH,
		ADDR_BIT_4_LOW,
		ADDR_BIT_5_HIGH,
		ADDR_BIT_5_LOW,
		ADDR_BIT_6_HIGH,
		ADDR_BIT_6_LOW,
		ADDR_BIT_7_HIGH,
		ADDR_BIT_7_LOW,
		IADDR_BIT_0_HIGH,
		IADDR_BIT_0_LOW,
		IADDR_BIT_1_HIGH,
		IADDR_BIT_1_LOW,
		IADDR_BIT_2_HIGH,
		IADDR_BIT_2_LOW,
		IADDR_BIT_3_HIGH,
		IADDR_BIT_3_LOW,
		IADDR_BIT_4_HIGH,
		IADDR_BIT_4_LOW,
		IADDR_BIT_5_HIGH,
		IADDR_BIT_5_LOW,
		IADDR_BIT_6_HIGH,
		IADDR_BIT_6_LOW,
		IADDR_BIT_7_HIGH,
		IADDR_BIT_7_LOW,
		CMD_BIT_0_HIGH,
		CMD_BIT_0_LOW,
		CMD_BIT_1_HIGH,
		CMD_BIT_1_LOW,
		CMD_BIT_2_HIGH,
		CMD_BIT_2_LOW,
		CMD_BIT_3_HIGH,
		CMD_BIT_3_LOW,
		CMD_BIT_4_HIGH,
		CMD_BIT_4_LOW,
		CMD_BIT_5_HIGH,
		CMD_BIT_5_LOW,
		CMD_BIT_6_HIGH,
		CMD_BIT_6_LOW,
		CMD_BIT_7_HIGH,
		CMD_BIT_7_LOW,
		ICMD_BIT_0_HIGH,
		ICMD_BIT_0_LOW,
		ICMD_BIT_1_HIGH,
		ICMD_BIT_1_LOW,
		ICMD_BIT_2_HIGH,
		ICMD_BIT_2_LOW,
		ICMD_BIT_3_HIGH,
		ICMD_BIT_3_LOW,
		ICMD_BIT_4_HIGH,
		ICMD_BIT_4_LOW,
		ICMD_BIT_5_HIGH,
		ICMD_BIT_5_LOW,
		ICMD_BIT_6_HIGH,
		ICMD_BIT_6_LOW,
		ICMD_BIT_7_HIGH,
		ICMD_BIT_7_LOW,
		END_HIGH

	};
	States state;
	uint8_t address, iaddress;
	uint8_t cmd, icmd;
public:

	IrNecDecoder() :
			state(START_1), address(0), iaddress(0), cmd(0), icmd(0) {

	}

	Data * decode(int span);

};

#endif /* IRNECDECODER_H_ */
