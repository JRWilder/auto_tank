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

///////////////////////// SERIAL_COM Operation /////////////////////////
#define START_SIGNAL						(0x21)
#define COMMAND_START_SIGNAL				(0x26)
#define END_SIGNAL							(0x0D)
#define BAUD_115_VALUE 						(0x5551)
#define BAUD_460_VALUE 						(0x4A00)
