#include "led7SEG.h"
#include "main.h"


void updateBuffer(int num1, int num2){
	number[0] = num1 / 10;
	number[1] = num1 % 10;
	number[2] = num2 / 10;
	number[3] = num2 % 10;
}

void reset7SEG(){
	HAL_GPIO_WritePin(GPIOA, EN0_Pin | EN1_Pin | EN2_Pin | EN3_Pin, 1);
}

void display7SEG(int counter){
	if(counter == 0){
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG6_Pin, 1);
	}
	else if(counter == 1){
		HAL_GPIO_WritePin(GPIOB,SEG1_Pin|SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 1);
	}
	else if(counter == 2){
		HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG3_Pin|SEG4_Pin|SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG2_Pin|SEG5_Pin, 1);
	}
	else if(counter == 3){
		HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG4_Pin|SEG5_Pin, 1);
	}
	else if (counter == 4){
		HAL_GPIO_WritePin(GPIOB,SEG1_Pin|SEG2_Pin|SEG5_Pin|SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG3_Pin|SEG4_Pin, 1);
	}
	else if (counter == 5){
		HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin|SEG4_Pin, 1);
	}
	else if (counter == 6){
		HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG1_Pin, 1);
	}
	else if (counter == 7){
		HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG2_Pin, 0);
		HAL_GPIO_WritePin(GPIOB, SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 1);
	}
	else if (counter == 8){
		HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin|SEG6_Pin, 0);
	}
	else if (counter == 9){
		HAL_GPIO_WritePin(GPIOB,SEG0_Pin|SEG1_Pin|SEG2_Pin|SEG3_Pin|SEG5_Pin|SEG6_Pin, 0);
		HAL_GPIO_WritePin(GPIOB,SEG4_Pin, 1);
	}
}



void switch7SEG(int index){
	switch (index){
	case 0:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 0);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		display7SEG(number[0]);
		break;
	case 1:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 0);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		display7SEG(number[1]);
		break;
	case 2:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 0);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 1);
		display7SEG(number[2]);
		break;
	case 3:
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, 1);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, 1);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, 1);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, 0);
		display7SEG(number[3]);
		break;
	default:
		break;
	}

}

int i = 0;

void auto_switch_7SEG(){
//	display7SEG(1);
	if(timer_flag[3] == 1){
		setTimer(3, 25);
		switch7SEG(i);
		if(i >= 3) i = 0;
		else i++;
	}
}

