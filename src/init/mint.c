/*
 * mint.c
 *
 *  Created on: 2017/09/12
 *      Author: PCーUSER
 */

/*
 * rx631_init.c
 *
 *  Created on: 2016/07/10
 *      Author: hihumi
 */

#include "mint.h"

#include "../function/function.h"
#include "serial.h"
#include "mint_define.h"
#include "../iodefine.h"
#include "stdint.h"

/*	init関数の呼び出し		*/
void Usage_init(void) {
	XTAL_init();	// クロック初期設定の呼び出し
	IO_init();		// ポート入出力設定の呼び出し
	CMT_0_init();		// CMT初期設定の呼び出し
	CMT_1_init();		// CMT初期設定の呼び出し
//	MTU0_init();		// MTU初期設定の呼び出し
//	MTU4_init();		// MTU初期設定の呼び出し
	MTU1_init();		// MTU初期設定の呼び出し
	MTU2_init();		// MTU初期設定の呼び出し
//	TPU5_init();		// TPU初期設定の呼び出し
	TPU3_init();		// TPU初期設定の呼び出し
	TPU4_init();		// TPU初期設定の呼び出し
//	MOTOR_init();
	init_sci1();
	AD_init();		// ADC初期設定の呼び出し

}

/*	IOピン設定	*/
void IO_init(void) {
	//入出力設定
	PORT2.PDR.BIT.B7 = 1;		//SET_LED0_OUT
	PORT1.PDR.BIT.B7 = 1;		//SET_LED1_OUT
	PORT1.PDR.BIT.B5 = 1;		//SET_LED2_OUT
	PORT5.PDR.BIT.B5 = 1;		//SET_LED3_OUT
	PORT5.PDR.BIT.B4 = 1;		//SET_LED4_OUT
	PORT3.PDR.BIT.B1 = 0;		//SET_SW0_IN

	PORT0.PDR.BIT.B5 = 1;		//SET_SENSOR_LED0_OUT
	PORTE.PDR.BIT.B4 = 1;		//SET_SENSOR_LED1_OUT
	PORTE.PDR.BIT.B5 = 1;		//SET_SENSOR_LED2_OUT
	PORTA.PDR.BIT.B0 = 1;		//SET_SENSOR_LED3_OUT
	PORTB.PDR.BIT.B0 = 1;		//SET_SENSOR_LED4_OUT

	PORTC.PDR.BIT.B5 = 1;		//SET_MOTORL1_OUT
	PORTC.PDR.BIT.B4 = 1;		//SET_MOTORL2_OUT
	PORTC.PDR.BIT.B3 = 1;		//SET_MOTORR1_OUT
	PORTC.PDR.BIT.B2 = 1;		//SET_MOTORR2_OUT

	PORTC.PDR.BIT.B6 = 1;		//SET_STBY_OUT

	//出力オンオフ設定
	PORT2.PODR.BIT.B7 = 1;		//LED0_ON
	PORT1.PODR.BIT.B7 = 1;		//LED1_ON
	PORT1.PODR.BIT.B5 = 1;		//LED2_ON
	PORT5.PODR.BIT.B5 = 1;		//LED3_ON
	PORT5.PODR.BIT.B4 = 1;		//LED4_ON

	PORT0.PODR.BIT.B5 = 1;		//SENSOR_LED0_ON
	PORTE.PODR.BIT.B4 = 1;		//SENSOR_LED1_ON
	PORTE.PODR.BIT.B5 = 1;		//SENSOR_LED2_ON
	PORTA.PODR.BIT.B0 = 1;		//SENSOR_LED3_ON
	PORTB.PODR.BIT.B0 = 1;		//SENSOR_LED4_ON

	PORTC.PODR.BIT.B5 = 0;		//MOTORL1_OFF
	PORTC.PODR.BIT.B4 = 0;		//MOTORL2_OFF
	PORTC.PODR.BIT.B3 = 0;		//MOTORR1_OFF
	PORTC.PODR.BIT.B2 = 0;		//MOTORR2_OFF
	PORTC.PODR.BIT.B6 = 0;		//STBY_OFF OFF(Low)でモータ回転なし設定
	/*
	 PORTA.PDR.BIT.B1 = 1;		//SET_Sleep1_OUT
	 PORTA.PDR.BIT.B3 = 1;		//SET_CW/CCW1_OUT
	 PORTA.PDR.BIT.B4 = 1;		//SET_CW/CCW2_OUT
	 PORTB.PDR.BIT.B5 = 1;		//SET_Clock2_OUT
	 PORTB.PDR.BIT.B3 = 1;		//SET_Clock1_OUT
	 PORTB.PDR.BIT.B5 = 1;		//SET_Reset2_OUT
	 PORTB.PDR.BIT.B6 = 1;		//SET_Reset1_OUT
	 PORTB.PDR.BIT.B7 = 1;		//SET_CW/CCW2_OUT
	 PORTC.PDR.BIT.B2 = 1;		//SET_interface_LED_OUT
	 PORTC.PDR.BIT.B3 = 1;		//SET_interface_LED_OUT
	 PORTC.PDR.BIT.B4 = 1;		//SET_interface_LED_OUT
	 PORTC.PDR.BIT.B5 = 0;		//SET_SWITCH_IN
	 PORTC.PDR.BIT.B6 = 0;		//SET_SWITCH_IN
	 PORTE.PDR.BIT.B0 = 1;		//SET_SENSOR_LED_OUT
	 PORTE.PDR.BIT.B1 = 1;		//SET_SENSOR_LED_OUT
	 PORTE.PDR.BIT.B2 = 1;		//SET_SENSOR_LED_OUT
	 PORTE.PDR.BIT.B3 = 1;		//SET_SENSOR_LED_OUT
	 PORTE.PDR.BIT.B4 = 1;		//SET_SENSOR_LED_OUT
	 PORTC.PODR.BIT.B2 = 1;		//interface_BLUELED_OFF
	 PORTC.PODR.BIT.B3 = 1;		//interface_YELLOWLED_OFF
	 PORTC.PODR.BIT.B4 = 1;		//interface_REDLED_OFF
	 PORTE.PODR.BIT.B0 = 0;		//LEFT-SENSOR_LED_OFF
	 PORTE.PODR.BIT.B1 = 0;		//ForwardLEFT-SENSOR_LED_OFF
	 PORTE.PODR.BIT.B2 = 0;		//Forward-SENSOR_LED_OFF
	 PORTE.PODR.BIT.B3 = 0;		//ForwardRIGHT-SENSOR_LED_OFF
	 PORTE.PODR.BIT.B4 = 0;		//RIGHT-SENSOR_LED_OFF

	 PORT0.PDR.BYTE = 0x00;

	 PORTA.PODR.BIT.B3 = 1;		//SET_CW/CCW1_HI
	 PORTA.PODR.BIT.B4 = 1;		//SET_CW/CCW2_HI

	 //	sensor_led_flg = 1;
	 */
}

