/* 
 * File:   digital_keypad.h
 * Author: Lakshminarayana
 *
 * Created on 31 July, 2024, 1:20 PM
 */

#ifndef DIGITAL_KEYPAD_H
#define	DIGITAL_KEYPAD_H

#define LEVEL_DETECTION         0
#define LEVEL                   0

#define STATE_DETECTION         1
#define STATE                   1

#define KEYPAD_PORT             PORTB
#define KEYPAD_PORT_DDR         TRISB

#define INPUT_LINES             0x3F

#define SW1                     0x3E
#define SW2                     0x3D
#define SW3                     0x3B
#define SW4                     0x37
#define SW5                     0x2F
#define SW6                     0x1F

#define SW4_LP                  0x80
#define SW5_LP                  0x90

#define ALL_RELEASED            INPUT_LINES

//unsigned char read_digital_keypad(unsigned char mode);
unsigned char read_digital_keypad(void);
void init_digital_keypad(void);

#endif	/* DIGITAL_KEYPAD_H */