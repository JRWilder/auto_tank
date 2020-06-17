//******************************************************************************
// File Name: WIFI_COM.c
// Description: This file contains the code that determines the actions the
// autonomous car will take when commands are sent over WiFi.
// Author: Johnathan Wilder
// Date: May 2019
// Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

unsigned int station = ZERO;
void wifi_com(void){
	switch(operation_state){
		case ZERO://Waitting for Command
			break;
		case ONE:
			break;
		case TWO:
			break;
		case THREE:
			if((command[command_index]=='0') && (command[command_index+ONE]=='4') && (command[command_index+TWO]=='1') &&(command[command_index+THREE]=='5')){
				switch(command[command_index+FOUR]){
					case 'R'://Reset
						pwm(OFF);
						operation_state = ONE;
						break;
					case 'W'://Network Joined
						pwm(STRAIGHT);
						operation_state = ONE;
						break;
					case 'S':
						pwm(REVERSE);
						operation_state = ONE;
						break;
					case 'D':
						pwm(CLOCKWISE);
						operation_state = ONE;
						break;
					case 'A':
						pwm(COUNTER_CLOCKWISE);
						operation_state = ONE;
						break;
					case 'Q':
						pwm(ARC_LEFT);
						operation_state = ONE;
						break;
					case 'E':
						pwm(ARC_RIGHT);
						operation_state = ONE;
						break;
					case 'T':
						operation_state = TWO;
						station++;
						break;
					case 'G':
						if(timerB1_1 != HIGH){
							start_timerB1_1(ONE);
							operation_state = TWO;
						}else{
							TB1CCTL1 &= ~CCIE;
							operation_state = FOUR;
						}
						break;
					case 'Z':
						operation = FIVE;
						operation_state = ONE;
						break;
					case 'M':
						operation = FIVE;
						operation_state = NINE;
						break;
					default: break;
				}
				/*
				switch(command[command_index+FIVE]){
					case '0':
						operation_state = ONE;
						break;
					case '1':
						if(timerB1_0 != HIGH){
							start_timerB1_0(FIVE);
						}
						operation_state = ONE;
						break;
					case '2':
						if(timerB1_0 != HIGH){
							start_timerB1_0(TEN);
						}
						operation_state = ONE;
						break;
					case '3':
						if(timerB1_0 != HIGH){
							start_timerB1_0(FIFTEEN);
						}
						operation_state = ONE;
						break;
					case '4':
						if(timerB1_0 != HIGH){
							start_timerB1_0(TWENTY);
						}
						operation_state = ONE;
						break;
					default: break;
				}*/
			}
			break;

		default: break;
	}
}
