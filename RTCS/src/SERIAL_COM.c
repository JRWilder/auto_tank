//******************************************************************************
// File Name: SERIAL_COM.c
// Description: This file contains the code that resets the IoT module and
// establishes the connection to WiFi while automatically storing the SSID and
// IP address.
// Author: Johnathan Wilder
// Date: May 2019
// Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"
#include "SERIAL_COM"

char command1[THREE] = "AT\r";
char command2[TWENTY] = "AT+WSYNCINTRL=65535\r";
char command3[TWENTY_ONE] = "AT+PING=Google.com,3\r";
char command4[SIXTEEN] = "AT+NSTCP=5535,1\r";
char command5[ELEVEN] = "AT+NSTAT=?\r";
char SSID_temp[TEN] = "          ";
char IP_addr1[TEN] = "          ";
char IP_addr2[TEN] = "          ";

void serial_com(void){
	switch(operation_state){
		case ZERO://Setup
			if(UCA0BRW != FOUR){
				UCA0BRW = FOUR;
				UCA0MCTLW = BAUD_115_VALUE;
				UCA1BRW = FOUR;
				UCA1MCTLW = BAUD_115_VALUE;
			}
			pwm(OFF);
			if(timerB1_0 != HIGH){
				start_timerB1_0(ONE);
			}
			break;

		case ONE:
			P5OUT |= IOT_RESET;
			break;

		case FIVE://Send "AT"
			if(AT_sent != HIGH){
				for(unsigned int k = ZERO; k<THREE; k++){
					IOT_Tx[k] = command1[k];
				}
				IOT_transmit();
				AT_sent = HIGH;
			}
			break;

		case SIX://Send "AT+WSYNCINTRL=65535"
			if(WSYN_sent != HIGH){
				for(unsigned int k = ZERO; k<TWENTY; k++){
					IOT_Tx[k] = command2[k];
				}
				IOT_transmit();
				WSYN_sent = HIGH;
			}
			break;

		case SEVEN://Send "AT+PING=Google.com,1\r"
			if(PING_sent != HIGH){
				for(unsigned int k=ZERO; k<TWENTY_ONE; k++){
					IOT_Tx[k] = command3[k];
				}
				IOT_transmit();
				PING_sent = HIGH;
			}
			break;

		case ELEVEN://Send "AT+NSTCP=5535,1"
			if(NSTC_sent != HIGH){
				for(unsigned int k=ZERO; k<SIXTEEN; k++){
					IOT_Tx[k] = command4[k];
				}
				IOT_transmit();
				NSTC_sent = HIGH;
			}
			break;

		case TWELVE://Send "AT+NSTAT=?"
			if(NSTAT_sent != HIGH){
				for(unsigned int k = ZERO; k<ELEVEN; k++){
					IOT_Tx[k] = command5[k];
				}
				IOT_transmit();
				NSTAT_sent = HIGH;
			}
			break;

		case THIRTEEN://Configure SSID and IP ADDR
			TB1CCTL0 &= ~CCIE;
			/*
			switch(SSID_index){
				case ONE:
					for(unsigned int k=FOUR; k<FIVE; k++){
						SSID_temp[k] = SSid[k-FOUR];
					}
					break;
				case TWO:
					for(unsigned int k=FOUR; k<SIX; k++){
						SSID_temp[k] = SSid[k-FOUR];
					}
					break;
				case THREE:
					for(unsigned int k=THREE; k<SIX; k++){
						SSID_temp[k] = SSid[k-THREE];
					}
					break;
				case FOUR:
					for(unsigned int k=THREE; k<SEVEN; k++){
						SSID_temp[k] = SSid[k-THREE];
					}
					break;
				case FIVE:
					for(unsigned int k=TWO; k<SEVEN; k++){
						SSID_temp[k] = SSid[k-TWO];
					}
					break;
				case SIX:
					for(unsigned int k=TWO; k<EIGHT; k++){
						SSID_temp[k] = SSid[k-TWO];
					}
					break;
				case SEVEN:
					for(unsigned int k=ONE; k<EIGHT; k++){
						SSID_temp[k] = SSid[k-ONE];
					}
					break;
				case EIGHT:
					for(unsigned int k=ONE; k<NINE; k++){
						SSID_temp[k] = SSid[k-ONE];
					}
					break;
				case NINE:
					for(unsigned int k=ZERO; k<NINE; k++){
						SSID_temp[k] = SSid[k];
					}
					break;
				case TEN:
					for(unsigned int k=ZERO; k<TEN; k++){
						SSID_temp[k] = SSid[k];
					}
					break;
				default: break;
			}
			*/
			operation_state++;
			break;
		case FOURTEEN:
			for(unsigned int k=ONE; k<SEVEN; k++){
				IP_addr1[k+ONE] = IP_addr[k];
			}
			for(unsigned int k=EIGHT; k<FOURTEEN; k++){
				IP_addr2[k-SIX] = IP_addr[k];
			}
			operation = THREE;
			operation_state = ZERO;
			break;
		case FIFTEEN:

			break;
		default: break;
	}
}

void IOT_transmit(void){
	if(IOT_Tx_rdy != HIGH){
		IOT_Tx_rdy = HIGH;
		IOT_Tx_index = ZERO;
		UCA0IE |= UCTXIE;
	}
}
