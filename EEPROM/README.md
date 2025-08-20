# **I²C EEPROM Interfacing with 8051**

## Overview
This project demonstrates interfacing an **EEPROM memory chip** with the **8051 microcontroller** using the **I²C protocol**.  
Data is written to and read back from the EEPROM to verify successful communication.  
The output data is displayed on Port 1 LEDs.

---

## Circuit Connections
* P2.2 connected to Serial Clock Line (SCL) of EEPROM  
* P2.3 is connected to Serial Data line (SDA) of EEPROM  
* P1 is coonected to LEDs to display the data read from EEPROM  
* VCC & GND Connected to EEPROM power supply pins
---

## Theory – I²C and EEPROM
* **I²C (Inter-Integrated Circuit)**  
  The I²C (Inter-Integrated Circuit) protocol is a two-wire communication standard that uses a Serial Data Line (SDA) and a Serial Clock Line (SCL). It allows multiple devices (masters and slaves) to communicate using unique addresses, with data transferred serially in a synchronized manner. It is widely used to connect peripherals like EEPROMs, RTCs, and sensors with microcontrollers.  

 * **EEPROM (Electrically Erasable Programmable Read-Only Memory):**  
 The EEPROM (Electrically Erasable Programmable Read-Only Memory) is a non-volatile memory chip that stores data even when power is off. Data can be electrically erased and reprogrammed byte by byte, making it useful for storing small amounts of data like configurations, calibration values, or logs in embedded systems..  
* In this project:
    * EEPROM_Write(address, data) → Stores a byte at the specified EEPROM address  
    * EEPROM_Read(address) → Retrieves the stored byte  
    * The retrieved data is shown on Port 1 LEDs 

---

## Expected Output
- The program writes the value **0xAA** into EEPROM at address **0x00**.  
- Then, it reads the same value back.  
- The binary pattern of **0xAA (10101010)** will appear on the LEDs connected to Port 1.  
- Successful read/write confirms correct I²C communication.  
