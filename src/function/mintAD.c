/*
 * mintAD.c
 *
 *  Created on: 2017/10/02
 *      Author: PCーUSER
 */

#include "function.h"
#include "../iodefine.h"
#include "../init/mint_define.h"
#include "../motor/motor.h"
#include "stdint.h"

unsigned short StartAD(unsigned char ch){
	S12AD.ADCSR.BIT.ADST = 0;

	S12AD.ADANS0.WORD = ch;

	S12AD.ADCSR.BIT.ADST = 1;
	while (S12AD.ADCSR.BIT.ADST == 1)
		;
	S12AD.ADCSR.BIT.ADST = 0;
}

void getIRSensorValue(unsigned char ch){
	unsigned char time1 = 1400;
	unsigned char time2 = 800;
	unsigned char i;

	if(ch & 0x01){ //左向きセンサの取得
		StartAD(0x01);
		ad_data_before[0]=S12AD.ADDR0;
		SENSOR_LED0 = ON;
		for (i = 0; i < time2; i++)
			;
		StartAD(0x01);

		SENSOR_LED0 = OFF;
		ad_data[0]=S12AD.ADDR0-ad_data_before[0];
	}
	if(ch & 0x02){ //左前向きセンサの取得
		StartAD(0x02);
		ad_data_before[1]=S12AD.ADDR1;
		SENSOR_LED1 = ON;
		for (i = 0; i < time2; i++)
			;
		StartAD(0x02);

		SENSOR_LED1 = OFF;
		ad_data[1]=S12AD.ADDR1-ad_data_before[1];
	}
	if(ch & 0x04){ //前向きセンサの取得
		StartAD(0x04);
		ad_data_before[2]=S12AD.ADDR2;
		SENSOR_LED2 = ON;
		for (i = 0; i < time2; i++)
			;
		StartAD(0x04);

		SENSOR_LED2 = OFF;
		ad_data[2]=S12AD.ADDR2-ad_data_before[2];
	}
	if(ch & 0x08){ //右前向きセンサの取得
		StartAD(0x08);
		ad_data_before[3]=S12AD.ADDR3;
		SENSOR_LED3 = ON;
		for (i = 0; i < time2; i++)
			;
		StartAD(0x08);

		SENSOR_LED3 = OFF;
		ad_data[3]=S12AD.ADDR3-ad_data_before[3];
	}
	if(ch & 0x10){ //右向きセンサの取得
		StartAD(0x10);
		ad_data_before[4]=S12AD.ADDR4;
		SENSOR_LED4 = ON;
		for (i = 0; i < time2; i++)
			;
		StartAD(0x10);

		SENSOR_LED4 = OFF;
		ad_data[4]=S12AD.ADDR4-ad_data_before[4];
	}
}

float getLipoVolt() {
	float lipo_volt;

	float R1 = 19.9;
	float R2 = 10.1;

	float ref_voltage = 3.3;
	int ad_data_accuracy = 4096;

	StartAD(0x40);
	ad_data[6] = S12AD.ADDR6;

	lipo_volt = (float) (ad_data[6] * ((R1 + R2) / R2)
			* (ref_voltage / ad_data_accuracy));

	return lipo_volt;
}
