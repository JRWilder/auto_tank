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

///////////////////////// Timer B0 /////////////////////////
//TimerB0_0
#define TB0CCR0_INTERVAL 					(50000)//100msec.
#define TWOH_MS_COUNT						(0x02)//Used for a 200 millisecond timer.
extern volatile unsigned char update_display;//Used to flag if the LCD display should be updated.
extern volatile unsigned int update_display_count;//Used to adjust how often the display updates.
//TimerB0_1
#define TB0CCR1_INTERVAL 					(50000)//100msec.
#define DEBOUNCE_COUNT 						(0x05)//Used to adjust how long to wait to avoid the bouncing of the switch.
extern char	SW1_press;//Flag used to signify if switch 1 has been pressed.
extern char SW1_debounce;//Flag used to signify if debounce needs to be accounted for on switch 1.
extern unsigned int SW1_debounce_count;//Used as a counter to exit timerB0_1 ISR.
extern char	SW2_press;//Flag used to signify if switch 1 has been pressed.
extern char SW2_debounce;//Flag used to signify if debounce needs to be accounted for on switch 2.
extern unsigned int SW2_debounce_count;//Used as a counter to exit timerB0_1 ISR.
//TimerB0_2
#define TB0CCR2_INTERVAL 					(50000)//100msec.
#define OP_STATE_DELAY_COUNT 				(0x05)//Used as a 0.5 second timer.
extern unsigned int timerB0_2_count;//Used as a counter to exit timerB0_2 ISR.
//TimerB0_overflow

///////////////////////// Timer B1 /////////////////////////
//TimerB1_0
#define TB1CCR0_INTERVAL 					(50000)//100msec.
#define HALF_SEC_COUNT 						(0x05)//Used for a 0.5 second timer.
extern char timerB1_0;//Used as a flag to determine if timerB1_0 has been started.
extern unsigned int timerB1_0_case;//Used to choose different timing intervals in timerB1_0.
extern unsigned int timerB1_0_count;//Used as a counter to exit timerB1_0 ISR.
//TimerB1_1
#define TB1CCR1_INTERVAL 					(50000)//100msec
#define ONE_MS_COUNT						(0x01)//Used for a 1 millisecond timer.
#define FIVE_MS_COUNT						(0x05)//Used for a 5 millisecond timer.
#define FORTY_MS_COUNT						(0x28)//Used for a 40 millisecond timer.
#define FIFTY_MS_COUNT						(0x32)//Used for a 50 millisecond timer.
#define FIFTY_FIVE_MS_COUNT 				(0x37)//Used for a 55 millisecond timer.
#define SIXTY_MS_COUNT 						(0x3C)//Used for a 60 millisecond timer.
#define SIXTY_FIVE_MS_COUNT					(0x41)//Used for a 65 millisecond timer.
extern char timerB1_1;//Used as a flag to determine if timerB1_1 has been started.
extern unsigned int timerB1_1_case;//Used to choose different timing intervals in timerB1_1.
extern unsigned int timerB1_1_count;//Used as a counter to exit timerB1_1 ISR.
//TimerB1_2
#define TB1CCR2_INTERVAL 					(50000)//100msec
extern char timerB1_2;//Used as a flag to determine if timerB1_2 has been started.
extern unsigned int timerB1_2_case;//Used to choose different timing intervals in timerB1_2.
extern unsigned int timerB1_2_count;//Used as a counter to exit timerB1_2 ISR.

///////////////////////// Timer B2 /////////////////////////
///////////////////////// Timer B3 /////////////////////////

///////////////////////// ADC /////////////////////////
extern unsigned int channel;//Used to select between the ADC channels of thumb wheel, left detector, and right detector.
extern volatile unsigned int v_thumb;//Used to store the value the ADC reads from the thumb wheel.
extern volatile unsigned int v_detect_left;//Used to store the value the ADC reads from the left detector.
extern volatile unsigned int v_detect_right;//Used to store the value the ADC reads from the right detector.

extern volatile char slow_input_down;
extern char display_line[4][11];
extern char *display[4];
extern unsigned char display_mode;
extern volatile unsigned char display_changed;
extern unsigned int test_value;
extern char chosen_direction;
extern char change;

