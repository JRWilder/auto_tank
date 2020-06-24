#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

char adc_char[ELEVEN] = {' ',' ',' ',' ',' ', ' ',' ',' ',' ',' ',0};


void HEXtoBCD(unsigned int v_detect_left_hex, unsigned int v_detect_right_hex){
	int value = ZERO;

	while (v_detect_left_hex > 999){
		v_detect_left_hex = v_detect_left_hex - 1000;
		value++;
	}
	adc_char[ZERO] = 0x30 + value;
	value = ZERO;

	while (v_detect_left_hex > 99){
		v_detect_left_hex = v_detect_left_hex - 100;
		value++;
	}
	adc_char[ONE] = 0x30 + value;
	value = ZERO;

	while (v_detect_left_hex > 9){
		v_detect_left_hex = v_detect_left_hex - 10;
		value++;
	}
	adc_char[TWO] = 0x30 + value;
	adc_char[THREE] = 0x30 + v_detect_left_hex;
	value = ZERO;

	while (v_detect_right_hex > 999){
		v_detect_right_hex = v_detect_right_hex - 1000;
		value++;
	}
	adc_char[SIX] = 0x30 + value;
	value = ZERO;

	while (v_detect_right_hex > 99){
		v_detect_right_hex = v_detect_right_hex - 100;
		value = value + 1;
	}
	adc_char[SEVEN] = 0x30 + value;
	value = ZERO;
	while (v_detect_right_hex > 9){
		v_detect_right_hex = v_detect_right_hex - 10;
		value++;
	}
	adc_char[EIGHT] = 0x30 + value;
	adc_char[NINE] = 0x30 + v_detect_right_hex;
}
