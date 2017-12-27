/*
 * function.h
 *
 *  Created on: 2017/10/02
 *      Author: PCーUSER
 */


#include "stdint.h"

/*PWM機能群*/
//StartPWM : PWMの開始。引数は周期とduty
void StartLeftMotor(float frequency,float duty);
void StartRightMotor(float frequency,float duty);
void StartSpeaker(float frequency,float duty);
void StartSucMotor(float frequency,float duty);

//StopPWM
void StopLeftMotor();
void StopRightMotor();
void StopSpeaker();
void StopSucMotor();

//Melody関数
void PlayStartMelody();
void intro_silent_majority();
void ErrorMelody();
void OkMelody();
void OnMelody();


/*AD機能*/
unsigned short StartAD(unsigned char ch);
void getIRSensorValue(unsigned char ch);

float getLipoVolt(); //リポ電圧

//	AD変換値の格納
volatile extern int ad_data_before[7];
volatile extern int ad_data_after[7];
volatile extern int ad_data[7];

/*CMT機能群*/
extern volatile int cmt_count;
extern volatile uint16_t cmtRunTime;

volatile extern float cmtRunVelocityL;
volatile extern float cmtRunVelocityR;

void __delay_ms(int time_ms);
void __delay_us(int time_us);

//エンコーダの値をfunction内でも使えるように
volatile extern uint16_t EncDltL;
volatile extern uint16_t EncDltR;


extern volatile int int_debug_value;
extern volatile float float_debug_value;

/* 小機能群 */
uint8_t SetMode();
uint8_t ExecuteMode(uint8_t mode); //返り値は実行が正常に終了したかしていないか(1かERRORコード123か)
uint8_t isCompletedSetMode();
void OperateLED(uint8_t,uint8_t,uint8_t,uint8_t,uint8_t);

