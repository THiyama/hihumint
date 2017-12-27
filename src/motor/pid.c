

#include "motor.h"
#include "../iodefine.h"
#include "../init/mint_define.h"
#include "stdint.h"
#include "math.h"


void changePIDGain(uint8_t p, uint8_t i, uint8_t d) {
	if (p != NOCHG)
		Kp = p;
	if (i != NOCHG)
		Ki = i;
	if (d != NOCHG)
		Kd = d;
}


float getMotCtrlAmt_PID(float TrgtVelo, uint8_t rl) {
	static float DevL = 0.0, BfrDevL = 0.0, BBfrDevL = 0.0, AcmDevL = 0.0; //偏差量Deviation
	static float CtrlAmtL = 0.0, BfrCtrlAmtL = 0.0, DltCtrlAmtL = 0.0; //制御量ControlAmount　Delta
	static float DevR = 0.0, BfrDevR = 0.0, BBfrDevR = 0.0, AcmDevR = 0.0; //偏差量Deviation
	static float CtrlAmtR = 0.0, BfrCtrlAmtR = 0.0, DltCtrlAmtR = 0.0; //制御量ControlAmount　Delta

	if (rl == LEFT) {
		BBfrDevL = BfrDevL;
		BfrDevL = DevL;
		DevL = TrgtVelo - getNowVelo(LEFT);

		BfrCtrlAmtL = CtrlAmtL;
		CtrlAmtL = BfrCtrlAmtL + DltCtrlAmtL;
		DltCtrlAmtL = Kp * (DevL - BfrDevL) + Ki * DevL
				+ Kp * ((DevL - BfrDevL) - (BfrDevL - BBfrDevL));

		return CtrlAmtL;
	} else if (rl == RIGHT) {
		BBfrDevR = BfrDevR;
		BfrDevR = DevR;
		DevR = TrgtVelo - getNowVelo(RIGHT);

		BfrCtrlAmtR = CtrlAmtR;
		CtrlAmtR = BfrCtrlAmtR + DltCtrlAmtR;
		DltCtrlAmtR = Kp * (DevR - BfrDevR) + Ki * DevR
				+ Kp * ((DevR - BfrDevR) - (BfrDevR - BBfrDevR));

		return CtrlAmtR;
	} else {
		return ERROR;
	}

}