void XTAL_init(void) {
	int xtal_wait_time;
	SYSTEM.PRCR.WORD = 0xA503;
	PORT3.PDR.BIT.B6 = 0;
	PORT3.PDR.BIT.B7 = 0;
	SYSTEM.SOSCCR.BIT.SOSTP = 1;
	SYSTEM.LOCOCR.BIT.LCSTP = 1;
	SYSTEM.ILOCOCR.BIT.ILCSTP = 1;
	SYSTEM.HOCOCR.BIT.HCSTP = 1;
	SYSTEM.HOCOPCR.BIT.HOCOPCNT = 1;
	SYSTEM.MOSCWTCR.BIT.MSTS = 0x0f;
	SYSTEM.PLLWTCR.BIT.PSTS = 0x0f;
	SYSTEM.PLLCR2.BIT.PLLEN = 1;
	SYSTEM.PLLCR.BIT.PLIDIV = 0x01;		//分周器（プリスケーラ）	：2分周      (=8MHz)
	SYSTEM.PLLCR.BIT.STC = 0x18;		//PLL回路（逓倍）		：25倍　　　(=200MHz)
	SYSTEM.PLLCR2.BIT.PLLEN = 0;
	SYSTEM.MOSCCR.BYTE = 0x00;			//
	for (xtal_wait_time = 0; xtal_wait_time <= 0x168; xtal_wait_time++)
		;
	SYSTEM.SCKCR.LONG = 0x21C31211;
	SYSTEM.SCKCR.BIT.ICK = 0x01;	//システムクロックへの分周器（プリスケーラ）	：2分周      (100MHz)
	SYSTEM.SCKCR.BIT.PCKB = 0x02;//周辺モジュールクロックへの分周器（プリスケーラ）	：4分周      (50MHz)
	SYSTEM.SCKCR.BIT.PCKA = 0x02;//周辺モジュールクロックへの分周器（プリスケーラ）	：4分周      (50MHz)
	SYSTEM.SCKCR.BIT.BCK = 0x02;//外部バスクロック選択						：4分周      (50MHz)
	SYSTEM.SCKCR.BIT.FCK = 0x02;//FlashIFクロック選択						：4分周      (50MHz)
	SYSTEM.SCKCR3.BIT.CKSEL = 0x04;		//メインクロック入力（200MHz）
	SYSTEM.PRCR.WORD = 0xA500;
}

