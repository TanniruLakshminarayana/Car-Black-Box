/*
 * File:   digital_keypad.c
 * Author: Lakshminarayana
 *
 * Created on 31 July, 2024, 1:21 PM
 */



#include <xc.h>
#include "digital_keypad.h"

// External variables to indicate press type
extern unsigned char key_pressed;
extern unsigned char long_press_detected;

static unsigned char pre_key;

void init_digital_keypad(void)
{
    /* Set Keypad Port as input */
    KEYPAD_PORT_DDR = KEYPAD_PORT_DDR | INPUT_LINES;
}

unsigned char read_digital_keypad()
{
    static char once;
    static int long_pressed;
    unsigned char key = KEYPAD_PORT & INPUT_LINES;

    if (key != ALL_RELEASED && once == 0) /* when any key is pressed */
    {
        once = 1; /* set the flag indicating a key is pressed for the 1st time */
        long_pressed = 0; /* reset the long press counter */
        pre_key = key; /* store the key in another variable */
        long_press_detected = 0; /* Reset long press indicator */
    }
    else if (key == ALL_RELEASED && once == 1) /* when that key is released */
    {
        once = 0; /* reset the flag */

        if (long_pressed < 15) /* if key is pressed less than the given value */
        {
            key_pressed = pre_key; /* set the short press indicator */
            return pre_key; /* return the previous key value */
        }
    }

    /*________________________________________________________________________*/

    if (once == 1 && long_pressed < 16)
    {
        long_pressed++;
    }

    else if (once == 1 && long_pressed == 16) /* long press detected */
    {
        long_press_detected = 1; /* set long press indicator */
        return (key == SW4) ? SW4_LP : (key == SW5) ? SW5_LP : ALL_RELEASED;
    }

    return ALL_RELEASED;
}
