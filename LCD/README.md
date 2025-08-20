# **Keypad Interfacing with LCD using 8051**

## Overview
* This project demonstrates interfacing a 4x4 keypad with an LCD display using the 8051 microcontroller.  
* The system captures user input from the keypad and displays the pressed key value on a 16x2 LCD.

---

## Circuit Connections
* **LCD Connections**  
  * Data lines → Port 1 (P1)  
  * RS → P2.0  
  * RW → P2.1  
  * EN → P2.2  

* **Keypad Connections**  
  * 4 rows → Lower nibble of Port 0 (P0.0 – P0.3)  
  * 4 columns → Upper nibble of Port 0 (P0.4 – P0.7)  

---

## Theory – Keypad and LCD Interfacing
* **Keypad (4x4 Matrix):**  
  * A 4x4 matrix keypad has **16 keys** arranged in rows and columns.  
  * By pulling one row low at a time and checking the columns, the microcontroller detects which key is pressed.  

* **LCD (16x2):**  
  * Operates in **8-bit mode** (Port 1 used for data).  
  * Commands are sent with RS=0, while data/characters are sent with RS=1.  
  - Displays user-friendly messages and pressed keys.  

---

## Expected Output
1. LCD initially displays:  **pressed value is:**
2. When a key is pressed on the keypad (e.g., `5`), the LCD shows:  **pressed value is:5**