void CMT_0_init() {
	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;	// CMTモジュールのプロテクト解除
	SYSTEM.PRCR.WORD = 0xA500;
	CMT.CMSTR0.BIT.STR0 = 0;			// CMTの停止
	CMT0.CMCR.BIT.CMIE = 0;			// 割り込み禁止
	CMT0.CMCR.BIT.CKS = 0;				// クロックセレクタ：PCLK/8
	CMT0.CMCR.BIT.CMIE = 1;			// 割り込み許可
	CMT0.CMCOR = 6250 - 1;					// CMCNTのコンペアマッチ値の設定
	IR(CMT0,CMI0)=0x00;
	IPR(CMT0,CMI0)=0x03;
	IEN(CMT0,CMI0)=0x01;
	CMT.CMSTR0.BIT.STR0 = 1;			// CMTの開始
}
void CMT_1_init() {
	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA15 = 0;	// CMTモジュールのプロテクト解除
	SYSTEM.PRCR.WORD = 0xA500;
	CMT.CMSTR0.BIT.STR1 = 0;			// CMTの停止
	CMT1.CMCR.BIT.CMIE = 0;			// 割り込み禁止
	CMT1.CMCR.BIT.CKS = 0;				// クロックセレクタ：PCLK/8
	CMT1.CMCR.BIT.CMIE = 1;			// 割り込み許可
	CMT1.CMCOR = 6250 - 1;					// CMCNTのコンペアマッチ値の設定
	IR(CMT1,CMI1)=0x00;
	IPR(CMT1,CMI1)=0x04;
//割り込み要因の優先順位（数字高い方が優先度高い）
	IEN(CMT1,CMI1)=0x01;
	CMT.CMSTR0.BIT.STR1 = 1;			// CMTの開始
}

