#include "IrNecDecoder.h"
IrNecDecoder::Data * IrNecDecoder::decode(int timespan) {
	 int span = (timespan + 50) / 575;

	switch (this->state) {
	case START_1:
		if (span == 16) {
			this->state = START_2;
		}
		break;
	case START_2:
		if (span == 8) {
			this->state = ADDR_BIT_0_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_0_HIGH:
		if (span == 1) {
			this->state = ADDR_BIT_0_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_0_LOW:
		if (span == 1) {
			address = 0;
			this->state = ADDR_BIT_1_HIGH;
		} else if (span == 3) {
			address = 1;
			this->state = ADDR_BIT_1_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_1_HIGH:
		if (span == 1) {
			this->state = ADDR_BIT_1_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_1_LOW:
		if (span == 1) {
			this->state = ADDR_BIT_2_HIGH;
		} else if (span == 3) {
			address |= 2;
			this->state = ADDR_BIT_2_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_2_HIGH:
		if (span == 1) {
			this->state = ADDR_BIT_2_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_2_LOW:
		if (span == 1) {
			this->state = ADDR_BIT_3_HIGH;
		} else if (span == 3) {
			address |= 4;
			this->state = ADDR_BIT_3_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_3_HIGH:
		if (span == 1) {
			this->state = ADDR_BIT_3_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_3_LOW:
		if (span == 1) {
			this->state = ADDR_BIT_4_HIGH;
		} else if (span == 3) {
			address |= 8;
			this->state = ADDR_BIT_4_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_4_HIGH:
		if (span == 1) {
			this->state = ADDR_BIT_4_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_4_LOW:
		if (span == 1) {
			this->state = ADDR_BIT_5_HIGH;
		} else if (span == 3) {
			address |= 16;
			this->state = ADDR_BIT_5_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_5_HIGH:
		if (span == 1) {
			this->state = ADDR_BIT_5_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_5_LOW:
		if (span == 1) {
			this->state = ADDR_BIT_6_HIGH;
		} else if (span == 3) {
			address |= 32;
			this->state = ADDR_BIT_6_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_6_HIGH:
		if (span == 1) {
			this->state = ADDR_BIT_6_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_6_LOW:
		if (span == 1) {
			this->state = ADDR_BIT_7_HIGH;
		} else if (span == 3) {
			address |= 64;
			this->state = ADDR_BIT_7_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_7_HIGH:
		if (span == 1) {
			this->state = ADDR_BIT_7_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ADDR_BIT_7_LOW:
		if (span == 1) {
			this->state = IADDR_BIT_0_HIGH;
		} else if (span == 3) {
			address |= 128;
			this->state = IADDR_BIT_0_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_0_HIGH:
		if (span == 1) {
			this->state = IADDR_BIT_0_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_0_LOW:
		if (span == 1) {
			iaddress = 0;
			this->state = IADDR_BIT_1_HIGH;
		} else if (span == 3) {
			iaddress = 1;
			this->state = IADDR_BIT_1_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_1_HIGH:
		if (span == 1) {
			this->state = IADDR_BIT_1_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_1_LOW:
		if (span == 1) {
			this->state = IADDR_BIT_2_HIGH;
		} else if (span == 3) {
			iaddress |= 2;
			this->state = IADDR_BIT_2_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_2_HIGH:
		if (span == 1) {
			this->state = IADDR_BIT_2_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_2_LOW:
		if (span == 1) {
			this->state = IADDR_BIT_3_HIGH;
		} else if (span == 3) {
			iaddress |= 4;
			this->state = IADDR_BIT_3_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_3_HIGH:
		if (span == 1) {
			this->state = IADDR_BIT_3_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_3_LOW:
		if (span == 1) {
			this->state = IADDR_BIT_4_HIGH;
		} else if (span == 3) {
			iaddress |= 8;
			this->state = IADDR_BIT_4_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_4_HIGH:
		if (span == 1) {
			this->state = IADDR_BIT_4_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_4_LOW:
		if (span == 1) {
			this->state = IADDR_BIT_5_HIGH;
		} else if (span == 3) {
			iaddress |= 16;
			this->state = IADDR_BIT_5_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_5_HIGH:
		if (span == 1) {
			this->state = IADDR_BIT_5_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_5_LOW:
		if (span == 1) {
			this->state = IADDR_BIT_6_HIGH;
		} else if (span == 3) {
			iaddress |= 32;
			this->state = IADDR_BIT_6_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_6_HIGH:
		if (span == 1) {
			this->state = IADDR_BIT_6_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_6_LOW:
		if (span == 1) {
			this->state = IADDR_BIT_7_HIGH;
		} else if (span == 3) {
			iaddress |= 64;
			this->state = IADDR_BIT_7_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_7_HIGH:
		if (span == 1) {
			this->state = IADDR_BIT_7_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case IADDR_BIT_7_LOW:
		if (span == 1) {
			this->state = CMD_BIT_0_HIGH;
		} else if (span == 3) {
			iaddress |= 128;
			this->state = CMD_BIT_0_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_0_HIGH:
		if (span == 1) {
			this->state = CMD_BIT_0_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_0_LOW:
		if (span == 1) {
			cmd = 0;
			this->state = CMD_BIT_1_HIGH;
		} else if (span == 3) {
			cmd = 1;
			this->state = CMD_BIT_1_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_1_HIGH:
		if (span == 1) {
			this->state = CMD_BIT_1_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_1_LOW:
		if (span == 1) {
			this->state = CMD_BIT_2_HIGH;
		} else if (span == 3) {
			cmd |= 2;
			this->state = CMD_BIT_2_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_2_HIGH:
		if (span == 1) {
			this->state = CMD_BIT_2_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_2_LOW:
		if (span == 1) {
			this->state = CMD_BIT_3_HIGH;
		} else if (span == 3) {
			cmd |= 4;
			this->state = CMD_BIT_3_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_3_HIGH:
		if (span == 1) {
			this->state = CMD_BIT_3_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_3_LOW:
		if (span == 1) {
			this->state = CMD_BIT_4_HIGH;
		} else if (span == 3) {
			cmd |= 8;
			this->state = CMD_BIT_4_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_4_HIGH:
		if (span == 1) {
			this->state = CMD_BIT_4_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_4_LOW:
		if (span == 1) {
			this->state = CMD_BIT_5_HIGH;
		} else if (span == 3) {
			cmd |= 16;
			this->state = CMD_BIT_5_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_5_HIGH:
		if (span == 1) {
			this->state = CMD_BIT_5_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_5_LOW:
		if (span == 1) {
			this->state = CMD_BIT_6_HIGH;
		} else if (span == 3) {
			cmd |= 32;
			this->state = CMD_BIT_6_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_6_HIGH:
		if (span == 1) {
			this->state = CMD_BIT_6_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_6_LOW:
		if (span == 1) {
			this->state = CMD_BIT_7_HIGH;
		} else if (span == 3) {
			cmd |= 64;
			this->state = CMD_BIT_7_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_7_HIGH:
		if (span == 1) {
			this->state = CMD_BIT_7_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case CMD_BIT_7_LOW:
		if (span == 1) {
			this->state = ICMD_BIT_0_HIGH;
		} else if (span == 3) {
			cmd |= 128;
			this->state = ICMD_BIT_0_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_0_HIGH:
		if (span == 1) {
			this->state = ICMD_BIT_0_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_0_LOW:
		if (span == 1) {
			icmd = 0;
			this->state = ICMD_BIT_1_HIGH;
		} else if (span == 3) {
			icmd = 1;
			this->state = ICMD_BIT_1_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_1_HIGH:
		if (span == 1) {
			this->state = ICMD_BIT_1_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_1_LOW:
		if (span == 1) {
			this->state = ICMD_BIT_2_HIGH;
		} else if (span == 3) {
			icmd |= 2;
			this->state = ICMD_BIT_2_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_2_HIGH:
		if (span == 1) {
			this->state = ICMD_BIT_2_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_2_LOW:
		if (span == 1) {
			this->state = ICMD_BIT_3_HIGH;
		} else if (span == 3) {
			icmd |= 4;
			this->state = ICMD_BIT_3_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_3_HIGH:
		if (span == 1) {
			this->state = ICMD_BIT_3_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_3_LOW:
		if (span == 1) {
			this->state = ICMD_BIT_4_HIGH;
		} else if (span == 3) {
			icmd |= 8;
			this->state = ICMD_BIT_4_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_4_HIGH:
		if (span == 1) {
			this->state = ICMD_BIT_4_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_4_LOW:
		if (span == 1) {
			this->state = ICMD_BIT_5_HIGH;
		} else if (span == 3) {
			icmd |= 16;
			this->state = ICMD_BIT_5_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_5_HIGH:
		if (span == 1) {
			this->state = ICMD_BIT_5_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_5_LOW:
		if (span == 1) {
			this->state = ICMD_BIT_6_HIGH;
		} else if (span == 3) {
			icmd |= 32;
			this->state = ICMD_BIT_6_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_6_HIGH:
		if (span == 1) {
			this->state = ICMD_BIT_6_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_6_LOW:
		if (span == 1) {
			this->state = ICMD_BIT_7_HIGH;
		} else if (span == 3) {
			icmd |= 64;
			this->state = ICMD_BIT_7_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_7_HIGH:
		if (span == 1) {
			this->state = ICMD_BIT_7_LOW;
		} else {
			this->state = START_1;
		}
		break;
	case ICMD_BIT_7_LOW:
		if (span == 1) {
			this->state = END_HIGH;
		} else if (span == 3) {
			icmd |= 128;
			this->state = END_HIGH;
		} else {
			this->state = START_1;
		}
		break;
	case END_HIGH:
		this->state = START_1;
		if (span == 1) {
			return new Data(address, cmd);
		}
		break;
	}
	return nullptr;
}
