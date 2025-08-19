#include <reg51.h>

// ===== LCD Connections =====
#define lcd_data P1
sbit RS = P2^0;
sbit RW = P2^1;
sbit EN = P2^2;

// ===== I2C Connections =====
sbit SDA = P3^3;
sbit SCL = P3^2;

#define DS1307_ID 0xD0  // 11010000 (write)

// ===== Delay =====
void delay(unsigned int ms) {
    unsigned int i, j;
    for(i=0; i<ms; i++)
        for(j=0; j<1275; j++);
}

// ===== LCD Functions =====
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
    lcd_cmd(0x38); // 2 line, 5x7 matrix
    lcd_cmd(0x0C); // Display on, cursor off
    lcd_cmd(0x01); // Clear
    lcd_cmd(0x80); // First line
}

// Print 2-digit numbers (e.g. 01, 09, 12)
void lcd_show_num(unsigned char num) {
    lcd_char((num/10) + '0');
    lcd_char((num%10) + '0');
}

// ===== I2C Functions =====
void i2c_start() {
    SDA = 1; SCL = 1; delay(1);
    SDA = 0; delay(1);
    SCL = 0;
}

void i2c_stop() {
    SDA = 0; SCL = 1; delay(1);
    SDA = 1; delay(1);
}

void i2c_write(unsigned char dat) {
    unsigned char i;
    for(i=0; i<8; i++) {
        SDA = (dat & 0x80) ? 1 : 0;
        SCL = 1; delay(1);
        SCL = 0; delay(1);
        dat <<= 1;
    }
    SDA = 1; SCL = 1; delay(1); // ACK
    SCL = 0;
}

unsigned char i2c_read(unsigned char ack) {
    unsigned char i, dat=0;
    SDA = 1; // Release SDA
    for(i=0; i<8; i++) {
        SCL = 1; delay(1);
        dat = (dat<<1) | SDA;
        SCL = 0; delay(1);
    }
    SDA = (ack) ? 0 : 1; // ACK for more, NACK for last
    SCL = 1; delay(1); SCL = 0;
    SDA = 1;
    return dat;
}

// ===== RTC Functions =====
unsigned char rtc_read(unsigned char addr) {
    unsigned char dat;
    i2c_start();
    i2c_write(DS1307_ID);     // Write mode
    i2c_write(addr);          // Address
    i2c_start();
    i2c_write(DS1307_ID | 1); // Read mode
    dat = i2c_read(0);
    i2c_stop();
    return dat;
}

void rtc_write(unsigned char addr, unsigned char dat) {
    i2c_start();
    i2c_write(DS1307_ID); // Write mode
    i2c_write(addr);
    i2c_write(dat);
    i2c_stop();
}

void rtc_set_time(unsigned char hr, unsigned char min, unsigned char sec) {
    rtc_write(0x00, ((sec/10)<<4) | (sec%10));   // Seconds BCD
    rtc_write(0x01, ((min/10)<<4) | (min%10));   // Minutes BCD
    rtc_write(0x02, ((hr/10)<<4) | (hr%10));     // Hours BCD
}

// Convert BCD ? Decimal
unsigned char BCD_DEC(unsigned char val) {
    return ((val >> 4) * 10 + (val & 0x0F));
}

// ===== Main =====
void main() {
    unsigned char sec, min, hour;
    unsigned char last_sec = 0xFF;

    lcd_init();
    lcd_cmd(0x80);
    lcd_string("Time: ");

    // Set time once ? 12:00:00
    rtc_set_time(12, 0, 0);

    while(1) {
        sec  = BCD_DEC(rtc_read(0x00) & 0x7F);
        min  = BCD_DEC(rtc_read(0x01) & 0x7F);
        hour = BCD_DEC(rtc_read(0x02) & 0x3F);

        if(sec != last_sec) {  // Update only when sec changes
            lcd_cmd(0x86);
            lcd_show_num(hour);
            lcd_char(':');
            lcd_show_num(min);
            lcd_char(':');
            lcd_show_num(sec);
            last_sec = sec;
        }

        delay(50);
    }
}