void AD_init() {
	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA17 = 0;
	SYSTEM.PRCR.WORD = 0xA500;
//	__delay_ms(10);
	S12AD.ADCSR.BIT.ADST = 0;
	/*		↓ASEL変更↓		*/
	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.P40PFS.BIT.ASEL = 1;
	MPC.P41PFS.BIT.ASEL = 1;
	MPC.P42PFS.BIT.ASEL = 1;
	MPC.P43PFS.BIT.ASEL = 1;
	MPC.P44PFS.BIT.ASEL = 1;
	MPC.P46PFS.BIT.ASEL = 1;
//	MPC.PE3PFS.BIT.ASEL = 1;
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;
	/*		↑ASEL変更↑		*/
	PORT4.PDR.BYTE = 0x00;
	PORT4.PDR.BIT.B6 = 0;
	PORT4.PMR.BYTE = 0x00;
	PORT4.PMR.BIT.B6 = 0;
//	PORTE.PDR.BYTE |= 0x10;
//	PORTE.PMR.BYTE |= 0x10;
	S12AD.ADCSR.BYTE = 0x00;
	/*
	 S12AD.ADCSR.BIT.EXTRG=0;
	 S12AD.ADCSR.BIT.TRGE=0;
	 S12AD.ADCSR.BIT.CKS=3;
	 S12AD.ADCSR.BIT.ADCS=0;
	 */
	S12AD.ADSSTR01.BIT.SST1 = 0x1E;
	S12AD.ADEXICR.WORD = 0x00;
	S12AD.ADANS0.WORD = 0x5F;
	S12AD.ADADS0.BIT.ADS0 = 0;
	S12AD.ADADC.BIT.ADC = 0x00;
//	S12AD.ADSSTR01.BIT.SST1 = 0x14;
	S12AD.ADCER.BIT.ADRFMT = 0;
//	__delay_ms(15);
}

void MTU0_init() {
	/*		*/

	PORTB.PMR.BIT.B1 = 0;

	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.PB1PFS.BIT.PSEL = 0x01; //MTIOC0C
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
	SYSTEM.PRCR.WORD = 0xA500;

	PORTB.PDR.BIT.B1 = 1; /* PB1:出力 */
	PORTB.PMR.BIT.B1 = 1; /* PB1:周辺機能 */

	MTU.TSTR.BIT.CST0 = 0; /*	MTU0の停止	*/

	MTU0.TCR.BIT.TPSC = 0x01; /*	タイマプリスケーラ選択：PCKB/4（50MHz）	*/
	MTU0.TCR.BIT.CKEG = 0x00; /*	立ち上がりエッジでカウント	*/
	MTU0.TCR.BIT.CCLR = 0x01; /*	カウンタクリアビット：TGRAのコンペアマッチ/インプットキャプチャでTCNTクリア	*/

//	ICU.SEL.BIT.CN0 = 0;

//	MTU0.TIER.BIT.TGIEB = 0x01; /*	TGRBのコンペマッチ割り込み許可	*/

//	IR(MTU0,TGIB0)=0x00;
//	IPR(MTU0,TGIB0)=0x01;
//	IEN(MTU0,TGIB0)=0x01;

	MTU0.TMDR.BIT.BFA = 0;
	MTU0.TMDR.BIT.BFB = 0;

	MTU0.TMDR.BIT.MD = 0x02; /*	動作選択：PWM1モード	*/

	//TIORは初期状態とコンペアマッチ後の状態の設定。
	//ここではAを周期に、Bをデューティーに設定。
	MTU0.TIORH.BIT.IOA = 0x01; //0b0010; 初期出力はLow出力	コンペアマッチでHigh出力
	MTU0.TIORH.BIT.IOB = 0x02; //0b0001; 初期出力はLow出力	コンペアマッチでLow出力

	MTU0.TGRA = 8000;
	MTU0.TGRB = 20;

	MTU0.TCNT = 0x0000;

//	MTU.TSTR.BIT.CST0 = 1; /*	MTU0の開始	*/

}
void TPU3_init() {
	/*		*/
	PORTB.PMR.BIT.B1 = 0;

	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.PB1PFS.BIT.PSEL = 0x03; //TIOCB3
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA13 = 0;
	SYSTEM.PRCR.WORD = 0xA500;

	PORTB.PDR.BIT.B1 = 1; /* PB1:出力 */
	PORTB.PMR.BIT.B1 = 1; /* PB1:周辺機能 */

	TPUA.TSTR.BIT.CST3 = 0; /*	TPU3の停止	*/

	TPU3.TCR.BIT.TPSC = 0x01; /*	タイマプリスケーラ選択：PCKB/4（50MHz）	*/
	TPU3.TCR.BIT.CKEG = 0x00; /*	立ち上がりエッジでカウント	*/
	TPU3.TCR.BIT.CCLR = 0x01; /*	カウンタクリアビット：TGRAのコンペアマッチ/インプットキャプチャでTCNTクリア	*/

//	ICU.SEL.BIT.CN1 = 0;

	/*
	 MTU0.TIER.BIT.TGIEB = 0x01; //	TGRBのコンペマッチ割り込み許可

	 //	IR(MTU0,TGIB0)=0x00;
	 IPR(MTU0,TGIB0)=0x01;
	 IEN(MTU0,TGIB0)=0x01;
	 */

	TPU3.TMDR.BIT.MD = 0x03; /*	動作選択：PWM2モード	*/

	//TIORは初期状態とコンペアマッチ後の状態の設定。
	//ここではAを周期に、Bをデューティーに設定。
	TPU3.TIORH.BIT.IOA = 0x01; //0b0001; 初期出力はLow出力	コンペアマッチでLow出力
	TPU3.TIORH.BIT.IOB = 0x02; //0b0010; 初期出力はLow出力	コンペアマッチでHigh出力

	TPU3.TGRA = 40000;
	TPU3.TGRB = 20000;

//	TPUA.TSTR.BIT.CST4 = 1; /*	TPU4の開始	*/

}

