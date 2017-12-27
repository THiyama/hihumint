/*
 * main.c
 *
 *  Created on: 2017/09/12
 *      Author: PCーUSER
 */

#include "function/function.h"
#include "init/mint.h"
#include "init/serial.h"
#include "iodefine.h"
#include "init/mint_define.h"
#include "stdint.h"

int main(void) { //main
	StartUpProcess();
 	MainProcess();
} //main
