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
