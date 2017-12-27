/*
 * function.c
 *
 *  Created on: 2017/10/26
 *      Author: PCーUSER
 */

#include "function.h"
#include "stdint.h"
#include "../init/mint_define.h"
#include "../motor/motor.h"
#include "../iodefine.h"

void MainProcess() { //MainProcess
	uint8_t mode = 0;
	mode = SetMode();
	while (1) {
		ExecuteMode(mode);
		mode = SetMode();
	}
} //MainProcess

void StartUpProcess() {
	Usage_init();
	if (getLipoVolt() <= AVAILABLE_VOLTAGE) {
		ErrorMelody();
		OperateLED(0, 0, 0, 0, 0);
		while (1)
			;
	}
	OperateLED(1, 1, 1, 1, 1);
	OnMelody();
}

uint8_t ExecuteMode(uint8_t mode) {
	OptDistRunPara_t Para;
	if (mode == 0) {

	} else if (mode == 1) {
		OperateLED(0, 0, 0, 1, 0);
		PlayStartMelody();
		Para.Acce = 2.0;
		Para.InitVelo = 0.2;
		Para.MaxVelo = 5.0;
		Para.TrgtDist = 1.8;
		Para.jerk[0] = 0.0;
		TrapStraight(Para);
		return 0;
	} else if (mode == 2) {
		OperateLED(0, 0, 1, 0, 0);
		__delay_ms(500);
		PlayStartMelody();
		while (1) {
			changePIDGain(140,10,0.2);
			RotMot_PID(1.0, 1, LEFT);
		}
		return 0;
	}
	return 0;
}

uint8_t SetMode() {
	static uint8_t count = 0;
	uint8_t chgflg = 0;
	float NowVelo;

	STBY = 0;
	while (isCompletedSetMode()) {
		NowVelo = getNowVelo(LEFT);
		if (NowVelo > 0.35) {
			count++;
			chgflg = 1;
		} else if (NowVelo < -0.35) {
			if (count == 0) {
				count = 7;
			} else {
				count--;
			}
			chgflg = 1;
		}
		if (chgflg == 1) {
			switch (count) {
			case 0:
				StartSpeaker(DO2, 50.0);
				OperateLED(1, 0, 0, 0, 1);
				count = 0;
				break;
			case 1:
				StartSpeaker(DO1, 50.0);
				OperateLED(1, 0, 0, 1, 1);
				break;
			case 2:
				StartSpeaker(RE1, 50.0);
				OperateLED(1, 0, 1, 0, 1);
				break;
			case 3:
				StartSpeaker(MI1, 50.0);
				OperateLED(1, 0, 1, 1, 1);
				break;
			case 4:
				StartSpeaker(FA1, 50.0);
				OperateLED(1, 1, 0, 0, 1);
				break;
			case 5:
				StartSpeaker(SO1, 50.0);
				OperateLED(1, 1, 0, 1, 1);
				break;
			case 6:
				StartSpeaker(RA1, 50.0);
				OperateLED(1, 1, 1, 0, 1);
				break;
			case 7:
				StartSpeaker(SI1, 50.0);
				OperateLED(1, 1, 1, 1, 1);
				break;
			case 8:
				StartSpeaker(DO2, 50.0);
				OperateLED(1, 0, 0, 0, 1);
				count = 0;
				break;
			default:
				count = 0;
			}
		}
		__delay_ms(100);
		StopSpeaker();
		__delay_ms(200);
		chgflg = 0;
	}
	STBY = 1;
	return count;
}

void OperateLED(uint8_t l0, uint8_t l1, uint8_t l2, uint8_t l3, uint8_t l4) {
	LED0 = l0;
	LED1 = l1;
	LED2 = l2;
	LED3 = l3;
	LED4 = l4;
}

uint8_t isCompletedSetMode() {
	if (SW0 == 0) { //押されていないなら無限ループとなるように
		return 1;
	} else {
		return 0;
	}
}