void TPU4_init() {
	/*		*/
	PORTB.PMR.BIT.B5 = 0;

	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.PB5PFS.BIT.PSEL = 0x03; //TIOCB4
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA13 = 0;
	SYSTEM.PRCR.WORD = 0xA500;

	PORTB.PDR.BIT.B5 = 1; /* PB5:出力 */
	PORTB.PMR.BIT.B5 = 1; /* PB5:周辺機能 */

	TPUA.TSTR.BIT.CST4 = 0; /*	TPU4の停止	*/

	TPU4.TCR.BIT.TPSC = 0x01; /*	タイマプリスケーラ選択：PCKB/4（50MHz）	*/
	TPU4.TCR.BIT.CKEG = 0x00; /*	立ち上がりエッジでカウント	*/
	TPU4.TCR.BIT.CCLR = 0x01; /*	カウンタクリアビット：TGRAのコンペアマッチ/インプットキャプチャでTCNTクリア	*/

//	ICU.SEL.BIT.CN1 = 0;

	/*
	 MTU0.TIER.BIT.TGIEB = 0x01; //	TGRBのコンペマッチ割り込み許可

	 //	IR(MTU0,TGIB0)=0x00;
	 IPR(MTU0,TGIB0)=0x01;
	 IEN(MTU0,TGIB0)=0x01;
	 */

	TPU4.TMDR.BIT.MD = 0x03; /*	動作選択：PWM2モード	*/

	//TIORは初期状態とコンペアマッチ後の状態の設定。
	//ここではAを周期に、Bをデューティーに設定。
	TPU4.TIOR.BIT.IOA = 0x01; //0b0001; 初期出力はLow出力	コンペアマッチでLow出力
	TPU4.TIOR.BIT.IOB = 0x02; //0b0010; 初期出力はLow出力	コンペアマッチでHigh出力

	TPU4.TGRA = 40000;
	TPU4.TGRB = 20000;

//	TPUA.TSTR.BIT.CST4 = 1; /*	TPU4の開始	*/

}