///////////////////////// Serial Interrupts /////////////////////////
//UCA0
#define THIRTY_TWO							(0x1A)
#define SIXTY_FOUR							(0xC0)
extern volatile char IOT_Rx[SIXTY_FOUR];
extern unsigned int IOT_Rx_index;
extern char IOT_Rx_rdy;
extern volatile char IOT_Tx[THIRTY_TWO];
extern unsigned int IOT_Tx_index;
extern char IOT_Tx_rdy;
extern unsigned int IOT_baud_rate;
//UCA1
extern volatile char USB_Rx[THIRTY_TWO];
extern volatile char USB_Tx[THIRTY_TWO];
extern unsigned int USB_Rx_index;
extern unsigned int USB_Tx_index;
extern char USB_Rx_rdy;
extern char USB_Tx_rdy;
extern unsigned int USB_baud_rate;
///////////////////////// Main /////////////////////////
extern volatile unsigned int old_v_thumb;
extern volatile char run_operation;
extern volatile unsigned int operation;
extern volatile unsigned int operation_state;
extern volatile unsigned int old_operation_state;
extern volatile char run_display;
extern volatile char reset_op;
extern char adc_char[ELEVEN];
extern char adc_char_timer[ELEVEN];

///////////////////////// Calibrate Operation /////////////////////////
#define SUBTRACT_VALUE						(0x32)//Used to subtract 50 from the average reading of the detectors to account for slight variences.
extern unsigned int left_white_value;//Used to store the average value read from the left detector off of the black tape.
extern unsigned int right_white_value;//Used to store the average value read from the right detector off of the black tape.
extern unsigned int left_black_value;//Used to store the average value read from the left detector on the black tape.
extern unsigned int right_black_value;//Used to store the average value read from the right detector on the black tape.
extern unsigned int read_count;//Used to keep track of how many readings are taken from the detectors.

///////////////////////// Line_Follow Operation /////////////////////////
#define MINUS_SMALL							(10)
#define MINUS_MEDIUM						(25)
#define MINUS_BIG							(50)
extern unsigned int position;
extern unsigned int last_position;

///////////////////////// SERIAL_COM Operation /////////////////////////
#define START_SIGNAL						(0x21)
#define COMMAND_START_SIGNAL				(0x26)
#define END_SIGNAL							(0x0D)
#define BAUD_115_VALUE 						(0x5551)
#define BAUD_460_VALUE 						(0x4A00)

///////////////////////// WIFI_COM Operation /////////////////////////
extern char SSid[TEN];
extern char SSID_temp[TEN];
extern unsigned int SSID_index;
extern char SSID_rdy;
extern char IP_addr[FOURTEEN];
extern char IP_addr1[TEN];
extern char IP_addr2[TEN];
extern unsigned int IP_ADDR_index;
extern char IP_ADDR_rdy;
extern volatile char command[THIRTY_TWO];
extern unsigned int command_index;
extern char command_rdy;
extern char diss_event[FOURTEEN];
extern unsigned int diss_index;
extern char diss_event_rdy;
extern char AT_sent;
extern char WSYN_sent;
extern char PING_sent;
extern char NSTC_sent;
extern char NSTAT_sent;
extern unsigned int station;
///////////////////////// PWM Operation /////////////////////////
#define STRAIGHT 							(0x01)
#define REVERSE 							(0x03)
#define CLOCKWISE 							(0x05)
#define COUNTER_CLOCKWISE 					(0x07)
#define CORRECT_LEFT						(0x09)
#define CORRECT_RIGHT						(0x011)
#define ARC_RIGHT 							(0x013)
#define ARC_LEFT							(0x015)
#define OFF 								(0x016)
#define WHEEL_OFF 							(0x00)
#define WHEEL_PERIOD 						(50000)
#define RIGHT_FORWARD_SPEED 				(TB3CCR1)
#define LEFT_FORWARD_SPEED	 				(TB3CCR2)
#define RIGHT_REVERSE_SPEED 				(TB3CCR3)
#define LEFT_REVERSE_SPEED 					(TB3CCR4)
#define TWENTY_PERCENT_SPEED 				(10000)
#define THIRTY_PERCENT_SPEED 				(15000)
#define FORTY_PERCENT_SPEED 				(20000)
#define FIFTY_PERCENT_SPEED 				(25000)
#define SIXTY_PERCENT_SPEED 				(30000)
#define SEVENTY_PERCENT_SPEED 				(35000)
#define EIGHTY_PERCENT_SPEED 				(40000)
#define NINETY_PERCENT_SPEED 				(45000)
