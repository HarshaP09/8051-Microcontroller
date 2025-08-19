\# DC Motor Interfacing with 8051



\## Overview

This project demonstrates \*\*DC motor control using the 8051 microcontroller\*\*.  

Two variations are implemented:

1\. \*\*Simple DC Motor Run\*\* – Motor runs continuously in a single direction.  

2\. \*\*DC Motor Controlled by Switches\*\* – Motor operation (start, stop, direction, and speed) is controlled using input switches with PWM (duty cycle variation).



---



\## Circuit Connections



\### Code-1 (Simple Motor Run)

\- \*\*Enable Pin (EN1)\*\* → P2.0  

\- \*\*Input Pins (IN1, IN2)\*\* → P2.4, P2.5 (controls motor direction via H-Bridge).  

\- \*\*DC Motor\*\* connected via driver (L293D or equivalent).  

\- \*\*Power Supply\*\*: +5V to controller, +12V to motor.  



\### Code-2 (Motor with Switch Control)

\- \*\*Switches (Active LOW)\*\*:  

&nbsp; - Start → P1.0  

&nbsp; - Reverse → P1.1  

&nbsp; - Increase Speed → P1.2  

&nbsp; - Decrease Speed → P1.3  

&nbsp; - Stop → P1.4  

\- \*\*Motor Control Pins\*\* same as above (EN1 = P2.0, IN1 = P2.4, IN2 = P2.5).  

\- \*\*PWM Duty Cycle\*\* is adjusted to vary motor speed.



---



\## Theory

\- \*\*DC Motor Control\*\*: Requires driver circuits like L293D to handle higher current.  

\- \*\*Enable Pin (EN1)\*\*: Used for motor ON/OFF control (also for PWM-based speed control).  

\- \*\*IN1 \& IN2\*\*: Logic inputs to set direction (Forward/Reverse).  

\- \*\*Pulse Width Modulation (PWM)\*\*: Controls the average voltage applied → hence controls motor speed.  

\- \*\*Switch Interfacing\*\*: Pull-up configured switches provide user input for motor operations.  



---



\## Expected Output

\- \*\*Code-1\*\*:  

&nbsp; - Motor starts running immediately in forward direction and keeps running continuously.  



\- \*\*Code-2\*\*:  

&nbsp; 1. Press \*\*Start Switch\*\* → Motor starts running.  

&nbsp; 2. Press \*\*Stop Switch\*\* → Motor stops.  

&nbsp; 3. Press \*\*Increase Speed\*\* → Motor speed increases gradually.  

&nbsp; 4. Press \*\*Decrease Speed\*\* → Motor speed decreases gradually.  

&nbsp; 5. Press \*\*Reverse Switch\*\* → Motor changes direction of rotation.  





