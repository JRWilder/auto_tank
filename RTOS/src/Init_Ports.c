//******************************************************************************
// File Name: Init_Ports.c
// Description: This file contains the Initialization for all port pins
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"
#include "Ports.h"

//This function calls all initialization port functions
void Init_Ports(void){
	Init_Port1(); //calls Init_Port1
	Init_Port2(); //calls Init_Port2
	Init_Port3(); //calls Init_Port3
	Init_Port4(); //calls Init_Port4
	Init_Port5(); //calls Init_Port5
	Init_Port6(); //calls Init_Port6
}

//This function initializes port1
void Init_Port1(void){
	P1OUT = ZERO; //sets all output values to 0
	P1DIR = ZERO; //sets all directions to inputs
	P1SEL0 = ZERO; //sets all select bit 0's to low
	P1SEL1 = ZERO; //sets all select bit 1's to low
	//pin0
	P1DIR |= RED_LED; //sets as output
	//pin 1
	P1SEL0 |= A1_SEEED; //sets select bit 0 high
	P1SEL1 |= A1_SEEED; //sets select bit 1 high
	//pin2
	P1SEL0 |= V_DETECT_L; //sets select bit 0 high
	P1SEL1 |= V_DETECT_L; //sets select bit 1 high
	//pin3
	P1SEL0 |= V_DETECT_R; //sets select bit 0 high
	P1SEL1 |= V_DETECT_R; //sets select bit 1 high
	//pin4
	P1SEL0 |= A4_SEEED; //sets select bit 0 high
	P1SEL1 |= A4_SEEED; //sets select bit 1 high
	//pin5
	P1SEL0 |= V_THUMB; //sets select bit 0 high
	P1SEL1 |= V_THUMB; //sets select bit 1 high
	//pin6
	P1SEL0 |= UCA0RXD; //sets select bit 0 high
	//pin7
	P1SEL0 |= UCA0TXD; //sets select bit 0 high
}

//This function initializes port2
void Init_Port2(void){
  P2OUT = ZERO; //sets all output values to 0
	P2DIR = ZERO; //sets all directions to inputs
	P2SEL0 = ZERO; //sets all select bit 0's to low
	P2SEL1 = ZERO; //sets all select bit 1's to low
	//pin0
	//pin1
	//pin2
	//pin3
	P2OUT |= SW2; // Configure pull-up resistor SW2
 	P2REN |= SW2; // Enable pull-up resistor SW2
 	P2IES |= SW2; // SW2 Hi/Lo edge interrupt
	P2IFG &= ~SW2; // IFG SW2 cleared
 	P2IE |= SW2; // SW2 interrupt Enable
	//pin4
	//pin5
	//pin6
	P2SEL1 |= LFXOUT; //sets select bit 1 high
	//pin7
	P2SEL1 |= LFXIN; //sets select bit 1 high
}

//This function initializes port3
void Init_Port3(void){
	P3OUT = ZERO; //sets all output values to 0
	P3DIR = ZERO; //sets all directions to inputs
	P3SEL0 = ZERO; //sets all select bit 0's to low
	P3SEL1 = ZERO; //sets all select bit 1's to low
	//pin0
	//pin1
	P3SEL0 |= OA20; //sets select bit 0 high
	P3SEL1 |= OA20; //sets select bit 1 high
	//pin2
	P3SEL0 |= OA2N; //sets select bit 0 high
	P3SEL1 |= OA2N; //sets select bit 1 high
	//pin3
	P3SEL0 |= OA2P; //sets select bit 0 high
	P3SEL1 |= OA2P; //sets select bit 1 high
	//pin4
	CSCTL5 &= ~DIVS__8;
	CSCTL5 &= ~DIVS__2;
	P3SEL0 &= ~SMCLK_OUT;
	//pin5
	P3SEL0 |= P3_5; //sets select bit 0 high
	P3SEL1 |= P3_5; //sets select bit 1 high
	//pin6

	//pin7
}

//This function initializes port4
void Init_Port4(void){
  P4OUT = ZERO; //sets all output values to 0
	P4DIR = ZERO; //sets all directions to inputs
	P4SEL0 = ZERO; //sets all select bit 0's to low
	P4SEL1 = ZERO; //sets all select bit 1's to low
	//pin0
	P4OUT |= RESET_LCD; //sets output value to 1
	P4DIR |= RESET_LCD; //enables the pull-up resistor
	//pin1
	P4OUT |= SW1; // Configure pull-up resistor SW1
	P4REN |= SW1; // Enable pull-up resistor SW1
	P4IES |= SW1; // SW1 Hi/Lo edge interrupt
	P4IFG &= ~SW1; // IFG SW1 cleared
	P4IE |= SW1; // SW1 interrupt Enabled
	//pin2
	P4SEL0 |= UCA1RXD; //sets select bit 0 high
	//pin3
	P4SEL0 |= UCA1TXD; //sets select bit 0 high
	//pin4
	P4OUT |= UCB1_CS_LCD; //sets output value to 1
	P4DIR |= UCB1_CS_LCD; //sets as output
	P4REN |= UCB1_CS_LCD; //enables the pull-up resister
	//pin5
	P4SEL0 |= UCB1SCK; //sets select bit 0 high
	//pin6
	P4SEL0 |= UCB1SIMO; //sets select bit 0 high
	//pin7
	P4SEL0 |= UCB1SOMI; //sets select bit 0 high
}

//This function initializes port5
void Init_Port5(void){
	P5OUT = ZERO; //sets all output values to 0
	P5DIR = ZERO; //sets all directions to inputs
	P5SEL0 = ZERO; //sets all select bit 0's to low
	P5SEL1 = ZERO; //sets all select bit 1's to low
	//pin0
	P5DIR |= IOT_RESET; //sets as output
	//pin1
	//pin2
	//pin3

	//pin4
	P5DIR |= IR_LED; //sets as output
}

//This function initializes port6
void Init_Port6(void){
	P6OUT = ZERO; //sets all output values to 0
	P6DIR = ZERO; //sets all directions to inputs
	P6SEL0 = ZERO; //sets all select bit 0's to low
	P6SEL1 = ZERO; //sets all select bit 1's to low
	//pin0
	P6SEL0 |= R_FORWARD;
	P6DIR |= R_FORWARD;
	//pin1
	P6SEL0 |= L_FORWARD;
	P6DIR |= L_FORWARD;
	//pin2
	P6SEL0 |= R_REVERSE;
	P6DIR |= R_REVERSE;
	//pin3
	P6SEL0 |= L_REVERSE;
	P6DIR |= L_REVERSE;
	//pin4
	P6OUT |= LCD_BACKLITE; //sets output value to be 1;
	P6DIR |= LCD_BACKLITE; //sets as an output
	//pin5
	P6SEL0 |= P6_5; //sets select bit 0 high
	//pin6
	P6DIR |= GRN_LED; //sets as output
}
