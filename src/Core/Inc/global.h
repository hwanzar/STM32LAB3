/*
 * global.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Lenovo
 */
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "software_timer.h"
#include "button.h"
#include "fsm.h"
#include "led7SEG.h"

#define INIT 0

#define RED1_GREEN2       1
#define RED1_YELLOW2      2
#define GREEN1_RED2       3
#define YELLOW1_RED2      4

#define MOD_RED 9
#define MOD_YELLOW 10
#define MOD_GREEN 11
extern int mode;

extern int timeRed;
extern int timeGreen;
extern int timeYellow;
extern int time_red, time_yellow, time_green;


extern int status;

extern int i;

extern int blink;

extern int number[4];
extern int timerTraffic1, timerTraffic2;

//void updateBuffer();

#endif /* INC_GLOBAL_H_ */

