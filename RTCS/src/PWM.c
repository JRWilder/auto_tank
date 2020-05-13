//******************************************************************************
// File Name: PWM.c
// Description: This file contains the code that controls how the autonomous car
// will move.
// Author: Johnathan Wilder
// Date: May 2019
// Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

unsigned int pwm_delay;
unsigned int pwm_count;

/*
Full battery
STRAIGHT: 40, 50
REVERSE: 30, 40
CW: 20, 30
CCW: 30, 40
ARC_RIGHT: 60, 30
ARC_LEFT: 30, 70
*/

/*used batteries
STRAIGHT: 40, 60
REVERSE: 30, 40
CW: 20, 30
CCW: 30, 40
ARC_RIGHT: 60, 30
ARC_LEFT: 30, 70
*/

void pwm(unsigned int operation_state){
	/*if(operation == PWM){
		if(reset_op != HIGH){
			operation_state = v_thumb/DIVISOR;
			displays(operation*DIVISOR);
		}
	}*/
	switch(operation_state){
		case ZERO://Setup
			break;
		case STRAIGHT:
			if(RIGHT_REVERSE_SPEED != WHEEL_OFF){
				RIGHT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(LEFT_REVERSE_SPEED != WHEEL_OFF){
				LEFT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(RIGHT_FORWARD_SPEED != SIXTY_PERCENT_SPEED){
				RIGHT_FORWARD_SPEED = SIXTY_PERCENT_SPEED;
			}
			if(LEFT_FORWARD_SPEED !=FORTY_PERCENT_SPEED){
				LEFT_FORWARD_SPEED = FORTY_PERCENT_SPEED;
			}
			break;

		case TWO:
			operation_state = OFF;
			break;

		case REVERSE:
			if(RIGHT_FORWARD_SPEED != WHEEL_OFF){
				RIGHT_FORWARD_SPEED = WHEEL_OFF;
			}
			if(LEFT_FORWARD_SPEED != WHEEL_OFF){
				LEFT_FORWARD_SPEED = WHEEL_OFF;
			}
			if(RIGHT_REVERSE_SPEED != THIRTY_PERCENT_SPEED){
				RIGHT_REVERSE_SPEED = THIRTY_PERCENT_SPEED;
			}
			if(LEFT_REVERSE_SPEED != FORTY_PERCENT_SPEED){
				LEFT_REVERSE_SPEED = FORTY_PERCENT_SPEED;
			}
			break;

		case FOUR:
			operation_state = OFF;
			break;

		case CLOCKWISE:
			if(RIGHT_FORWARD_SPEED != WHEEL_OFF){
				RIGHT_FORWARD_SPEED = WHEEL_OFF;
			}
			if(LEFT_REVERSE_SPEED != WHEEL_OFF){
				LEFT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(RIGHT_REVERSE_SPEED != TWENTY_PERCENT_SPEED){
				RIGHT_REVERSE_SPEED = TWENTY_PERCENT_SPEED;
			}
			if(LEFT_FORWARD_SPEED != THIRTY_PERCENT_SPEED){
				LEFT_FORWARD_SPEED = THIRTY_PERCENT_SPEED;
			}
			break;

		case SIX:
			operation_state = OFF;
			break;

		case COUNTER_CLOCKWISE:
			if(RIGHT_REVERSE_SPEED != WHEEL_OFF){
				RIGHT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(LEFT_FORWARD_SPEED != WHEEL_OFF){
				LEFT_FORWARD_SPEED = WHEEL_OFF;
			}
			if(RIGHT_FORWARD_SPEED != THIRTY_PERCENT_SPEED){
				RIGHT_FORWARD_SPEED = THIRTY_PERCENT_SPEED;
			}
			if(LEFT_REVERSE_SPEED != TWENTY_PERCENT_SPEED){
				LEFT_REVERSE_SPEED = TWENTY_PERCENT_SPEED;
			}
			break;

		case EIGHT:
			operation_state = OFF;
			break;

		case CORRECT_LEFT:
			if(RIGHT_REVERSE_SPEED != WHEEL_OFF){
				RIGHT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(LEFT_REVERSE_SPEED != WHEEL_OFF){
				LEFT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(RIGHT_FORWARD_SPEED != WHEEL_OFF){
				RIGHT_FORWARD_SPEED = WHEEL_OFF;
			}
			if(LEFT_FORWARD_SPEED != THIRTY_PERCENT_SPEED){
				LEFT_FORWARD_SPEED = THIRTY_PERCENT_SPEED;
			}
			break;

		case TEN:
			operation_state = OFF;
			break;

		case CORRECT_RIGHT:
			if(RIGHT_REVERSE_SPEED != WHEEL_OFF){
				RIGHT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(LEFT_REVERSE_SPEED != WHEEL_OFF){
				LEFT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(RIGHT_FORWARD_SPEED != FORTY_PERCENT_SPEED){
				RIGHT_FORWARD_SPEED = FORTY_PERCENT_SPEED;
			}
			if(LEFT_FORWARD_SPEED != WHEEL_OFF){
				LEFT_FORWARD_SPEED = WHEEL_OFF;
			}
			break;

		case TWELVE:
			operation_state = OFF;
			break;

		case ARC_RIGHT:
			if(RIGHT_REVERSE_SPEED != WHEEL_OFF){
				RIGHT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(LEFT_REVERSE_SPEED != WHEEL_OFF){
				LEFT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(RIGHT_FORWARD_SPEED != THIRTY_PERCENT_SPEED){
				RIGHT_FORWARD_SPEED = THIRTY_PERCENT_SPEED;
			}
			if(LEFT_FORWARD_SPEED != SIXTY_PERCENT_SPEED){
				LEFT_FORWARD_SPEED = SIXTY_PERCENT_SPEED;
			}
			break;

		case FOURTEEN:
			operation_state = OFF;
			break;

		case ARC_LEFT:
			if(RIGHT_REVERSE_SPEED != WHEEL_OFF){
				RIGHT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(LEFT_REVERSE_SPEED != WHEEL_OFF){
				LEFT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(RIGHT_FORWARD_SPEED != SEVENTY_PERCENT_SPEED){
				RIGHT_FORWARD_SPEED = SEVENTY_PERCENT_SPEED;
			}
			if(LEFT_FORWARD_SPEED != THIRTY_PERCENT_SPEED){
				LEFT_FORWARD_SPEED = THIRTY_PERCENT_SPEED;
			}
			break;

		case OFF:
			if(RIGHT_FORWARD_SPEED != WHEEL_OFF){
				RIGHT_FORWARD_SPEED = WHEEL_OFF;
			}
			if(LEFT_FORWARD_SPEED != WHEEL_OFF){
				LEFT_FORWARD_SPEED = WHEEL_OFF;
			}
			if(RIGHT_REVERSE_SPEED != WHEEL_OFF){
				RIGHT_REVERSE_SPEED = WHEEL_OFF;
			}
			if(LEFT_REVERSE_SPEED != WHEEL_OFF){
				LEFT_REVERSE_SPEED = WHEEL_OFF;
			}
			break;

		default:
			reset_op = HIGH;
			break;
	}
}
