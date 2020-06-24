//******************************************************************************
// File Name: Serial_ISR.c
// Description: This file contains the code that handles the ISR's for both
// serial ports UCA0, and UCA1
// Author: Johnathan Wilder
// Date: May 2019
// Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

#pragma vector=EUSCI_A0_VECTOR
__interrupt void eUSCI_A0_ISR(void){
	switch(__even_in_range(UCA0IV,EIGHT)){
		case ZERO: // Vector 0 - no interrupt
			break;
		case TWO://IOT_Rx
			//SSID
			if(NSTAT_sent == HIGH){
				if(SSID_rdy == HIGH){
					if(UCA0RXBUF != '"'){
						SSid[SSID_index] = UCA0RXBUF;
						SSID_index++;
					}else{
						SSID_rdy = LOW;
					}
				}else{
						if(UCA0RXBUF == '"'){
							SSID_rdy = HIGH;
						}
				}
				//IP_ADDR
				if(IP_ADDR_rdy == HIGH){
					if(UCA0RXBUF != ' '){
						IP_addr[IP_ADDR_index] = UCA0RXBUF;
						IP_ADDR_index++;
					}else{
						IP_ADDR_rdy = LOW;
					}
				}else{
					if(UCA0RXBUF == 'r'){
						IP_ADDR_rdy = HIGH;
					}
				}
			}
			//Command
			if(command_rdy == HIGH){
					command[command_index] = UCA0RXBUF;
					command_index++;
					if((command_index>= THIRTY_TWO) || (UCA0RXBUF == END_SIGNAL)){
						command_index = ZERO;
						command_rdy = LOW;
						operation = THREE;
						operation_state = THREE;
					}
			}else{
				if(UCA0RXBUF == START_SIGNAL){
					command_rdy = HIGH;
				}
			}

			if(diss_event_rdy == HIGH){
				diss_event[diss_index] = UCA0RXBUF;
				diss_index++;
				if(diss_index>=FOURTEEN){
					if(strcmp(diss_event, "Disassociation") == 0){
						operation = FOUR;
						operation_state = ZERO;
					}
					diss_index = ZERO;
					diss_event_rdy = LOW;
				}
			}else{
				if(UCA0RXBUF == 'D'){
					diss_event_rdy = HIGH;
				}
			}
			IOT_Rx[IOT_Rx_index] = UCA0RXBUF;
			UCA1TXBUF = IOT_Rx[IOT_Rx_index];
			IOT_Rx_index++;
			if(IOT_Rx_index >= SIXTY_FOUR){
				IOT_Rx_index = ZERO;
			}
			break;
		case FOUR://IOT_Tx
			if(IOT_Tx_rdy == HIGH){
				UCA0TXBUF = IOT_Tx[IOT_Tx_index];
				if(IOT_Tx[IOT_Tx_index] == END_SIGNAL){
					UCA0IE &= ~UCTXIE;
				}
				if(IOT_Tx_index >= THIRTY_TWO){
					IOT_Tx_index = ZERO;
				}
				IOT_Tx_index++;
			}
			break;
		default: break;
	}
}

#pragma vector=EUSCI_A1_VECTOR
__interrupt void eUSCI_A1_ISR(void){
	switch(__even_in_range(UCA1IV,EIGHT)){
		case ZERO: // Vector 0 - no interrupt
			break;
		case TWO://USB_Rx
			USB_Rx[USB_Rx_index] = UCA1RXBUF; // RX -> USB_Receive character
			UCA0TXBUF = USB_Rx[USB_Rx_index];
			USB_Rx_index++;
			if((USB_Rx_index >= THIRTY_TWO) || (UCA1RXBUF == END_SIGNAL)){
				USB_Rx_index = ZERO;
			}
			break;
		case FOUR://USB_Tx
			UCA1TXBUF = USB_Tx[USB_Tx_index++];
			if(USB_Tx_index >= THIRTY_TWO){
				USB_Tx_index = ZERO;
			}
		break;
	default: break;
	}
}
