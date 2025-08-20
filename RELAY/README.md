# **Relay Control with Push Button using 8051**

## Overview
This project demonstrates how to control a relay using a push button and the 8051 microcontroller.  
A relay is an electromechanical switch that allows the microcontroller to control high-power devices like bulbs, fans, or motors with a simple low-power signal.

---

## Circuit Connections
* Relay module control pin → P2.0  
* Push button → P2.2 (with pull-up resistor)  
* Relay VCC & GND → +5V and Ground  
 * 8051 Ports →  
  * P2.0: Output to relay  
  * P2.2: Input from push button  

---

## Theory – Relay Interfacing
* A relay is an electromechanical switch used to control high-voltage or high-current circuits with a low-power signal from a microcontroller. It consists of a coil, armature, spring, and contacts. When current flows through the coil, it creates a magnetic field that pulls the armature, changing the contact position and switching the circuit ON or OFF. 
* The 8051 cannot directly drive high-voltage appliances, so a relay is used as an interface.  
* A push button provides user input:  
  * Each press toggles the relay **ON or OFF**.  
  * Relay energizes/de-energizes to switch external devices.  

---

## Expected Output
1. Initially, relay is OFF.  
2. When the button is pressed:  
   * Relay toggles its state (ON → OFF or OFF → ON).  
   * Connected load (like a bulb/fan) turns ON/OFF accordingly.  
3. Relay state remains stable until the next button press.  
