# **Keypad Interfacing with 7-Segment Display (8051)**

## Overview
This project demonstrates interfacing a 4x4 matrix keypad with a 7-segment display using the 8051 microcontroller.  
When a key is pressed on the keypad, the corresponding hexadecimal digit (0–F) is displayed on the 7-segment display.

---

## Circuit Connections

### Keypad
* A **4x4 matrix keypad** is connected to **Port 0 (P0)** of the 8051.  
* Rows and columns of the keypad are scanned to detect key presses.  

### 7-Segment Display
* A **common cathode 7-segment display** is connected to **Port 1 (P1)**.  
* Segment codes (0–F) are stored in an array and output to the display pins.  

### Control Pins
* Digit selection pins (c1, c2, c3, c4) are connected to **P2.0, P2.1, P2.2, P2.3**.  
* These are used to enable/disable display segments for proper multiplexing.

---

## Theory

* **Matrix Keypad (4x4):**  
A 4×4 keypad is a matrix-type input device that consists of 16 keys arranged in four rows and four columns. The keypad works on the principle of row and column scanning. The microcontroller sequentially activates one row at a time while keeping the others inactive and simultaneously monitors the column lines. When a key is pressed, it creates an electrical connection between a specific row and column, allowing the microcontroller to identify the exact key based on the active row and detected column.

* **7-Segment Display:**  
  Each digit/character is represented by activating specific LEDs in the 7-segment module.  
  The segment codes for hexadecimal digits (0–F) are stored in a lookup table.  

* **Working Principle:**  
  * The program continuously scans the keypad.  
  * When a valid key is detected, its mapped value is taken from the `key_map` array.  
  * The corresponding 7-segment code is fetched from `seg_code` array and displayed.

---

## Expected Output
* On pressing a key on the keypad, the corresponding value (0–9, A–F) is shown on the 7-segment display.  
* Example:  
  * Press `1` → Display shows **1**  
  * Press `A` → Display shows **A**  
  * Press `F` → Display shows **F**

