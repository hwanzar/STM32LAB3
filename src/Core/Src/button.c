/*
 * button.c
 *
 *  Created on: Oct 29, 2023
 *      Author: Admin
 */

#include "button.h"

uint16_t mode[3] = {BTN1_Pin, BTN2_Pin, BTN3_Pin};

int KeyReg0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};

int TimeOutForKeyPress[3] =  {200, 200, 200};
int button_flag[3] = {0, 0, 0};

int isButtonPressed(int num){
	if(button_flag[num] == 1){
		button_flag[num] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int num){
	//TODO
	button_flag[num]=1;
}

void getKeyInput(){
	for (int i=0; i < 3; i++){
		KeyReg2[i] = KeyReg1[i];
		KeyReg1[i] = KeyReg0[i];
		//Add your button here
		KeyReg0[i] = HAL_GPIO_ReadPin(GPIOC, mode[i]);

		if ((KeyReg1[i] == KeyReg0[i]) && (KeyReg1[i] == KeyReg2[i])){
			if (KeyReg2[i] != KeyReg3[i]){
				KeyReg3[i] = KeyReg2[i];
				if (KeyReg3[i] == PRESSED_STATE){
					TimeOutForKeyPress[i] = 200;
					subKeyProcess(i);
				}
			}

			else{ //press without release
				TimeOutForKeyPress[i]--;
				if (TimeOutForKeyPress[i] == 0){
					KeyReg3[i] = NORMAL_STATE;
				}
			}
		}
	}
}
