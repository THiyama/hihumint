/*
 * run.c
 *
 *  Created on: 2017/10/26
 *      Author: PCーUSER
 */

#include "motor.h"
#include "../iodefine.h"
#include "../init/mint_define.h"
#include "stdint.h"
#include "math.h"

float RunStraight(OptDistRunPara_t Para) {
	float Dist = 0.0;

	changePIDGain(140, 10, 0.2);

	Para.InitVelo = SCurveAcce(Para); //S字加速
	Dist += 1 / 6 * Para.jerk[0] * pow(cmtRunTime * 0.001, 3)
			+ Para.InitVelo * cmtRunTime * 0.001; //S字加速によって進んだ距離

	Para.InitVelo = TrapStraight(Para);
	Dist += 1 / 2 * Para.Acce * pow(cmtRunTime * 0.001, 2)
			+ Para.InitVelo * cmtRunTime * 0.001;

	Para.InitVelo = SCurveAcce(Para); //S字加速
	Dist += 1 / 6 * Para.jerk[1] * pow(cmtRunTime * 0.001, 3)
			+ Para.InitVelo * cmtRunTime * 0.001; //S字加速によって進んだ距離

	return Para.FinVelo;
}

float SCurveAcce(OptDistRunPara_t Para) {
	float Velo = 0.0, BfrVelo = 0.0;
	float Acce = 0.0;
	float Dece = 0.0;

	cmtRunTime = 0;

	cmtRunVelocityL = 0.0;
	cmtRunVelocityR = 0.0;

	if ((Para.jerkNo >> 1) == 0) {
		while (Acce <= Para.Acce) {
			BfrVelo = Velo;
			if (Para.jerkNo == 0) {
				Velo = 0.5 * Para.jerk[Para.jerkNo]
						* pow((cmtRunTime * 0.001), 2) + Para.InitVelo;
			} else {
				Velo = 0.5 * Para.jerk[Para.jerkNo]
						* pow((cmtRunTime * 0.001), 2)
						+ Para.Acce * cmtRunTime * 0.001 + Para.InitVelo;
			}
			Acce = (Velo - BfrVelo) / 0.001;
			cmtRunVelocityL = Velo;
			cmtRunVelocityR = cmtRunVelocityL;
		}
	} else if ((Para.jerkNo >> 1) == 1) {
		while (Dece >= Para.Dece) {
			BfrVelo = Velo;
			if ((Para.jerkNo & 2) == 0) { //jerkNoが2のとき
				Velo = 0.5 * Para.jerk[Para.jerkNo]
						* pow((cmtRunTime * 0.001), 2) + Para.InitVelo;
			} else {
				Velo = 0.5 * Para.jerk[Para.jerkNo]
						* pow((cmtRunTime * 0.001), 2)
						+ Para.Dece * cmtRunTime * 0.001 + Para.InitVelo;
			}
			Dece = (Velo - BfrVelo) / 0.001;
			cmtRunVelocityL = Velo;
			cmtRunVelocityR = cmtRunVelocityL;
		}
	}
	return Velo;
}

float TrapStraight(OptDistRunPara_t Para) {
	float Velo = 0.0;

	cmtRunTime = 0;
	cmtRunVelocityL = 0.0;
	cmtRunVelocityR = 0.0;

	while (Velo <= (Para.MaxVelo - CalcSpentVeloSCurveAcce(Para))) {
		Velo = Para.Acce * cmtRunTime * 0.001 + Para.InitVelo;
		cmtRunVelocityL = Velo;
		cmtRunVelocityR = cmtRunVelocityL;
	}

	return Velo;
}
/*
float ConstStraight(OptDistRunPara_t) {

}
*/
float CalcSpentVeloSCurveAcce(OptDistRunPara_t Para) {
	return (1 / 2 * Para.jerk[Para.jerkNo]
			* pow(CalcSpentTimeSCurveAcce(Para), 2));
}

float CalcSpentTimeSCurveAcce(OptDistRunPara_t Para) {
	if (Para.jerkNo == 0) {
		return Para.Acce / Para.jerk[Para.jerkNo];
	} else if (Para.jerkNo == 1) {
		return -Para.Acce / Para.jerk[Para.jerkNo];
	} else if (Para.jerkNo == 2) {
		return Para.Dece / Para.jerk[Para.jerkNo];
	} else if (Para.jerkNo == 3) {
		return -Para.Dece / Para.jerk[Para.jerkNo];
	} else {
		return ERROR;
	}
}
