/*
 * mint_define.h
 *
 *  Created on: 2017/09/12
 *      Author: PCーUSER
 */

#ifndef MINT_DEFINE_H_
#define MINT_DEFINE_H_

#define ERROR 123

#define LED0 PORT2.PODR.BIT.B7
#define LED1 PORT1.PODR.BIT.B7
#define LED2 PORT1.PODR.BIT.B5
#define LED3 PORT5.PODR.BIT.B5
#define LED4 PORT5.PODR.BIT.B4
#define SW0 PORT3.PIDR.BIT.B1 //switchは、1で押された。0で押されていない

#define	SENSOR_LED0 PORT0.PODR.BIT.B5
#define	SENSOR_LED1 PORTE.PODR.BIT.B4
#define	SENSOR_LED2 PORTE.PODR.BIT.B5
#define	SENSOR_LED3 PORTA.PODR.BIT.B0
#define	SENSOR_LED4 PORTB.PODR.BIT.B0

#define MOTOR_L1 PORTC.PODR.BIT.B5
#define MOTOR_L2 PORTC.PODR.BIT.B4
#define MOTOR_R1 PORTC.PODR.BIT.B3
#define MOTOR_R2 PORTC.PODR.BIT.B2
#define STBY PORTC.PODR.BIT.B6

#define ENCL MTU2.TCNT
#define ENCR MTU1.TCNT

#define LEFT 0
#define RIGHT 1

#define DO1 1046.502
#define RE1 1174.569
#define MI1 1318.510
#define FA1 1396.913
#define SO1 1567.982
#define RA1 1760.000
#define SI1 1975.533
#define DO2 2093.533

/*機体定数*/
//歯数
#define SPUR_TEETH 40.0
#define PINION_TEETH 8.0

#define ENC_PULSE 4096

//タイヤ幅
#define TIRE_WIDTH 0.023

#define AVAILABLE_VOLTAGE 7.8

#define ON 1
#define OFF 0
#define HIGH 1
#define LOW 0

#define FW 1
#define BW 2

#define NOCHG 255

#define PI 3.14159265
#endif
