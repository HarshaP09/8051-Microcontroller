\# Keypad Interfacing with LCD using 8051



\## Overview

This project demonstrates \*\*interfacing a 4x4 keypad with an LCD display\*\* using the 8051 microcontroller.  

The system captures user input from the keypad and displays the pressed key value on a \*\*16x2 LCD\*\*.



---



\## Circuit Connections

\- \*\*LCD Connections\*\*  

&nbsp; - Data lines → Port 1 (P1)  

&nbsp; - RS → P2.0  

&nbsp; - RW → P2.1  

&nbsp; - EN → P2.2  



\- \*\*Keypad Connections\*\*  

&nbsp; - 4 rows → Lower nibble of Port 0 (P0.0 – P0.3)  

&nbsp; - 4 columns → Upper nibble of Port 0 (P0.4 – P0.7)  



---



\## Theory – Keypad and LCD Interfacing

\- \*\*Keypad (4x4 Matrix):\*\*  

&nbsp; - A 4x4 matrix keypad has \*\*16 keys\*\* arranged in rows and columns.  

&nbsp; - By pulling one row low at a time and checking the columns, the microcontroller detects which key is pressed.  

&nbsp;



\- \*\*LCD (16x2):\*\*  

&nbsp; - Operates in \*\*8-bit mode\*\* (Port 1 used for data).  

&nbsp; - Commands are sent with RS=0, while data/characters are sent with RS=1.  

&nbsp; - Displays user-friendly messages and pressed keys.  



---



\## Expected Output

1\. LCD initially displays: The Pressed Value is:



