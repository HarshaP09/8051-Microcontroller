\# I²C EEPROM Interfacing with 8051



\## Overview

This project demonstrates interfacing an \*\*EEPROM memory chip\*\* with the \*\*8051 microcontroller\*\* using the \*\*I²C protocol\*\*.  

Data is written to and read back from the EEPROM to verify successful communication.  

The output data is displayed on \*\*Port 1 LEDs\*\*.



---



\## Circuit Connections

\- \*\*P2.2 (SCL)\*\* → Serial Clock Line of EEPROM  

\- \*\*P2.3 (SDA)\*\* → Serial Data Line of EEPROM  

\- \*\*P1 (LEDs/Output)\*\* → Used to display the data read from EEPROM  

\- \*\*VCC \& GND\*\* → Connected to EEPROM power supply pins  

\- \*\*Pull-up resistors (4.7kΩ recommended)\*\* → On SCL and SDA lines for proper I²C operation  



---



\## Theory – I²C and EEPROM

\- \*\*I²C (Inter-Integrated Circuit)\*\* is a two-wire communication protocol consisting of:

&nbsp; - \*\*SCL (Clock)\*\* – Synchronizes communication  

&nbsp; - \*\*SDA (Data)\*\* – Transfers serial data  



\- \*\*EEPROM (Electrically Erasable Programmable Read-Only Memory):\*\*  

&nbsp; Non-volatile memory used for permanent data storage. Supports byte-level read/write operations.  



\- In this project:

&nbsp; - `EEPROM\_Write(address, data)` → Stores a byte at the specified EEPROM address  

&nbsp; - `EEPROM\_Read(address)` → Retrieves the stored byte  

&nbsp; - The retrieved data is shown on \*\*Port 1 LEDs\*\*  



---



\## Expected Output

\- The program writes the value \*\*0xAA\*\* into EEPROM at address `0x00`.  

\- Then, it reads the same value back.  

\- The binary pattern of \*\*0xAA (10101010)\*\* will appear on the LEDs connected to \*\*Port 1\*\*.  

\- Successful read/write confirms correct I²C communication.  



---



