# **Stepper Motor Control with Speed & Direction (8051)**

## Overview
This project demonstrates how to control a stepper motor using the 8051 microcontroller with external switches.  
The user can start/stop the motor, change direction (forward/reverse), and adjust its speed using push buttons.

---

## Circuit Connections

### Stepper Motor Driver (IN1–IN4)
* IN1 → P2.4 
* IN2 → P2.5 
* IN3 → P2.6* 
* IN4 → P2.7* 
- These pins control the coils of the stepper motor in sequence.  

### Enable Pins
* EN1 → P2.0
* EN2 → P2.1  
- Used to enable motor driver channels.  

### Switches
* Start → P1.0 → Starts motor rotation.  
* Reverse → P1.1 → Toggles direction (forward/reverse).  
* Increase Speed → P1.2 → Increases motor speed (reduces delay).  
* Decrease Speed → P1.3 → Decreases motor speed (increases delay).  
* Stop → P1.4 → Stops the motor.  

---

## Theory

* **Stepper Motor**:  
  * A stepper motor moves in discrete steps. Each coil must be energized in a specific sequence to rotate the motor.  
  * **Forward sequence**: IN1 → IN2 → IN3 → IN4  
  * **Reverse sequence**: IN4 → IN3 → IN2 → IN1  
  * By adjusting the delay between steps, the motor’s speed can be controlled.  

* **Switch Control**:  
  The switches allow the user to start, stop, change direction, and control speed dynamically while the motor runs.  

---

## Expected Output
* Pressing Start → Motor begins to rotate.  
* Pressing Stop → Motor stops immediately.  
* Pressing Reverse → Motor changes its direction of rotation.  
* Pressing Increase Speed → Motor rotates faster.  
* Pressing Decrease Speed → Motor rotates slower.  

