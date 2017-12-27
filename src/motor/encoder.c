/*
 * encoder.c
 *
 *  Created on: 2017/10/26
 *      Author: PCーUSER
 */
#include "motor.h"
#include "../iodefine.h"
#include "../init/mint_define.h"
#include "stdint.h"
#include "math.h"


//エンコーダの差分値取得
//この関数が呼ばれるのはCMTの中
int16_t getEncDlt(uint8_t rl) {
	volatile static int16_t Dlt;

	if (rl == LEFT) {
		Dlt = ENCL - 32768;
	} else if (rl == RIGHT) {
		Dlt = ENCR - 32768;
	} else {
		return ERROR;
	}

	ENCL = 32768;
	ENCR = 32768;

	return Dlt;
}

float getNowVelo(uint8_t rl) {
	float GearRatio = PINION_TEETH / SPUR_TEETH;
	float NowVelo;
	if (rl == LEFT) {
		NowVelo = PI * TIRE_WIDTH * GearRatio * EncDltL * 1000 / ((ENC_PULSE-1)*4);
	} else if (rl == RIGHT) {
		NowVelo = PI * TIRE_WIDTH * GearRatio * EncDltR * 1000 / ((ENC_PULSE-1)*4);
	} else {
		return ERROR;
	}
	return NowVelo;
}
