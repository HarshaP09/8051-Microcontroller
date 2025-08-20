#include <reg51.h>

#define lcd_data P1
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

sbit SDA = P3^3;
sbit SCL = P3^2;

void delay(unsigned int ms) {
    unsigned int i, j;
    for(i = 0; i < ms; i++)
        for(j = 0; j < 1275; j++);
}

void lcd_cmd(unsigned char cmd) {
    RS = 0; RW = 0;
    lcd_data = cmd;
    EN = 1; delay(2); EN = 0;
}

void lcd_char(unsigned char val) {
    RS = 1; RW = 0;
    lcd_data = val;
    EN = 1; delay(2); EN = 0;
}

void lcd_string(char *s) {
    while(*s) lcd_char(*s++);
}

void lcd_init() {
    lcd_cmd(0x38); 
    lcd_cmd(0x0C); 
    lcd_cmd(0x01); 
    lcd_cmd(0x80); 
}

void i2c_start() {
    SDA = 1; SCL = 1;
    SDA = 0; SCL = 0;
}
void i2c_stop() {
    SDA = 0; SCL = 1;
    SDA = 1;
}
void i2c_write(unsigned char dat) {
    unsigned char i;
    for(i=0; i<8; i++) {
        SDA = (dat & 0x80) ? 1 : 0;
        SCL = 1; dat <<= 1; SCL = 0;
    }
    SDA = 1; SCL = 1; SCL = 0; 
}
unsigned char i2c_read() {
    unsigned char i, dat=0;
    SDA = 1; 
    for(i=0; i<8; i++) {
        SCL = 1;
        dat = (dat<<1) | SDA;
        SCL = 0;
    }
 
    SDA = 1; SCL = 1; SCL = 0;
    return dat;
}


#define RTC_ADDR_W 0xD0
#define RTC_ADDR_R 0xD1

unsigned char dec_to_bcd(unsigned char val) {
    return ((val/10)<<4) | (val%10);
}
unsigned char bcd_to_dec(unsigned char val) {
    return ((val>>4)*10) + (val & 0x0F);
}

void rtc_set_time(unsigned char hh, unsigned char mm, unsigned char ss) {
    i2c_start();
    i2c_write(RTC_ADDR_W);
    i2c_write(0x00);  
    i2c_write(dec_to_bcd(ss) & 0x7F);
    i2c_write(dec_to_bcd(mm));
    i2c_write(dec_to_bcd(hh));
    i2c_stop();
}



unsigned char rtc_read(unsigned char addr) {
    unsigned char val;
    i2c_start();
    i2c_write(RTC_ADDR_W);
    i2c_write(addr);
    i2c_start();
    i2c_write(RTC_ADDR_R);
    val = i2c_read();
    i2c_stop();
    return val;
}


void main() {
    unsigned char sec, min, hr;
    lcd_init();

    rtc_set_time(12, 0, 0); 

    lcd_cmd(0x80);
    lcd_string("Time:");

    while(1) {
        sec = bcd_to_dec(rtc_read(0x00));
        min = bcd_to_dec(rtc_read(0x01));
        hr  = bcd_to_dec(rtc_read(0x02));

        lcd_cmd(0xC0);
        lcd_char((hr/10)+'0');
        lcd_char((hr%10)+'0');
        lcd_char(':');
        lcd_char((min/10)+'0');
        lcd_char((min%10)+'0');
        lcd_char(':');
        lcd_char((sec/10)+'0');
        lcd_char((sec%10)+'0');

        delay(10);
    }
}
