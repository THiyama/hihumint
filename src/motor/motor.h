/*
 * motor.h
 *
 *  Created on: 2017/10/26
 *      Author: PCーUSER
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "stdint.h"

/*Motor機能群*/
char MOTOR_init(char RotDir);
float getMotCtrlAmt_PID(float TrgtVelo, uint8_t rl);
void RotMot_PID(float TrgtVelo, uint8_t dir, uint8_t rl);
float trap_acce_straight(float distance, float MaxVelo, float BgnVelo,
		float EndVelo, float BgnAcce, float EndAcce);

//位相計数
void SoundEnc();
float getNowVelo(uint8_t rl);
int16_t getEncDlt(uint8_t rl);

//PIDゲイン
void changePIDGain(uint8_t p, uint8_t i, uint8_t d);
volatile extern uint8_t Kp, Ki, Kd;

volatile extern int16_t EncDltL;
volatile extern int16_t EncDltR;

volatile extern float cmtRunVelocityL;
volatile extern float cmtRunVelocityR;

//runソース系

typedef struct{ //任意距離走行用構造体
	float TrgtDist; //TargetDistance
	float MaxVelo;
	float InitVelo;
	float FinVelo;
	float FinAcce;
	float Acce;
	float Dece;
	float jerk[4];
	uint8_t jerkNo;
} OptDistRunPara_t;



float RunStraight(OptDistRun_t);
float SCurveAcce(OptDistRun_t); //返り値は走行距離
float TrapStraight(OptDistRun_t);
float ConstStraight(OptDistRunPara_t);

float CalcSpentVeloSCurveAcce(OptDistRunPara_t);
float CalcSpentTimeSCurveAcce(OptDistRunPara_t);

volatile extern uint16_t cmtRunTime;

#endif /* MOTOR_H_ */
