//******************************************************************************
// File Name: Calibration.c
// Description: This file contains the code for the autonomous car to calibrate
// its IR detector values for both on white and on the black line.
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

///////////////////////// Calibration Operation /////////////////////////
unsigned int left_white_value = ZERO;//Used to store the average value read from the left detector off of the black tape.
unsigned int right_white_value = ZERO;//Used to store the average value read from the right detector off of the black tape.
unsigned int left_black_value = ZERO;//Used to store the average value read from the left detector on the black tape.
unsigned int right_black_value = ZERO;//Used to store the average value read from the right detector on the black tape.
unsigned int read_count = ZERO;//Used to keep track of how many readings are taken from the detectors.

void calibration(void){
	displays(SIX);
	switch(operation_state){
		case ZERO://Setup.
			break;
		case ONE://Emitter_On.
			P5OUT |= IR_LED;//Turns on the IR LED.
			left_white_value = ZERO;
			right_white_value = ZERO;
			left_black_value = ZERO;
			right_black_value = ZERO;
			read_count = ZERO;
			break;
		case TWO://White Calibration.
			if(read_count < TEN){//If the number of readings taken is less then 10 then continue to take readings.
				read_count++;//Increments the number of readings taken.
				left_white_value += v_detect_left;//Add the current reading from the left detector to the current left-white sum.
				right_white_value += v_detect_right;//Add the current reading from the right detector to the current right_white sum.
			}else{
				read_count = ZERO;//Reset the read count.
			}
			break;
		case THREE://Black Calibration.
			if(read_count < TEN){//If the number of readings taken is less then 10 then continue to take readings.
				read_count++;//Increments the number of readings taken.
				left_black_value += v_detect_left;//Add the current reading from the left detector to the current left-black sum.
				right_black_value += v_detect_right;//Add the current reading from the right detector to the current right_black sum.
			}
			break;
		case FOUR://Emitter Off.
			P5OUT &= ~IR_LED;
			left_white_value = left_white_value / read_count;//Take the average of all the readings from the left detector off of the tape.
			right_white_value = right_white_value / read_count;//Take the average of all the readings from the right detector off of the tape.
			left_black_value = left_black_value / read_count;//Take the average of all the readings from the left detector on the tape.
			right_black_value = right_black_value / read_count;//Take the average of all the readings from the right detector on the tape.
			left_white_value -= SUBTRACT_VALUE;//Subtracts 50 from average left_white readings to account for slight variences.
			right_white_value -= SUBTRACT_VALUE;//Subtracts 50 from average right_white readings to account for slight variences.
			left_black_value -= SUBTRACT_VALUE;//Subtracts 50 from average left_black readings to account for slight variences.
			right_black_value -= SUBTRACT_VALUE;//Subtracts 50 from average left_black readings to account for slight variences.
			operation_state++;//Increments the operation state.
			break;
		case FIVE://End calibration and switch to line detection.
			operation_state = ZERO;//Resets the operation state to setup.
			operation = FIVE;//Changes to the line follow operation.
			break;
	}
}
