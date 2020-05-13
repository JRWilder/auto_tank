//******************************************************************************
// File Name: Ports_ISR.c
// Description: This file contains the ISR for port 4, which is reserved for
// switch 1, and port 2, which is reserved for switch 2.
// Author: Johnathan Wilder
// Date: May 2019
// Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

#pragma vector=PORT4_VECTOR
__interrupt void SW1_interrupt(void){
 	if (P4IFG & SW1){
		SW1_press = HIGH;//Switch 1 has been pressed.
		SW1_debounce = HIGH;//Flag to disable switch 1 to account for debounce.
		SW1_debounce_count = LOW;//Reset the count required to wait for the debounce.
		P4IE &= ~SW1;//Disable switch 1 ISR.
		TB0CTL |= TBCLR;//Resets TB0R, clock divider, count direction.

		//Switch1 Function
		if(run_operation != HIGH){//If switch 1 is pressed once, it starts the operation.
			run_operation = HIGH;//Start the operation.
		}else{//If switch 1 is pressed a second time it ends the operation.
			reset_op = HIGH;//Reset to default state.
		}
	}
	TB0CCTL1 |= CCIE;//Enables the timerB0_1 ISR which is for debounce.
}

#pragma vector=PORT2_VECTOR
__interrupt void SW2_interrupt(void){
	if (P2IFG & SW2){
		SW2_press = HIGH;//Switch 2 has been pressed.
		SW2_debounce = HIGH;//Flag to disable switch 1 to account for debounce.
		SW2_debounce_count = LOW;//Reset the count required to wait for the debounce.
		timerB0_2_count = ZERO;//Resets the timerB0_2 count to zero.
		P2IE &= ~SW2;//Disable switch 2 ISR.
		TB0CTL |= TBCLR;//Resets TB0R, clock divider, count direction.

		//Switch2 function
		TB0CCTL1 |= CCIE;//Enables the timerB0_1 ISR which is for switch debounce.
		TB0CCTL2 |= CCIE;//Enables the timerB0_2 ISR which is for switch 2 operations.
	}
}
