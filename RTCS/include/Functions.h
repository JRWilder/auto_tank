//******************************************************************************
//  File Name: Functions.h
//  Description: This file contains the Function prototypes
//  Author: Johnathan Wilder
//  Date: May 2019
// Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (7.11.2)
//******************************************************************************

// Functions
void main(void);
void reset(unsigned int operation);

// Clocks
void Init_Clocks(void);
void Software_Trim(void);

// Timers
void Init_Timers(void);
void Init_Timer_B0(void);
void Init_Timer_B1(void);
void Init_Timer_B2(void);
void Init_Timer_B3(void);
void start_timerB1_0(unsigned int timerB1_0_value);
void start_timerB1_1(unsigned int timerB1_1_value);
void start_timerB1_2(unsigned int timerB1_2_value);

// Interrupts
void enable_interrupts(void);
__interrupt void Timer0_B0_ISR(void);
__interrupt void Timer0_B1_ISR(void);
__interrupt void Timer1_B0_ISR(void);
__interrupt void Timer1_B1_ISR(void);
__interrupt void Timer3_B5_ISR(void);
__interrupt void SW1_interrupt(void);
__interrupt void SW2_interrupt(void);
__interrupt void ADC_ISR(void);
__interrupt void eUSCI_A0_ISR(void);
__interrupt void eUSCI_A1_ISR(void);

// Ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_Port5(void);
void Init_Port6(void);

// Initialization
void Init_Conditions(void);
void init_adc(void);

// LED Configurations
void Init_LEDs(void);
void IR_LED_control(char selection);
void Backlite_control(char selection);

// LCD
void Display_Process(void);
void string_copy(unsigned int line, char* string);
void Display_Update(char p_L1,char p_L2,char p_L3,char p_L4);
void enable_display_update(void);
void update_string(char *string_data, int string);
void Init_LCD(void);
void lcd_clear(void);
void lcd_putc(char c);
void lcd_puts(char *s);
void lcd_power_on(void);
void lcd_write_line1(void);
void lcd_write_line2(void);
void displays(unsigned int display);
void normal_display(void);

//void lcd_draw_time_page(void);
//void lcd_power_off(void);
void lcd_enter_sleep(void);
void lcd_exit_sleep(void);

//void lcd_write(unsigned char c);
//void out_lcd(unsigned char c);
void Write_LCD_Ins(char instruction);
void Write_LCD_Data(char data);
void ClrDisplay(void);
void ClrDisplay_Buffer_0(void);
void ClrDisplay_Buffer_1(void);
void ClrDisplay_Buffer_2(void);
void ClrDisplay_Buffer_3(void);
void SetPostion(char pos);
void DisplayOnOff(char data);
void lcd_BIG_mid(void);
void lcd_4line(void);
void lcd_out(char *s, char line, char position);
void lcd_rotate(char view);

//void lcd_write(char data, char command);
void lcd_write(unsigned char c);
void lcd_write_line1(void);
void lcd_write_line2(void);
void lcd_write_line3(void);
void lcd_command( char data);
void LCD_test(void);
void LCD_iot_meassage_print(int nema_index);

// SPI
void Init_SPI_B1(void);
void SPI_B1_write(char byte);
void spi_rs_data(void);
void spi_rs_command(void);
void spi_LCD_idle(void);
void spi_LCD_active(void);
void SPI_test(void);
void WriteIns(char instruction);
void WriteData(char data);

// Switches
void Init_Switches(void);
void switch_control(void);
void enable_switch_SW1(void);
void enable_switch_SW2(void);
void disable_switch_SW1(void);
void disable_switch_SW2(void);
void Switches_Process(void);
void Init_Switch(void);
void Switch_Process(void);
void Switch1_Process(void);
void Switch2_Process(void);
void menu_act(void);
void menu_select(void);
void usleep(unsigned int usec);
void usleep10(unsigned int usec);
void five_msec_sleep(unsigned int msec);
void measure_delay(void);
void out_control_words(void);

// Analog to Digital Converter
void Init_ADC(void);
void HEXtoBCD(unsigned int v_detect_left_hex, unsigned int v_detect_right_hex);
void HEXtoBCD_timer(unsigned int timer_value_hex);

//Calibration
void calibration(void);

//LINE_FOLLOW
void line_follow(void);
void intercept(void);
void alignment(void);
void check_alignment(void);
void check_position(void);
void follow_black(void);

//SERIAL_COM
void Init_Serial(void);
void Init_Serial_UCA0(void);
void Init_Serial_UCA1(void);
void serial_com(void);
void IOT_transmit(void);

//WIFI_COM
void wifi_com(void);

//Movement
void pwm(unsigned int operation_state);
