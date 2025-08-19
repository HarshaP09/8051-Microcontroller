\# LED Blinking Patterns (8051)



\## Overview

This project demonstrates multiple LED blinking patterns using the 8051 microcontroller.  

It covers different methods of controlling LEDs connected to Port 0 (`P0`) and helps understand bitwise operations, delay loops, and port programming in 8051.



\## Implemented Patterns

1\. \*\*All LEDs ON/OFF\*\* – Turns all LEDs ON simultaneously, then OFF.

2\. \*\*Alternate LEDs ON/OFF\*\* – Switches between even-position LEDs (P0.0, P0.2, …) and odd-position LEDs (P0.1, P0.3, …).

3\. \*\*Upper vs Lower Nibble\*\* – Turns ON the upper 4 LEDs (P0.4–P0.7), then the lower 4 LEDs (P0.0–P0.3).

4\. \*\*Counting Pattern (00–FF)\*\* – Displays a binary counting sequence from 0x00 to 0xFF on the LEDs.



\## Circuit Connections

\- Port P0.0 → LED1 (with current-limiting resistor ~330Ω to GND)  

\- Port P0.1 → LED2  

\- Port P0.2 → LED3  

\- …  

\- Port P0.7 → LED8  



Note: Port 0 of 8051 is an open-drain port, so \*\*external pull-up resistors (typically 10kΩ) are required\*\* when connecting LEDs.



