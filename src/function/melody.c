/*
 * melody.c
 *
 *  Created on: 2017/10/02
 *      Author: PCーUSER
 */

#include "function.h"
#include "stdint.h"
#include "../init/mint_define.h"
#include "../motor/motor.h"
#include "../iodefine.h"

void ErrorMelody() {
	StartSpeaker((DO1 + RE1) / 2, 50.0);
	__delay_ms(50);
	StopSpeaker();
	__delay_ms(50);
	StartSpeaker((DO1 + RE1) / 2, 50.0);
	__delay_ms(500);
	StopSpeaker();
}

void OkMelody() {
	StartSpeaker(FA1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
	__delay_ms(50);
	StartSpeaker(FA1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
}

void OnMelody() {
	StartSpeaker(MI1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
	__delay_ms(50);
	StartSpeaker(RA1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
	__delay_ms(50);

	StartSpeaker(SI1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
	__delay_ms(50);
	StartSpeaker(RA1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
	__delay_ms(100);


	StartSpeaker(MI1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
	__delay_ms(50);


	StartSpeaker(MI1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
	__delay_ms(50);
	StartSpeaker(SI1 * 3, 50.0);
	__delay_ms(50);
	StopSpeaker();
}
void PlayStartMelody() {
	StartSpeaker(3520.0, 50.0);
	__delay_ms(300);
	StopSpeaker();
	__delay_ms(300);
	StartSpeaker(3520.0, 50.0);
	__delay_ms(300);
	StopSpeaker();
	__delay_ms(300);
	StartSpeaker(3520.0, 50.0);
	__delay_ms(300);
	StopSpeaker();
	__delay_ms(300);
	StartSpeaker(7040.0, 50.0);
	__delay_ms(500);
	StopSpeaker();
}

void intro_silent_majority() {
}

void SoundEnc(){
	while(SW0 == LOW){
		if(ENCL < 8192){
			StartSpeaker(DO1,50.0);
		}
		else if(ENCL < 8192*2){
			StartSpeaker(RE1,50.0);
		}
		else if(ENCL < 8192*3){
			StartSpeaker(MI1,50.0);
		}
		else if(ENCL < 8192*4){
			StartSpeaker(FA1,50.0);
		}
		else if(ENCL < 8192*5){
			StartSpeaker(SO1,50.0);
		}
		else if(ENCL < 8192*6){
			StartSpeaker(RA1,50.0);
		}
		else if(ENCL < 8192*7){
			StartSpeaker(SI1,50.0);
		}
		else if(ENCL < 8192*8-1){
			StartSpeaker(DO1,50.0);
		}
		__delay_ms(100);
		StopSpeaker();
	}
}
