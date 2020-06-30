//******************************************************************************
// File Name: ADC_Interrupt.c
// Description: This file contains the code for handling ADC interrupts from
// three different channels, Thumb Wheel, left and right IR detectors.
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

unsigned int channel;
volatile unsigned int v_detect_left;
volatile unsigned int v_detect_right;

#pragma vector = ADC_VECTOR
__interrupt void ADC_ISR(void){
	switch(__even_in_range(ADCIV,ADCIV_ADCIFG)){
		case ADCIV_NONE:
			break;
		case ADCIV_ADCOVIFG://When a conversion result is written to the ADCMEM0
		// before its previous conversion result was read.
			break;
		case ADCIV_ADCTOVIFG://ADC conversion-time overflow
			break;
		case ADCIV_ADCHIIFG://Window comparator interrupt flags
			break;
		case ADCIV_ADCLOIFG://Window comparator interrupt flag
			break;
		case ADCIV_ADCINIFG://Window comparator interrupt flag
			break;
		case ADCIV_ADCIFG://ADCMEM0 memory register with the conversion result
			ADCCTL0 &= ~ADCENC;
			switch(channel){
				case ZERO://Thumb Wheel Channel
					v_thumb = ADCMEM0>>NINE;//Divides the value read from the thumb wheel by nine and stores it
					ADCMCTL0 &= ~ADCINCH_5;//Turns off the ADC channel for the thumb wheel
					ADCMCTL0 |= ADCINCH_2;//Turns on the ADC channel for the left detector
					channel++;//Selects the left detector channel
					break;
				case ONE://Left Detector Channel
					v_detect_left = ADCMEM0>>TWO;//Divides the value read from the left detector by two and stores it
					ADCMCTL0 &= ~ADCINCH_2;//Turns off the ADC channel for the left detector
					ADCMCTL0 |= ADCINCH_3;//Turns on the ADC channel for the right detector
					channel++;//Selects the right detector channel
					break;
				case TWO://Right Detector Channel
					v_detect_right = ADCMEM0>>TWO;//Divides the value read from the right detector by two and stores it
					ADCMCTL0 &= ~ADCINCH_3;//Turns off the ADC channel for the right detector
					ADCMCTL0 |= ADCINCH_5;//Turns on the ADC channel for the thumb wheel
					channel = ZERO;//Selects the thumb wheel
					break;
			}
			ADCCTL0 |= ADCENC;
			ADCCTL0 |= ADCSC;
			break;
		default:
			break;
	}
}
