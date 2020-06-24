//******************************************************************************
// File Name: Display.c
// Description: This file contains all of the code to update the LCD display
// based on the operation and operation state.
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"
#include <string.h>

void displays(unsigned int display_mode){
	switch(display_mode){
		case SEVEN://Normal
			string_copy(ZERO,  "  HELLO!  ");
			string_copy(ONE,   "JOHNATHAN!");
			string_copy(TWO,   " I AM BOB ");
			string_copy(THREE, " JRWILDE2 ");
			if(operation != SEVEN){
				operation = SEVEN;
			}
			break;
		case SIX://Calibration
			if(run_display == HIGH){
				switch(operation_state){
					case ZERO://Setup
						string_copy(ONE,  "EMITTR_OFF");
						break;
					case ONE://Emitter_On
						string_copy(ONE,  "EMITTR_ON ");
						string_copy(TWO,  "LEFT RIGHT");
						break;
					case TWO://White Calibration
						string_copy(ONE,  "WHITE_CAL ");
						break;
					case THREE://Black Calibration
						string_copy(ONE,  "BLACK_CAL ");
						break;
					case FOUR://Emitter Off
						string_copy(ONE,  "EMITTR_OFF");
						break;
					default: break;
				}
				if(operation != SIX){
					operation = SIX;
				}
				HEXtoBCD(v_detect_left, v_detect_right);
				string_copy(THREE, adc_char);
			}else{
				string_copy(ZERO,   "LINE_DETEC");
				string_copy(ONE,    "          ");
				string_copy(TWO,    "          ");
				string_copy(THREE,  "          ");
			}
			break;
		case FIVE://Line Follow
			if(run_display == HIGH){
				switch(operation_state){
					case ZERO://Setup
						string_copy(ZERO, "LINE_FOLLW");
						break;
					/*//Commented out to create space
					case ZERO://Setup
						string_copy(ZERO,  "  START   ");
						break;
					case ONE://Intercept Line
						string_copy(ZERO,  "INTERCEPT ");
						break;
					case FOUR://Intercept delay
						string_copy(ZERO,  " WAITTING ");
						break;
					case FIVE://Alignment
						string_copy(ZERO,  "ALIGNMENT ");
						break;
					case SIX://Follow Line
						string_copy(ZERO,  "BL_TRAVEL ");
						break;
					case SEVEN://Intercept delay
						string_copy(ZERO,  " WAITTING ");
						break;
					case EIGHT://Go To Middle
						string_copy(ZERO,  "BL_CIRCLE ");
						break;
					case NINE:
						string_copy(ZERO,  " BL_EXIT  ");
						break;
					case TEN:
						string_copy(ZERO,  " BL_STOP  ");
						break;
					case ELEVEN:
						string_copy(ZERO,  " BL_STOP  ");
						break;
					*/
					default: break;
				}
				if(operation != FIVE){
					operation = FIVE;
				}
			}else{
				string_copy(ZERO,   "LINE_FOLLW");
				string_copy(ONE,    "          ");
				string_copy(TWO,    "          ");
				string_copy(THREE,  "          ");
			}
			break;
		case FOUR://Serial Communications
			if(run_display == HIGH){
				switch(operation_state){
					case ZERO://Setup
						string_copy(ONE,  "  SETUP   ");
						break;
					case ONE:
						break;
					case FIVE://Send AT
						string_copy(ONE, "    AT    ");
						break;
					/*Commented out for space
					case SIX://Send "AT+WSYNCINTRL=65535"
						string_copy(ONE, "AT+WSYNCIN");
						break;
					case SEVEN://Send "AT+PING=Google.com,1\r"
						string_copy(ONE, "AT+PING=Go");
						break;
					case ELEVEN://Send "AT+NSTCP=5535,1"
						string_copy(ONE, "AT+NSTCP=5");
						break;
					case TWELVE://Send "AT+NSTAT=?"
						string_copy(ONE, "AT+NSTAT=?");
						break;
						*/
					default: break;
				}
				//strcpy(display_line[ZERO], (char*) USB_Char_Rx);
				if(operation != FOUR){
					operation = FOUR;
				}
			}else{
				string_copy(ZERO,   "SERIAL_COM");
				string_copy(ONE,    "          ");
				string_copy(TWO,    "          ");
				string_copy(THREE,  "          ");
			}
			break;
		case THREE://WIFI_COM
			if(run_display == HIGH){
				switch(operation_state){
					case ZERO://Setup
						//string_copy(ZERO,  SSID_temp);
						//string_copy(ONE, "IP ADDRESS");
						string_copy(ZERO,    " WAITTING ");
						string_copy(ONE,  IP_addr1);
						string_copy(TWO,  IP_addr2);
						break;
					case ONE:
						break;
					case TWO:
						switch(station){
							/*Commented out for space
							case ZERO:
								break;
							case ONE:
								string_copy(ZERO,    "STATION 1 ");
								break;
							case TWO:
								string_copy(ZERO,    "STATION 2 ");
								break;
							case THREE:
								string_copy(ZERO,    "STATION 3 ");
								break;
							case FOUR:
								string_copy(ZERO,    "STATION 4 ");
								break;
							case FIVE:
								string_copy(ZERO,    "STATION 5 ");
								break;
							case SIX:
								string_copy(ZERO,    "STATION 6 ");
								break;
							case SEVEN:
								string_copy(ZERO,    "STATION 7 ");
								break;
							case EIGHT:
								string_copy(ZERO,    "STATION 8 ");
								break;
							*/
							default: break;
						}
						break;
					case THREE://WiFi movement commands
						switch(command[command_index+FOUR]){
							case 'R':
								string_copy(ZERO,    "   STOP   ");
								break;
							case 'W':
								string_copy(ZERO,    " STRAIGHT ");
								break;
							case 'S':
								string_copy(ZERO,    " REVERSE  ");
								break;
							case 'D':
								string_copy(ZERO,    "CLOCKWISE ");
								break;
							case 'A':
								string_copy(ZERO,    " CC_WISE  ");
								break;
							case 'Q':
								string_copy(ZERO,    " ARC_LEFT ");
								break;
							case 'E':
								string_copy(ZERO,    "ARC_RIGHT ");
								break;
							default: break;
						}
						break;
					default: break;
				}
				string_copy(THREE,   adc_char_timer);
				if(operation != THREE){
					operation = THREE;
				}
			}else{
				string_copy(ZERO,   " WIFI_COM ");
				string_copy(ONE,    "          ");
				string_copy(TWO,    "          ");
				string_copy(THREE,  "          ");
			}
			break;
		case TWO://Pulse Width Modulation (PWM)
			if(run_display == HIGH){
				switch(operation_state){
					case ZERO://Setup
						string_copy(ONE,  "  SETUP   ");
						break;
					case STRAIGHT:
						string_copy(ONE,  " STRAIGHT ");
						break;
					case REVERSE:
						string_copy(ONE,  " REVERSE  ");
						break;
					case CLOCKWISE:
						string_copy(ONE,  "CLOCKWISE ");
						break;
					case COUNTER_CLOCKWISE:
						string_copy(ONE,  " CC_WISE  ");
					case OFF:
						string_copy(ONE,  "   OFF    ");
					default:
						break;
				}
				if(operation != TWO){
					operation = TWO;
				}
			}else{
				string_copy(ZERO,   "   PWM    ");
				string_copy(ONE,    "          ");
				string_copy(TWO,    "          ");
				string_copy(THREE,  "          ");
			}
			break;
		default: break;
	}
	display_changed = HIGH;
}

void string_copy(unsigned int line, char* string){
	strcpy(display_line[line], string);
}
