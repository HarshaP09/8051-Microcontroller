"C:\Users\Harsha Pandhare\OneDrive\Documents\8051-MC"
cat > README.md <<'EOF'
# 8051 Microcontroller Projects

This repository contains multiple embedded C projects for the 8051 microcontroller, implemented and tested using **Keil uVision** and actual hardware.  
Each project folder contains:
- Source code (`.c`, `.h`)
- Keil project files (`.uvproj`, `.uvopt`)
- Compiled HEX files (`.hex`)
- Any supporting files needed to run the project

---

## Projects Included

1. **LED Blink** — Basic program to blink an LED.
2. **DC Motor Control** — Control motor direction and rotation speed.
3. **LCD Interface** — Display pressed characters and numbers on an LCD from 4*4 keyboard.
4. **Stepper Motor** — Control motor direction and stepping speed.
5. **7-segment display** — Displays numbers from 0-9 on a 7-segment display.
6. **buzzer** — This turns on/off the buzzer when the button is pressed.
7. **Relay** — This turns on/off the relay when button is pressed.
8. **DAC** - This contains various types of waveforms which is then seen using a CRO.
9. **Switches and LEDs** - Turns on a LED when corresponding switch is pressed.
10. **4*4 Keyboard** - Pressed key is displayed on 7-segment display 

## Tools Used
- Keil uVision (development & build)
- Progisp-172 (programming)
- Proteus / Multisim (optional simulation)
- Embedded C 

## How to Use
1. Clone or download this repository.
2. Open the desired project folder in **Keil uVision**.
3. Open the `.uvproj` file and build to generate `.hex`.
4. Flash `.hex` to your board. (or program via your programmer).

---
EOF
