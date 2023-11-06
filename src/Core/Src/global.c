/*
 * global.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Lenovo
 */

#include "global.h"
int status = INIT;

int timeRed = 500;
int timeYellow = 200;
int timeGreen = 300;

int time_red = 5;
int time_yellow = 3;
int time_green = 2;

int number[4] = {0,0,0,0};

int blink = 0;

int timerTraffic1 = 0;
int timerTraffic2 = 0;

//void updateBuffer(){
//	number[0] = timerTraffic1 / 10;
//	number[1] = timerTraffic1 % 10;
//	number[2] = timerTraffic2 / 10;
//	number[3] = timerTraffic2 % 10;
//}

//int mode = MOD_RED;
