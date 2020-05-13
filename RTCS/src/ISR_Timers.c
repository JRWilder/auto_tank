//******************************************************************************
// File Name : timerB0_ISR.c
// Description: This file contains the code for timer B0 ISR.
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

//TimerB0_0
//TimerB0_1
char SW1_press = LOW;
char SW1_debounce = LOW;
unsigned int SW1_debounce_count = ZERO;
char SW2_press = LOW;
char SW2_debounce = LOW;
unsigned int SW2_debounce_count = ZERO;
//TimerB0_2
unsigned int timerB0_2_count = ZERO;

//TimerB1_0
char timerB1_0 = LOW;//Used as a flag to determine if timerB1_0 has been started.
unsigned int timerB1_0_case = ZERO;//Used to choose different timing intervals in timerB1_0.
unsigned int timerB1_0_count = ZERO;//Used as a counter to exit timerB1_0 ISR.
//TimerB1_1
char timerB1_1 = LOW;//Used as a flag to determine if timerB1_1 has been started.
unsigned int timerB1_1_case = ZERO;//Used to choose different timing intervals in timerB1_1.
unsigned int timerB1_1_count = ZERO;//Used as a counter to exit timerB1_1 ISR.
//TimerB1_2
char timerB1_2 = LOW;//Used as a flag to determine if timerB1_2 has been started.
unsigned int timerB1_2_case = ZERO;//Used to choose different timing intervals in timerB1_2.
unsigned int timerB1_2_count = ZERO;//Used as a counter to exit timerB1_2 ISR.

#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer0_B0_ISR(void){
	if(update_display_count++ > TWOH_MS_COUNT){
		update_display_count = ZERO;
		update_display = ONE;
		//P6OUT != GRN_LED;//Turns the green LED off and on ever 200 milliseconds.
	}
	TB0CCR0 += TB0CCR0_INTERVAL;
}

#pragma vector = TIMER0_B1_VECTOR
__interrupt void Timer0_B1_ISR(void){
	// TimerB0 1-2 and overflow Interrupt Vector (TBIV) handler
	switch(__even_in_range(TB0IV,FOURTEEN)){
		case ZERO:
			break; // No interrupt

		case TWO://TimerB0_1 ISR, switch debounce
			if(SW1_debounce){
				if(SW1_debounce_count++ > DEBOUNCE_COUNT){
					P4IFG &= ~SW1; //Disable the port interrupt flag
					P4IE |= SW1;
					TB0CCTL1 &= ~CCIE;
					SW1_debounce = LOW;
				}
			}
			if(SW2_debounce){
				if(SW2_debounce_count++ > DEBOUNCE_COUNT){
					P2IFG &= ~SW2;//Disable the port interrupt flag
					P2IE |= SW2;
					TB0CCTL1 &= ~CCIE;
					SW2_debounce = LOW;
				}
			}
			TB0CCR1 += TB0CCR1_INTERVAL;//Add Offset to TBCCR1
			break;

		case FOUR://timerB0_2 ISR, switch 2 operations
			if(SW2_press){
				if(timerB0_2_count++ > OP_STATE_DELAY_COUNT){
					TB0CCTL2 &= ~CCIE;
					timerB0_2_count = ZERO;
					operation_state++;
				}
			}
			TB0CCR2 += TB0CCR2_INTERVAL;
			break;

		case FOURTEEN: // overflow
			break;

		default: break;
	}
}

///////////////////////// Timer B1_0 ISR /////////////////////////
#pragma vector = TIMER1_B0_VECTOR
__interrupt void Timer1_B0_ISR(void){
	if(timerB1_0_count++ > HALF_SEC_COUNT*timerB1_0_case){
		switch(operation){
			case SEVEN:
				break;
			case SIX://Callibration.
				break;
			case FIVE://Line Follow.
				operation_state++;
				P5OUT |= IR_LED;
				TB1CCTL0 &= ~CCIE;
				break;
			case FOUR:// SERIAL_COM.
				IOT_Tx_rdy = LOW;
				IOT_Rx_index = ZERO;
				operation_state++;
				break;
			case THREE://WIFI
				TB1CCTL0 &= ~CCIE;
				operation_state = ONE;
				break;
			case TWO:
				break;
			default: break;
		}
		timerB1_0 = LOW;
		timerB1_0_count = ZERO;
	}
	TB1CCR0 += TB1CCR0_INTERVAL;
}

///////////////////////// Timer B1_1, B1_2, B1_overflow ISR /////////////////////////
#pragma vector = TIMER1_B1_VECTOR
__interrupt void Timer1_B1_ISR(void){
	switch(__even_in_range(TB1IV,FOURTEEN)){
		case ZERO:
			break;
		case TWO://PWM Delay
				timerB1_1_count++;
				HEXtoBCD_timer(timerB1_1_count);
				displays(operation);
			TB1CCR1 += TB1CCR1_INTERVAL;
			break;
		case FOUR:
			switch(timerB1_2_case){
				case ZERO://Circle Time
					break;
				case ONE://Back Mid
					break;
			}
			TB1CCR2 += TB1CCR2_INTERVAL;
			break;

		case FOURTEEN:
			break;
	}
}

void start_timerB1_0(unsigned int timerB1_0_value){
	timerB1_0 = HIGH;
	timerB1_0_case = timerB1_0_value;
	timerB1_0_count = ZERO;
	TB1CCTL0 |= CCIE;
}

void start_timerB1_1(unsigned int timerB1_1_value){
	timerB1_1 = HIGH;
	timerB1_1_count = ZERO;
	timerB1_1_case = timerB1_1_value;
	TB1CCTL1 |= CCIE;
}

void start_timerB1_2(unsigned int timerB1_2_value){
	timerB1_2 = HIGH;
	timerB1_2_case = timerB1_2_value;
	timerB1_2_count = ZERO;
	TB1CCTL2 |= CCIE;
}
