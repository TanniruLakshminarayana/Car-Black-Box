/*
 * File:   AT24C04.c
 * Author: Lakshminarayana
 *
 * Created on 30 July, 2024, 10:43 AM
 */


#include <xc.h>
#include "i2c.h"
#include "AT24C04.h"

/*void init_AT24C04(void)
{
    unsigned char dummy;
    
    dummy = read_AT24C04(SEC_ADDR);
    dummy = dummy & 0x7F;
    write_AT24C04(SEC_ADDR, dummy);
}*/

unsigned char eeprom_at24c04_random_read(unsigned char memory_loc)
{
    unsigned char received_data = 0;

    i2c_start();
    i2c_write(SLAVE_WRITE_EE);
    i2c_write(memory_loc);
    i2c_rep_start();
    i2c_write(SLAVE_READ_EE);
    received_data = i2c_read(0);
    i2c_stop();

    return received_data;
}

void eeprom_at24c04_byte_write(unsigned char memory_loc, unsigned char data)
{
    i2c_start();
    i2c_write(SLAVE_WRITE_EE);
    i2c_write(memory_loc);
    i2c_write(data);
    i2c_stop();

    __delay_ms(3);
}

void eeprom_at24c04_str_write(unsigned char memory_loc, char *data)
{
    while (*data != 0)
    {
        eeprom_at24c04_byte_write(memory_loc, *data);
        data++;
        memory_loc++;
    }
}