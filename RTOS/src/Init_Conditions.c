//******************************************************************************
// File Name: Init_Conditions.c
// Description: This file contains the Initialization for all port pins
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************
#include "msp430.h"
#include "Functions.h"
#include "Macros.h"

void Init_Conditions(void){
	///////////////////////// LCD /////////////////////////
  int i;
  for(i=ZERO;i<ELEVEN;i++){
    display_line[ZERO][i] = ZERO;
    display_line[ONE][i] = ZERO;
    display_line[TWO][i] = ZERO;
    display_line[THREE][i] = ZERO;
  }

  display_line[ZERO][TEN] = ZERO;
  display_line[ONE][TEN] = ZERO;
  display_line[TWO][TEN] = ZERO;
  display_line[THREE][TEN] = ZERO;

  display[ZERO] = &display_line[ZERO][ZERO];
  display[ONE] = &display_line[ONE][ZERO];
  display[TWO] = &display_line[TWO][ZERO];
  display[THREE] = &display_line[THREE][ZERO];
  update_display = ZERO;
  update_display_count = ZERO;
}
