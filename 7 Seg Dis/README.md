\# 7-Segment Display with 8051



\## Overview

This project demonstrates interfacing a \*\*7-segment display\*\* with the 8051 microcontroller to display digits \*\*0–9 sequentially\*\*.  

It helps in understanding digital display driving, lookup tables, and GPIO-based interfacing.



---



\## Circuit Connections

\- \*\*Port P2\*\* → Connected to 7-segment display segments (a–g + DP)  

\- \*\*P0.0 → dis1\*\* (Digit Select 1)  

\- \*\*P0.1 → dis2\*\* (Digit Select 2)  

\- \*\*P0.2 → dis3\*\* (Digit Select 3)  

\- \*\*P0.3 → dis4\*\* (Digit Select 4)  



In this setup, all digit select lines are enabled together, so the same digit appears on all displays.  





\## Theory – 7-Segment Display

A \*\***7-segment display**\*\* is a simple output device used for displaying decimal numbers.  

It consists of \*\*seven LEDs\*\* arranged as segments (labeled \*\*a–g\*\*) and an optional \*\*decimal point (DP)\*\*.  



\- \*\***Common Cathode (CC)**:\*\* All cathodes connected to GND, segments turn ON when given logic HIGH.  

\- \*\***Common Anode (CA)**:\*\* All anodes connected to VCC, segments turn ON when given logic LOW.  



💡 This project uses \*\***Common Anode**\*\* configuration, as the program sends inverted (`~`) values to display digits.



---



\## Expected Output

\- The display will show numbers \*\*0–9 in sequence\*\*, one after another.  

\- All four digits will show the \*\*same number at the same time\*\*.  

\- After 9, the cycle restarts from 0.  



---



\## Learning Outcomes

\- Basics of \*\*7-segment display interfacing\*\* with 8051  

\- Difference between \*\*common cathode and common anode displays\*\*  

\- Sequential number display using microcontroller GPIO  



