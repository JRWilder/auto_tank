//******************************************************************************
// File Name: HEXtoBCD.c
// Description: This file contains the code to convert hexadecimal values into
// Binary-coded Decimal values
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

unsigned int timer_value_hex;
char adc_char_timer[ELEVEN] = {' ',' ',' ',' ',' ', '.',' ',' ',' ',' ',0};

void HEXtoBCD_timer(unsigned int timer_value_hex){
		int value = ZERO;

		while (timer_value_hex > 999){
			timer_value_hex = timer_value_hex - 1000;
			value++;
		}
		adc_char_timer[TWO] = 0x30 + value;
		value = ZERO;

		while (timer_value_hex > 99){
			timer_value_hex = timer_value_hex - 100;
			value++;
		}
		adc_char_timer[THREE] = 0x30 + value;
		value = ZERO;

		while (timer_value_hex > 9){
			timer_value_hex = timer_value_hex - 10;
			value++;
		}
		adc_char_timer[FOUR] = 0x30 + value;
		adc_char_timer[SIX] = 0x30 + timer_value_hex;
		value = ZERO;
}
