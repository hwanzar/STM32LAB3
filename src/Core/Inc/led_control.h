	/*
 * light_control.h
 *
 *  Created on: Oct 30, 2023
 *      Author: Lenovo
 */

#ifndef INC_LED_CONTROL_H_
#define INC_LED_CONTROL_H_

#include "global.h"
#include "main.h"

void onRed1();
void onYellow1();
void onGreen1();
void onRed2();
void onYellow2();
void onGreen2();
void resetLight();
void blinkLED(uint16_t led);
#endif /* INC_LED_CONTROL_H_ */