void TPU5_init() {
	/*		*/
	PORTB.PMR.BIT.B6 = 0;

	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.PB6PFS.BIT.PSEL = 0x03; //TIOCA5
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA13 = 0;
	SYSTEM.PRCR.WORD = 0xA500;

	PORTB.PDR.BIT.B6 = 1; /* PB6:出力 */
	PORTB.PMR.BIT.B6 = 1; /* PB6:周辺機能 */

	TPUA.TSTR.BIT.CST5 = 0; /*	TPU5の停止	*/

	TPU5.TCR.BIT.TPSC = 0x01; /*	タイマプリスケーラ選択：PCKB/4（50MHz）	*/
	TPU5.TCR.BIT.CKEG = 0x00; /*	立ち上がりエッジでカウント	*/
	TPU5.TCR.BIT.CCLR = 0x01; /*	カウンタクリアビット：TGRAのコンペアマッチ/インプットキャプチャでTCNTクリア	*/

	TPU5.TMDR.BIT.MD = 0x02; /*	動作選択：PWM1モード	*/

//	ICU.SEL.BIT.CN2 = 0;

	TPU5.TIER.BIT.TGIEB = 0x00; /*	TGRBのコンペマッチ割り込み禁止	*/

	/*
	 IPR(MTU2,TGIB2)=0x02;
	 IEN(MTU2,TGIB2)=0x01;
	 */
	//TIORは初期状態とコンペアマッチ後の状態の設定。
	//ここではAを周期に、Bをデューティーに設定。
	TPU5.TIOR.BIT.IOA = 0x01; //0b0001; 初期出力はLow出力	コンペアマッチでLow出力
	TPU5.TIOR.BIT.IOB = 0x02; //0b0010; 初期出力はLow出力	コンペアマッチでHigh出力

	TPU5.TGRA = 40000;
	TPU5.TGRB = 20000;

//	MTU.TSTR.BIT.CST2 = 1; /*	MTU2の開始	*/
}

void MTU4_init() {
	/*		*/
	//	MTU.TRWER.BIT.RWE = 0x01;
	MTU.TOER.BIT.OE4A = 0x01;

	PORTB.PMR.BIT.B3 = 0;

	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.PB3PFS.BIT.PSEL = 0x02; //MTIOC4A
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
	SYSTEM.PRCR.WORD = 0xA500;

	PORTB.PDR.BIT.B3 = 1; /* PB3:出力 */
	PORTB.PMR.BIT.B3 = 1; /* PB3:周辺機能 */

	MTU.TSTR.BIT.CST4 = 0; /*	MTU4の停止	*/

	MTU4.TCR.BIT.TPSC = 0x01; /*	タイマプリスケーラ選択：PCKB/4（50MHz）	*/
	MTU4.TCR.BIT.CKEG = 0x01; /*	立ち下がりエッジでカウント	*/
	MTU4.TCR.BIT.CCLR = 0x01; /*	カウンタクリアビット：TGRAのコンペアマッチ/インプットキャプチャでTCNTクリア	*/

	MTU4.TMDR.BIT.MD = 0x03; /*	動作選択：PWM1モード	*/

	//TIORは初期状態とコンペアマッチ後の状態の設定。
	//ここではAを周期に、Bをデューティーに設定。
	MTU4.TIORH.BIT.IOA = 0x01; //0b0001; 初期出力はLow出力	コンペアマッチでLow出力
	MTU4.TIORH.BIT.IOB = 0x02; //0b0010; 初期出力はLow出力	コンペアマッチでHigh出力

	MTU4.TGRC = 40000;
	MTU4.TGRD = 20000;

	//	MTU.TSTR.BIT.CST4 = 1; /*	MTU4の開始	*/
}

void MTU1_init() {
//	MTU.TRWER.BIT.RWE = 0x01;
//	MTU.TOER.BIT.OE4C = 0x01;

	PORTA.PMR.BIT.B4 = 0;
	PORTA.PMR.BIT.B6 = 0;

	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.PA4PFS.BIT.PSEL = 0x02; //MTCLKA
	MPC.PA6PFS.BIT.PSEL = 0x02; //MTCLKA
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
	SYSTEM.PRCR.WORD = 0xA500;

	PORTA.PDR.BIT.B4 = 0; /* PA4:入力 */
	PORTA.PMR.BIT.B4 = 1; /* PA4:周辺機能 */
	PORTA.PDR.BIT.B6 = 0; /* PA6:入力 */
	PORTA.PMR.BIT.B6 = 1; /* PA6:周辺機能 */

	MTU.TSTR.BIT.CST1 = 0; /*	MTU1の停止	*/

	MTU1.TMDR.BIT.MD = 0x04; /*	動作選択：位相計数1	*/
	MTU1.TCNT = 0x0000;

	MTU.TSTR.BIT.CST1 = 1; /*	MTU1の開始	*/

}

