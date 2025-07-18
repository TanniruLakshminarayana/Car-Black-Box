/* 
 * File:   i2c.h
 * Author: Lakshminarayana
 *
 * Created on 31 July, 2024, 1:20 PM
 */

#ifndef I2C_H
#define	I2C_H

#define FOSC            20000000

void init_i2c(unsigned long baud);
void i2c_start(void);
void i2c_rep_start(void);
void i2c_stop(void);
unsigned char i2c_read(unsigned char ack);
int i2c_write(unsigned char data);
void i2c_wait_for_idle(void);

#endif	/* I2C_H */

