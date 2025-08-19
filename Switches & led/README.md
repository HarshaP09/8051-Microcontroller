\# Switches and LEDs Interfacing with 8051



\## Overview

This project demonstrates \*\*interfacing switches and LEDs with the 8051 microcontroller\*\*.  

When a switch is pressed, the corresponding LED turns ON; otherwise, the LED remains OFF. This forms the basic building block for understanding \*\*digital input/output (I/O) handling\*\* with microcontrollers.



---



\## Circuit Connections

\- \*\*Input (Switches)\*\* → Port 1 (P1.0 – P1.7)  

&nbsp; - Connected with pull-up resistors (default HIGH, goes LOW when pressed).  

\- \*\*Output (LEDs)\*\* → Port 2 (P2.0 – P2.7)  

&nbsp; - Each LED corresponds to a switch.  



\- \*\*Power Supply\*\* → +5V for 8051, switches, and LEDs.  



---



\## 🔹Theory – Switch \& LED Interfacing

\- \*\*Switches:\*\* Act as digital inputs (logic HIGH = not pressed, logic LOW = pressed).  

\- \*\*LEDs:\*\* Act as digital outputs (ON when logic HIGH is applied).  

\- \*\*Logic:\*\* When a switch is pressed → input detected → corresponding LED is activated.  



---



\## 🔹 Expected Output

1\. All LEDs remain OFF when no switches are pressed.  

2\. If a switch is pressed (e.g., Switch 1), the corresponding LED (LED 1) turns ON.  

3\. Multiple switches can be pressed simultaneously, and the corresponding LEDs will glow.  



