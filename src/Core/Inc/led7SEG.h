/*
 * led7SEG.h
 *
 *  Created on: Oct 29, 2023
 *      Author: Lenovo
 */

#ifndef INC_LED7SEG_H_
#define INC_LED7SEG_H_
#include "global.h"





void updateBuffer(int num1, int num2);
void reset7SEG();
void display7SEG(int counter);
void switch7SEG(int index);
void auto_switch_7SEG();// ham de switch led 1/4s
#endif /* INC_LED7SEG_H_ */


