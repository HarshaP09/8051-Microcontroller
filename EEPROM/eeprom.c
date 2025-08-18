#include <reg51.h>

sbit SCL =P2^2;
sbit SDA = P2^3;

void delay(unsigned int t) {
    unsigned int i, j;
    for (i = 0; i < t; i++)
        for (j = 0; j < 127; j++);
}

void I2C_Start() {
    SDA = 1; SCL = 1; delay(1);
    SDA = 0; delay(1);
    SCL = 0;
}

void I2C_Stop() {
    SDA = 0; SCL = 1; delay(1);
    SDA = 1; delay(1);
}

bit I2C_Write(unsigned char dat) {
    unsigned char i;
    bit ack;
    for (i = 0; i < 8; i++) {
        SDA = (dat & 0x80) ? 1 : 0;
        SCL = 1; delay(1); SCL = 0;
        dat <<= 1;
    }
    SDA = 1; SCL = 1; delay(1);  
    ack = SDA; 
    SCL = 0;
    return ack;  
}

unsigned char I2C_Read(bit ack) {
    unsigned char i, dat = 0;
    SDA = 1;
    for (i = 0; i < 8; i++) {
        SCL = 1; delay(1);
        dat = (dat << 1) | SDA;
        SCL = 0; delay(1);
    }
    SDA = ack ? 0 : 1;
    SCL = 1; delay(1); SCL = 0;
    SDA = 1; 
    return dat;
}

void EEPROM_Write(unsigned char addr, unsigned char dat) {
    I2C_Start();
    I2C_Write(0xA0); 
    I2C_Write(addr);
    I2C_Write(dat);
    I2C_Stop();
    delay(50); 
}

unsigned char EEPROM_Read(unsigned char addr) {
    unsigned char dat;
    I2C_Start();
    I2C_Write(0xA0); 
    I2C_Write(addr);
    I2C_Start();
    I2C_Write(0xA1); 
    dat = I2C_Read(0); 
    I2C_Stop();
    return dat;
}

void main() {
    unsigned char value;
    P1 = 0x00;  

    EEPROM_Write(0x00, 0xAA); 
    value = EEPROM_Read(0x00); 

    P1 = value; 

    while (1);
}
