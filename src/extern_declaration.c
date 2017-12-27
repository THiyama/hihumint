/*
 * extern_declaration.c
 *
 *  Created on: 2017/09/13
 *      Author: PCーUSER
 */

#include "stdint.h"

/*	CMT用の外部変数	*/
volatile int cmt_count;

/*	AD変換値の格納	*/
volatile int ad_data_before[7];
volatile int ad_data_after[7];
volatile int ad_data[7];

volatile int int_debug_value;
volatile float float_debug_value;

volatile int16_t EncDltL;
volatile int16_t EncDltR;

volatile uint8_t Kp,Ki,Kd;

volatile uint16_t cmtRunTime;
volatile float cmtRunVelocityR;
volatile float cmtRunVelocityL;

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
