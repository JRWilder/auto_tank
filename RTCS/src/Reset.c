//******************************************************************************
// File Name : Reset.c
// Description: This file contains the code to clear all flags, disable timers,
// and reset operation specific variables
// Author: Johnathan Wilder
// Date: January 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

void reset(unsigned int operation){
	pwm(OFF);
	run_operation = LOW;
	run_display = LOW;
	operation_state = ZERO;
	old_operation_state = ZERO;
	SW1_press = LOW;
	SW2_press = LOW;
	TB1CCTL0 &= ~CCIE;
	TB1CCTL1 &= ~CCIE;
	switch(operation){
		case SEVEN://Normal
			break;
		case SIX://Line Detect
			P5OUT &= ~IR_LED;
			break;
		case FIVE://Line Follow
			P5OUT &= ~IR_LED;
			break;
		case FOUR://Serial Communications
			//UCA0
			for(unsigned int i=ZERO; i<SIXTY_FOUR; i++){
				IOT_Rx[i] = ZERO;
			}
			for(unsigned int i=ZERO; i<THIRTY_TWO; i++){
				IOT_Tx[i] = ZERO;
			}
			for(unsigned int i=ZERO; i<THIRTY_TWO; i++){
				command[i] = ZERO;
			}
			IOT_Rx_index = ZERO;
			IOT_Rx_rdy = LOW;
			IOT_Tx_index = ZERO;
			IOT_Tx_rdy = LOW;
			SSID_index = ZERO;
			SSID_rdy = LOW;
			IP_ADDR_index = ZERO;
			IP_ADDR_rdy = LOW;
			command_index = ZERO;
			command_rdy = LOW;
			diss_index = ZERO;
			diss_event_rdy = LOW;

			//UCA1
			for(unsigned int i=ZERO; i<THIRTY_TWO; i++){
				USB_Rx[i] = ZERO; // USB Rx Buffer
				USB_Tx[i] = ZERO;
			}
			USB_Rx_index = ZERO;
			USB_Tx_index = ZERO;
			USB_Rx_rdy = LOW;
			USB_Tx_rdy = LOW;
			break;
		case THREE://WIFI
			station = ZERO;
			TB1CCTL1 &= ~CCIE;
			break;
		case TWO://Pulse Width Modulation (PWM)
			break;
		default: break;
	}
	reset_op = LOW;
	operation = ZERO;
}
