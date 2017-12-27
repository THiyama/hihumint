/*
 * mintPWM.c
 *
 *  Created on: 2017/10/02
 *      Author: PCーUSER
 */

#include "../init/mint_define.h"
#include "function.h"
#include "../iodefine.h"
#include "../motor/motor.h"
#include "stdint.h"

unsigned int tpsc = 50;

/*PWM機能群*/
//StartPWM : PWMの開始。引数は周期とduty
void StartLeftMotor(float frequency,float duty){
	TPU3.TIORH.BIT.IOA = 0x01; //0b0001; 初期出力はLow出力	コンペアマッチでLow出力
	TPU3.TIORH.BIT.IOB = 0x02; //0b0010; 初期出力はLow出力	コンペアマッチでHigh出力

	int_debug_value = (unsigned int)((tpsc*1000000.0/frequency)*duty/100.0+0.5);

	TPU3.TGRA = (unsigned int)((tpsc*1000000.0/frequency) + 0.5);
	TPU3.TGRB = (unsigned int)((tpsc*1000000.0/frequency)*duty/100.0+0.5);

	TPUA.TSTR.BIT.CST3 = 1; /*	TPU3の開始	*/
}
void StartRightMotor(float frequency,float duty){

	MTU4.TGRC = (unsigned int)((tpsc*1000000.0/frequency) + 0.5);
	MTU4.TGRD = (unsigned int)((tpsc*1000000.0/frequency)*duty/100.0+0.5);

	MTU.TSTR.BIT.CST4 = 1; /*	MTU4の開始	*/
}
void StartSpeaker(float frequency,float duty){
	//TIORは初期状態とコンペアマッチ後の状態の設定。
	//ここではAを周期に、Bをデューティーに設定。
	TPU4.TIOR.BIT.IOA = 0x01; //0b0001; 初期出力はLow出力	コンペアマッチでLow出力
	TPU4.TIOR.BIT.IOB = 0x02; //0b0010; 初期出力はLow出力	コンペアマッチでHigh出力

	TPU4.TGRA = (unsigned int)(tpsc*1000000.0/frequency+0.5);
	TPU4.TGRB = (unsigned int)((tpsc*1000000.0/frequency)*duty/100.0+0.5);

	TPUA.TSTR.BIT.CST4 = 1; /*	TPU4の開始	*/
}
void StartSucMotor(float frequency,float duty){

	TPU5.TGRA = (unsigned int)(tpsc*1000000.0/frequency+0.5);
	TPU5.TGRB = (unsigned int)((tpsc*1000000.0/frequency)*duty/100.0+0.5);

	TPUA.TSTR.BIT.CST5 = 1; /*	TPU4の開始	*/
}

//StopPWM
void StopLeftMotor(){
	//TIOR出力禁止
	TPU3.TIORH.BIT.IOA = 0x00;
	TPU3.TIORH.BIT.IOB = 0x00;

	TPUA.TSTR.BIT.CST3 = 0; /*	TPU3の停止	*/
}
void StopRightMotor(){
	//TIOR出力禁止
	MTU4.TIORH.BIT.IOA = 0x00;
	MTU4.TIORH.BIT.IOB = 0x00;

	MTU.TSTR.BIT.CST4 = 0; /*	MTU4の停止	*/
}
void StopSpeaker(){
	//TIOR出力禁止
	TPU4.TIOR.BIT.IOA = 0x00;
	TPU4.TIOR.BIT.IOB = 0x00;

	TPUA.TSTR.BIT.CST4 = 0; /*	TPU4の停止	*/
}
void StopSucMotor(){
	//TIOR出力禁止
	TPU5.TIOR.BIT.IOA = 0x00;
	TPU5.TIOR.BIT.IOB = 0x00;

	TPUA.TSTR.BIT.CST5 = 0; /*	TPU5の停止	*/
}


