#ifndef PORTS_H
#define PORTS_H

////////// PORT 1 //////////
#define RED_LED 							(0x01)//Pin 0, Red LED.
#define A1_SEEED 							(0x02)//Pin 1, A1_SEEED.
#define V_DETECT_L 							(0x04)//Pin 2, left IR detector.
#define V_DETECT_R 							(0x08)//Pin 3, right IR detector.
#define A4_SEEED 							(0x10)//Pin 4, A4_SEEED.
#define V_THUMB 							(0x20)//Pin 5, Thumb Wheel.
#define UCA0RXD 							(0x40)//Pin 6, Back Channel UCA0TXD.
#define UCA0TXD 							(0x80)//Pin 7, Back Channel UCA0RXD.

////////// PORT 2 //////////
#define P2_0 								(0x01)//Pin 0, .
#define P2_1 								(0x02)//Pin 1, .
#define P2_2 								(0x04)//Pin 2, .
#define SW2 								(0x08)//Pin 3, SW2.
#define P2_4 								(0x10)//Pin 4, .
#define P2_5 								(0x20)//Pin 5, .
#define LFXOUT 								(0x40)//Pin 6, XOUTR.
#define LFXIN 								(0x80)//Pin 7, XINR.

////////// PORT 3 //////////
#define TEST_PROBE 							(0x01)//Pin 0, TEST PROBE.
#define OA20 								(0x02)//Pin 1, Photodiode Circuit.
#define OA2N 								(0x04)//Pin 2, Photodiode Circuit.
#define OA2P 								(0x08)//Pin 3, Photodiode Circuit.
#define SMCLK_OUT 							(0x10)//Pin 4, SMCLK.
#define P3_5 								(0x20)//Pin 5, .
#define IOT_LINK 							(0x40)//Pin 6, IOT_LINK.
#define P3_7 								(0x80)//Pin 7, .

////////// PORT 4 //////////
#define RESET_LCD 							(0x01)//Pin 0, LCD Reset.
#define SW1 								(0x02)//Pin 1, SW1.
#define UCA1RXD 							(0x04)//Pin 2, Back Channel UCA1RXD.
#define UCA1TXD 							(0x08)//Pin 3, Back Channel UCA1TXD.
#define UCB1_CS_LCD 						(0x10)//Pin 4, Chip Select.
#define UCB1SCK 							(0x20)//Pin 5, SPI mode - clock output—UCB1CLK.
#define UCB1SIMO 							(0x40)//Pin 6, UCB1SIMO.
#define UCB1SOMI 							(0x80)//Pin 7, UCB1SOMI.

////////// PORT 5 //////////
#define IOT_RESET 							(0X01)//Pin 0, .
#define P5_1  								(0X02)//Pin 1, .
#define IOT_PROG_SEL 						(0X04)//Pin 2, .
#define IOT_PROG_MODE 						(0X08)//Pin 3, .
#define IR_LED 								(0X10)//Pin 4, .

////////// PORT 6 //////////
#define R_FORWARD 							(0X01)//Pin 0
#define L_FORWARD 							(0X02)//Pin 1
#define R_REVERSE 							(0X04)//Pin 2
#define L_REVERSE 							(0X08)//Pin 3
#define LCD_BACKLITE 						(0X10)//Pin 4
#define P6_5 								(0X20)//Pin 5
#define GRN_LED 							(0X40)//Pin 6

#endif
