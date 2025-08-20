# **Real Time Clock (RTC) Interfacing with 8051 and LCD**

## Project Description
This project demonstrates how to interface a DS1307 RTC (Real Time Clock) with the 8051 microcontroller using the I²C protocol. The time (hours, minutes, seconds) is displayed on a 16x2 LCD in real-time. The RTC ensures accurate timekeeping even when the microcontroller is powered off, thanks to its onboard crystal and battery backup.

---

## Connections

* 8051 to LCD
  * P1 (P1.0 – P1.7) → Data pins (D0–D7) of LCD  
  * P2.0 → RS 
  * P2.1 → RW  
  * P2.2 → EN  

### 8051 to RTC (DS1307)
* P3.2 → SCL (Serial Clock Line)  
* P3.3 → SDA (Serial Data Line)  

### Other
* RTC requires a 32.768 kHz crystal oscillator.
* RTC backup battery: 3V coin cell.  

---

## Theory

### Real Time Clock (RTC - DS1307)

* The DS1307 is a real-time clock (RTC) integrated circuit that keeps accurate track of time in terms of seconds, minutes, hours, day, date, month, and year, including leap-year adjustments. It communicates with microcontrollers through the I²C protocol using just two lines, SDA and SCL. The IC requires an external 32.768 kHz crystal oscillator to maintain precise timing and is supported by a backup battery (commonly a 3V coin cell), allowing it to continue timekeeping even when the main system power is off. 
* It also includes 56 bytes of non-volatile RAM for general-purpose data storage. The DS1307 operates on a 5V supply and outputs time values in binary-coded decimal (BCD) format, making it easy for microcontrollers to process.
---

## Expected Output
* The LCD displays the real-time clock in the format: ** TIME : HH:MM:SS**
* At starting the time is set to **12:00:00** and then it starts incrementing by 1 sec.
* The time goes from **TIME 12:00:00** to **12:00:01** to **12:00:02**.....
