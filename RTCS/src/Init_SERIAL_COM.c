//******************************************************************************
// File Name: Init_SERIAL_COM.c
// Description: This file contains the Initialization for serial ports UCA0
// and UCA1.
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

///////////////////////// Serial Interrupts /////////////////////////
//UCA0
volatile char IOT_Rx[SIXTY_FOUR];
unsigned int IOT_Rx_index = ZERO;
char IOT_Rx_rdy = LOW;
volatile char IOT_Tx[THIRTY_TWO];
unsigned int IOT_Tx_index = ZERO;
char IOT_Tx_rdy = LOW;
char SSid[TEN];
unsigned int SSID_index = ZERO;
char SSID_rdy = LOW;
char IP_addr[FOURTEEN];
unsigned int IP_ADDR_index = ZERO;
char IP_ADDR_rdy = LOW;
volatile char command[THIRTY_TWO];
unsigned int command_index = ZERO;
char command_rdy = LOW;
char diss_event[FOURTEEN];
unsigned int diss_index = ZERO;
char diss_event_rdy = LOW;
char AT_sent = LOW;
char WSYN_sent = LOW;
char PING_sent = LOW;
char NSTC_sent = LOW;
char NSTAT_sent = LOW;
unsigned int IOT_baud_rate;
//UCA1
volatile char USB_Rx[THIRTY_TWO];
volatile char USB_Tx[THIRTY_TWO];
unsigned int USB_Rx_index = ZERO;
unsigned int USB_Tx_index = ZERO;
char USB_Rx_rdy = LOW;
char USB_Tx_rdy = LOW;
unsigned int USB_baud_rate;

void Init_Serial(void){
	Init_Serial_UCA0();
	Init_Serial_UCA1();
}

void Init_Serial_UCA0(void){
	for(unsigned int i=ZERO; i<SIXTY_FOUR; i++){
		IOT_Rx[i] = ZERO;
	}
	for(unsigned int i=ZERO; i<THIRTY_TWO; i++){
		IOT_Tx[i] = ZERO;
	}
	// Configure UART 0
	UCA0CTLW0 = ZERO; // Use word register
	UCA0CTLW0 |= UCSWRST; // Set Software reset enable
	UCA0CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK

	UCA0BRW = FOUR;
	UCA0MCTLW = BAUD_115_VALUE;
	UCA0CTLW0 &= ~ UCSWRST;             // Set Software reset enable
  UCA0IE |= UCRXIE;
}

void Init_Serial_UCA1(void){
	for(unsigned int i=ZERO; i<THIRTY_TWO; i++){
		USB_Rx[i] = ZERO; // USB Rx Buffer
		USB_Tx[i] = ZERO;
	}
	// Configure UART 0
	UCA1CTLW0 = ZERO; // Use word register
	UCA1CTLW0 |= UCSWRST; // Set Software reset enable
	UCA1CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK

	UCA1BRW = FOUR;
	UCA1MCTLW = BAUD_115_VALUE;
	UCA1CTLW0 &= ~ UCSWRST;             // Set Software reset enable
  UCA1IE |= UCRXIE;
}
