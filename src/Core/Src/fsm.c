/*
 * fsm.c
 *
 *  Created on: Oct 30, 2023
 *      Author: Lenovo
 */


#include "fsm.h"
#include "led_control.h"


void fsm_auto_run(){
	switch(status){
	case INIT:
		resetLight();
		timerTraffic1 = timeRed / 100;
		timerTraffic2 = timeGreen / 100;
		status = RED1_GREEN2;
		setTimer(0, timeGreen);
		setTimer(1, 100);
		break;
	case RED1_GREEN2:
		onRed1();
		onGreen2();
		if(timer_flag[0] == 1){
			status = RED1_YELLOW2;
			setTimer(0, timeYellow);
		}
		if(timer_flag[1] == 1){
			setTimer(1, 100);
			timerTraffic1--;
			timerTraffic2--;
			if(timerTraffic2 <= 0) timerTraffic2 = timeYellow / 100;
		}
		if (isButtonPressed(0) == 1) {
			resetLight();

			status = MOD_RED;
			time_red = timeRed / 100;
			time_yellow = timeYellow / 100;
			time_green  = timeGreen / 100;

			setTimer(4, 1);
			timerTraffic1 = time_red;
			timerTraffic2 = 2;
		}
		break;
	case RED1_YELLOW2:
		onRed1();
		onYellow2();
		if(timer_flag[0] == 1){
			status = GREEN1_RED2;
			setTimer(0, timeGreen);
		}
		if(timer_flag[1] == 1){
			setTimer(1, 100);
			timerTraffic1--;
			if(timerTraffic1 <= 0) timerTraffic1 = timeGreen / 100;
			timerTraffic2--;
			if(timerTraffic2 <= 0) timerTraffic2 = timeRed / 100;
		}
		if (isButtonPressed(0) == 1) {
			resetLight();

			status = MOD_RED;
			time_red = timeRed / 100;
			time_yellow = timeYellow / 100;
			time_green  = timeGreen / 100;

			setTimer(4, 1);
			timerTraffic1 = time_red;
			timerTraffic2 = 2;
		}
		break;
	case GREEN1_RED2:
		onGreen1();
		onRed2();
		if(timer_flag[0] == 1){
			status = YELLOW1_RED2;
			setTimer(0, timeYellow);
		}
		if(timer_flag[1] == 1){
			setTimer(1, 100);
			timerTraffic1--;
			if(timerTraffic1 <= 0) {
				timerTraffic1 = timeYellow / 100;
			}
			timerTraffic2--;
		}
		if (isButtonPressed(0) == 1) {
			resetLight();

			status = MOD_RED;
			time_red = timeRed / 100;
			time_yellow = timeYellow / 100;
			time_green  = timeGreen / 100;

			setTimer(4, 1);
			timerTraffic1 = time_red;
			timerTraffic2 = 2;
		}
		break;
	case YELLOW1_RED2:
		onYellow1();
		onRed2();
		if(timer_flag[0] == 1){
			status = RED1_GREEN2;
			setTimer(0, timeGreen);
		}
		if(timer_flag[1] == 1){
			setTimer(1, 100);
			timerTraffic1--;
			if(timerTraffic1 <= 0) timerTraffic1 = timeRed / 100;
			timerTraffic2--;
			if(timerTraffic2 <= 0) timerTraffic2 = timeYellow / 100;
		}
		if (isButtonPressed(0) == 1) {
			resetLight();

			status = MOD_RED;
			time_red = timeRed / 100;
			time_yellow = timeYellow / 100;
			time_green  = timeGreen / 100;

			setTimer(4, 2);
			timerTraffic1 = time_red;
			timerTraffic2 = 2;
		}
		break;
	default:
		break;
	}

}

void fsm_mod_run() {
	switch(status){
		case MOD_RED:
			if(timer_flag[4] == 1){
				setTimer(4, 25);
				if(blink == 0){
					onRed1();
					onRed2();
					blink = 1;
				}
				else{
					resetLight();
					blink = 0;
				}

			}
			if(isButtonPressed(0) == 1){
				setTimer(4, 2);
				status = MOD_YELLOW;
				timerTraffic1 = timeYellow / 100;
				timerTraffic2 = 3;
			}
			if(isButtonPressed(1) == 1){
				time_red++;
				if(time_red >= 100) time_red = 5;
				timerTraffic1 = time_red;
			}
			if(isButtonPressed(2) == 1){
				timeRed = time_red*100;
			}
			break;
		case MOD_YELLOW:
			if(timer_flag[4] == 1){
				setTimer(4, 25);
				if(blink == 0){
					blink = 1;
					onYellow1();
					onYellow2();
				}
				else{
					blink = 0;
					resetLight();
				}
			}
			if(isButtonPressed(0)){
				setTimer(4, 2);
				status = MOD_GREEN;
				timerTraffic1 = time_green;
				timerTraffic2 = 4;
			}
			if(isButtonPressed(1)){
				time_yellow++;
				if(time_yellow >= 100) time_yellow = 2;
				timerTraffic1 = time_yellow;
			}
			if(isButtonPressed(2)){
				timeYellow = time_yellow*100;
			}
			break;
		case MOD_GREEN:
			if(timer_flag[4] == 1){
				setTimer(4, 25);
				if(blink == 0){
					blink = 1;
					onGreen1();
					onGreen2();
				}
				else{
					blink = 0;
					resetLight();
				}
			}
			if(isButtonPressed(0)){
				status = RED1_GREEN2;
				timeYellow = timeRed - timeGreen;

				// set everything to INIT
				timerTraffic1 = timeRed / 100;
				timerTraffic2 = timeGreen / 100;
				updateBuffer(timerTraffic1, timerTraffic2);
				setTimer(0, timeGreen);
				setTimer(1, 100);
				setTimer(2, 100);
				i = 0;

			}
			if(isButtonPressed(1)){
				time_green++;
				if(time_green >= 100){
					time_green = 3;
					timerTraffic1 = 3;
				}
				else timerTraffic1++;
			}
			if(isButtonPressed(2)){
				timeGreen = time_green*100;
			}
			break;
		default:
			break;
		}
}
