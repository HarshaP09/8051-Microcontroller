# **Buzzer Control with Switch (8051)**

## Overview
This project demonstrates how to control a buzzer using the 8051 microcontroller and a push button.  
Each time the button is pressed, the buzzer toggles **ON or OFF**.  

---

## Circuit Connections
* Buzzer → P1.1  
* Push Button → P1.3   

---

## Theory
* **Buzzer**: A buzzer is an audio signaling device that produces sound when driven by a voltage. In microcontroller projects, it is often used for **alerts, notifications, and alarms**.  
* **Switch Control**:  
  * A push button acts as a digital input to the microcontroller.  
  * In this project, every press toggles the state of the buzzer:  
    * First press → Buzzer turns ON.  
    * Second press → Buzzer turns OFF.  
  * This is implemented using state toggling logic in the code.  

---

## Expected Output
* Initially, the buzzer is OFF.  
* When the button is pressed the Buzzer turns ON.  
* When the button is pressed again the Buzzer turns OFF.  
* This process repeats with every press of the button.  
