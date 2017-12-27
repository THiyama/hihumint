/*
 * mint.h
 *
 *  Created on: 2017/09/12
 *      Author: PCーUSER
 */

#ifndef MINT_H_
#define MINT_H_


void Usage_init();
void XTAL_init(void);
void IO_init(void);
void CMT_0_init(void);
void CMT_1_init(void);
void AD_init();
//void MTU0_init(); //左モーター
void TPU5_init(); //吸引モーター
void MTU4_init(); //右モーター
void TPU3_init(); //左モータ
void TPU4_init(); //スピーカー
void MTU1_init(); //左エンコーダ位相計数
void MTU2_init(); //右エンコーダ位相計数


int AD_con(int ad_ch);
void led(int pattern);
void choose_mode();


void start_switch();
void start_led();
void determine_led();

#endif /* MINT_H_ */
