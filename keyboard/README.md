\# Keypad Interfacing with 7-Segment Display (8051)



\## Overview

This project demonstrates \*\*interfacing a 4x4 matrix keypad with a 7-segment display\*\* using the 8051 microcontroller.  

When a key is pressed on the keypad, the corresponding \*\*hexadecimal digit (0–F)\*\* is displayed on the 7-segment display.



---



\## Circuit Connections



\### Keypad

\- A \*\*4x4 matrix keypad\*\* is connected to \*\*Port 0 (P0)\*\* of the 8051.  

\- Rows and columns of the keypad are scanned to detect key presses.  



\### 7-Segment Display

\- A \*\*common cathode 7-segment display\*\* is connected to \*\*Port 1 (P1)\*\*.  

\- Segment codes (0–F) are stored in an array and output to the display pins.  



\### Control Pins

\- Digit selection pins (c1, c2, c3, c4) are connected to \*\*P2.0, P2.1, P2.2, P2.3\*\*.  

\- These are used to enable/disable display segments for proper multiplexing.



---



\## Theory



\- \*\*Matrix Keypad (4x4):\*\*  

&nbsp; A keypad has \*\*4 rows and 4 columns\*\*. When a key is pressed, a row and column short together.  

&nbsp; By scanning rows and reading columns, the specific key pressed can be identified.



\- \*\*7-Segment Display:\*\*  

&nbsp; Each digit/character is represented by activating specific LEDs in the 7-segment module.  

&nbsp; The segment codes for hexadecimal digits (0–F) are stored in a lookup table.  



\- \*\*Working Principle:\*\*  

&nbsp; - The program continuously scans the keypad.  

&nbsp; - When a valid key is detected, its mapped value is taken from the `key\_map` array.  

&nbsp; - The corresponding \*\*7-segment code\*\* is fetched from `seg\_code` array and displayed.



---



\## Expected Output

\- On pressing a key on the keypad, the \*\*corresponding value\*\* (0–9, A–F) is shown on the 7-segment display.  

\- Example:  

&nbsp; - Press `1` → Display shows **\*\*1\*\***  

&nbsp; - Press `A` → Display shows **\*\*A\*\***  

&nbsp; - Press `F` → Display shows **\*\*F\*\***





