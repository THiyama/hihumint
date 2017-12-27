/*
 * motor.c
 *
 *  Created on: 2017/10/03
 *      Author: PCーUSER
 */

#include "motor.h"
#include "../iodefine.h"
#include "../init/mint_define.h"
#include "stdint.h"
#include "math.h"

char MD_init(char RotDir) {
	static dir = 0;
	if (RotDir != 0) { //RotDirが0なら、現在の回転方向のみを返す
		if (dir == 0) {
			STBY = 1; //最初だけSTBYをHIGHに。
		}
		if (RotDir == FW) {
			//左モータCCW設定
			MOTOR_L1 = 0;
			MOTOR_L2 = 1;
			//右モータCW設定
			MOTOR_R1 = 1;
			MOTOR_R2 = 0;
		} else if (RotDir == BW) {
			//左モータCW設定
			MOTOR_L1 = 1;
			MOTOR_L2 = 0;
			//右モータCCW設定
			MOTOR_R1 = 0;
			MOTOR_R2 = 1;
		} else {
			dir = ERROR;
		}
		dir = RotDir;
	}
	return dir;
}

//PIDにより任意のモーターを任意の目標速度で回す。主にrun.c内の関数で用いられる。
void RotMot_PID(float TrgtVelo, uint8_t dir, uint8_t rl) {
	float CtrlAmt = 0.0;
	if (TrgtVelo != 0.0) {
		if (rl == LEFT) {
			CtrlAmt = getMotCtrlAmt_PID(TrgtVelo, LEFT);
			StartLeftMotor(1000.0, CtrlAmt);
		} else if (rl == RIGHT) {
			CtrlAmt = getMotCtrlAmt_PID(TrgtVelo, RIGHT);
			StartRightMotor(1000.0, CtrlAmt);
		}
	}
}