void MTU2_init() {
//	MTU.TRWER.BIT.RWE = 0x01;
//	MTU.TOER.BIT.OE4C = 0x01;

	PORTA.PMR.BIT.B1 = 0;
	PORTA.PMR.BIT.B3 = 0;

	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.PA1PFS.BIT.PSEL = 0x02; //MTCLKC
	MPC.PA3PFS.BIT.PSEL = 0x02; //MTCLKD
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRA.BIT.MSTPA9 = 0;
	SYSTEM.PRCR.WORD = 0xA500;

	PORTA.PDR.BIT.B1 = 0; /* PA1:入力 */
	PORTA.PMR.BIT.B1 = 1; /* PA1:周辺機能 */
	PORTA.PDR.BIT.B3 = 0; /* PA3:入力 */
	PORTA.PMR.BIT.B3 = 1; /* PA3:周辺機能 */

	MTU.TSTR.BIT.CST2 = 0; /*	MTU2の停止	*/

	MTU2.TMDR.BIT.MD = 0x04; /*	動作選択：位相計数1	*/
	MTU2.TCNT = 0x0000;
	MTU.TSTR.BIT.CST2 = 1; /*	MTU1の開始 */

}

void RSPI_init(){
	//いつものはじまり
	PORTE.PMR.BIT.B1 = 0;
	PORTE.PMR.BIT.B2 = 0;
	PORTE.PMR.BIT.B3 = 0;

	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;
	MPC.PE1PFS.BIT.PSEL = 0x0E; //RSPCKB
	MPC.PE2PFS.BIT.PSEL = 0x0E; //MOSIB
	MPC.PE2PFS.BIT.PSEL = 0x0D; //MISOB
	MPC.PWPR.BIT.B0WI = 1;
	MPC.PWPR.BIT.PFSWE = 0;

	SYSTEM.PRCR.WORD = 0xA502;
	SYSTEM.MSTPCRB.BIT.MSTPB16 = 0; //RSPI1
	SYSTEM.PRCR.WORD = 0xA500;
	//いつもの終わり

	//以下本来の初期設定たち
	RSPI1.SPCR.BIT.SPMS = 0x01; //SPIモード:0x0,クロック同期式モード:0x1;要はSS端子を使うかどうか
	RSPI1.SPSSR.BIT.SPCP = 0; //SPCMD0を使う
	RSPI1.SPSSR.BIT.SPECM = 0; //SPCMD0を使う
	RSPI1.SPBR = 0x18; //0d24
	RSPI1.SPCMD0.BIT.BRDV = 0x3; //0d3 以上2つによって通信速度が125kbpsになる。
	RSPI1.SPCMD0.BIT.CPHA = 0x0; //SPI MODE0
	RSPI1.SPCMD0.BIT.CPOL = 0x0; //SPI MODE0
//	RSPI1.SPCMD0.BIT.SSLA = ?; //勉強中
//	RSPI1.SPCMD0.BIT.SSLKP = ?; //勉強中　多分SS端子を使わない設定にしているから設定しなくても大丈夫
	RSPI1.SPCMD0.BIT.SPB = 0x4; //データ長16bit
	RSPI1.SPDCR.BIT.SPFC=0x3; //フレーム数（フレーム数とは、上で設定したデータ長を一回の送受信で何個送るか。SDなら6バイト送るので、16bit*3フレームで48bit=6byte）
	RSPI1.SPCMD0.BIT.LSBF = 0x0; //MSBファースト


	RSPI1.SPCR.BIT.MSTR = 1; //マスターモード
}

