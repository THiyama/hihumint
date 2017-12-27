/*
 * mintCMT.c
 *
 *  Created on: 2017/10/02
 *      Author: PCーUSER
 */

#include "function.h"
#include "../init/mint_define.h"
#include "../motor/motor.h"
#include "../iodefine.h"
#include "stdint.h"

void cmt_0_interrupt() {

	cmt_count++;
	cmtRunTime++;

	getIRSensorValue(0x09);
	getIRSensorValue(0x12);
	getIRSensorValue(0x04);

	EncDltL = getEncDlt(LEFT);
	EncDltR = getEncDlt(RIGHT);

//	RotMot_PID(cmtRunVelocityL,1,LEFT);
//	RotMot_PID(cmtRunVelocityR,1,RIGHT);
}
void cmt_1_interrupt() {

}

void __delay_ms(int time_ms) {
	cmt_count = 0;
	while (cmt_count != time_ms)
		;
}
