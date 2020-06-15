//******************************************************************************
// File Name: Line_Follow.c
// Description: This file contains the code the autonomous car to intercept and
// then follow a black line.
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"
#include "Ports.h"

///////////////////////// Line_Follow Operation /////////////////////////
unsigned int position = ZERO;
unsigned int last_position = ZERO;

void line_follow(void){
	switch(operation_state){
		case ZERO://Setup
			break;
		case ONE://Intercept Line with Emitter OFF
			if(timerB1_0 != HIGH){
				start_timerB1_0(FOUR);
			}
			pwm(ARC_LEFT);
			break;
		case TWO://Intercept Line with Emitter ON
			if(timerB1_0 != HIGH){
				start_timerB1_0(FOUR);
			}
			break;
		case THREE://Intercept Line with Emitter ON
			intercept();
			break;
		case FOUR://Intercept_delay
			break;
		case FIVE://Alignment
			alignment();
			break;
		case SIX://BL_TRAVEL
			follow_black();
			if(timerB1_0 != HIGH){
				start_timerB1_0(FOURTEEN);
			}
			break;
		case SEVEN://Circle Delay
			pwm(OFF);
			if(timerB1_0 != HIGH){
				start_timerB1_0(FOUR);
			}
			break;
		case EIGHT://BL_CIRCLE
			TB1CCTL0 &= ~CCIE;
			TB1CCTL1 &= ~CCIE;
			follow_black();
			break;
		case NINE://BL_EXIT
			if(timerB1_0 != HIGH){
				pwm(STRAIGHT);
				start_timerB1_0(SIX);
			}
			break;
		case TEN://BL_DONE
				pwm(OFF);
				P5OUT &= ~IR_LED;
				TB1CCTL1 &= ~CCIE;
				string_copy(ZERO,  " BL_STOP  ");
				display_changed = HIGH;
			break;
		case ELEVEN:
			pwm(OFF);
			P5OUT &= ~IR_LED;
			TB1CCTL1 &= ~CCIE;
			string_copy(ZERO,  " BL_STOP  ");
			display_changed = HIGH;
			break;
		default:
			reset_op = HIGH;
			break;
	}
}

void intercept(void){
	pwm(STRAIGHT);
	if((v_detect_left >= left_black_value) || (v_detect_right >= right_black_value)){
		pwm(OFF);
		operation_state++;
		if(timerB1_0 != HIGH){
			start_timerB1_0(FOUR);
		}
	}
}
void alignment(void){
	pwm(CLOCKWISE);
	if((v_detect_left >= left_black_value) && (v_detect_right >= right_black_value)){
		pwm(OFF);
		operation_state++;
	}
}
void check_position(void){
	if((v_detect_left >= left_black_value) && (v_detect_right >= right_black_value)){
		position = ZERO;
	}
	if((v_detect_left < left_black_value) && (v_detect_right >= right_black_value)){
		position = ONE;
	}
	if((v_detect_left >= left_black_value) && (v_detect_right < right_black_value)){
		position = TWO;
	}
	if((v_detect_left < left_black_value) && (v_detect_right < right_black_value)){
		position = THREE;
	}
}
void follow_black(void){
	check_position();
	switch(position){
		case ZERO://Middle of Black
			last_position = ZERO;
			pwm(STRAIGHT);
			break;
		case ONE://Left of Middle
			last_position = ONE;
			pwm(CORRECT_LEFT);
			break;
		case TWO://Right of Middle
			last_position = TWO;
			pwm(CORRECT_RIGHT);
			break;
		case THREE://Off of Black
			if(last_position == ONE){
				pwm(CLOCKWISE);
			}
			if(last_position == TWO){
				pwm(COUNTER_CLOCKWISE);
			}
			break;
	}
}
