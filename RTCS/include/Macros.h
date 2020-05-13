//******************************************************************************
// File Name: Macros.h
// Description: This file contains the macros and global variables used by all
// the other files
// Author: Johnathan Wilder
// Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

#define LOW			       					('L')//Used to signify a character variable is low.
#define HIGH		         				('H')//Used to signify a character variable is high.
#define ZERO			    				(0x00)//Used to represent the numeric value 0.
#define ONE			    					(0x01)//Used to represent the numeric value 1.
#define TWO		    						(0x02)//Used to represent the numeric value 2.
#define THREE		    					(0x03)//Used to represent the numeric value 3.
#define FOUR		    					(0x04)//Used to represent the numeric value 4.
#define FIVE		    					(0x05)//Used to represent the numeric value 5.
#define SIX		    						(0x06)//Used to represent the numeric value 6.
#define SEVEN		    					(0x07)//Used to represent the numeric value 7.
#define EIGHT		    					(0x08)//Used to represent the numeric value 8.
#define NINE		    					(0x09)//Used to represent the numeric value 9.
#define TEN		    						(0x0A)//Used to represent the numeric value 10.
#define ELEVEN		    					(0x0B)//Used to represent the numeric value 11.
#define TWELVE		    					(0x0C)//Used to represent the numeric value 12.
#define THIRTEEN		    				(0x0D)//Used to represent the numeric value 13.
#define FOURTEEN		    				(0x0E)//Used to represent the numeric value 14.
#define FIFTEEN		    					(0x0F)//Used to represent the numeric value 15.
#define SIXTEEN		    					(0x10)//Used to represent the numeric value 16.
#define SEVENTEEN		    				(0x11)//Used to represent the numeric value 17.
#define EIGHTEEN	    					(0x12)//Used to represent the numeric value 18.
#define NINETEEN							(0x13)//Used to represent the numeric value 19.
#define TWENTY								(0x14)//Used to represent the numeric value 20.
#define TWENTY_ONE							(0x15)//Used to represent the numeric value 21.
#define USE_SMCLK 							(0x01)
#define MCLK_FREQ_MHZ 						(0x08) // MCLK = 8MHz.
#define CLEAR_REGISTER     					(0x0000)

extern volatile char slow_input_down;
extern char display_line[4][11];
extern char *display[4];
extern unsigned char display_mode;
extern volatile unsigned char display_changed;
extern unsigned int test_value;
extern char chosen_direction;
extern char change;
