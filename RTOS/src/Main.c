//******************************************************************************
// File Name: Main.c
// Description: This file contains the Main Routine - "While" Operating System
// Author: Johnathan Wilder
// Date: May 2019
// Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"
#include <string.h>

///////////////////////// Operations /////////////////////////
volatile unsigned int v_thumb = ZERO;//Sets the current value read from the thumb wheel to zero
volatile unsigned int old_v_thumb = HIGH;//Sets the old value read from the thumb wheel to zero
volatile char run_operation = LOW;//Sets the va
volatile unsigned int operation = ZERO;
volatile unsigned int operation_state = ZERO;
volatile unsigned int old_operation_state = ZERO;
volatile char run_display = LOW;
volatile char reset_op = LOW;

void main(void){
//------------------------------------------------------------------------------
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.
//
//------------------------------------------------------------------------------
// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;
	Init_Ports();// Initialize Ports
	Init_Clocks();// Initialize Clock System
	Init_Conditions();// Initialize Variables and Initial Conditions
	Init_Timers();// Initialize Timers
	Init_LCD();// Initialize LCD
	Init_ADC();// Initialize Analog to Digital Converter
	Init_Serial();// Initialize serial ports
	enable_interrupts();

	while(ONE){// Can the Operating system run
		if(run_operation == HIGH){// If an operation is ready to run, continue
			if(reset_op != HIGH){// If reset is not ready, continue
				if(run_display != HIGH){
					run_display = HIGH;
					displays(v_thumb);
				}
				if(operation_state != old_operation_state){
					old_operation_state = operation_state;
					displays(operation);
				}
				switch(operation){
					case SEVEN://Normal
						break;
					case SIX://Calibration
						calibration();
						break;
					case FIVE://Line Follow
						line_follow();
						break;
					case FOUR://Serial Communications
						serial_com();
						break;
					case THREE://WiFi Communications
						wifi_com();
						break;
					case TWO://Pulse Width Modulation (PWM)
						pwm(operation_state);
						break;
					default: break;
				}
			}else{
				reset(operation);
				displays(v_thumb);
			}
		}else{
			if(v_thumb != old_v_thumb){
				old_v_thumb = v_thumb;
				displays(v_thumb);
			}
		}
		Display_Process();
	}
}
