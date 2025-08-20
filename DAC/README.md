# **Waveform Generation using 8051**

## Overview
This project demonstrates how to generate different **digital waveforms** using the 8051 microcontroller.  
By varying the output pattern on Port 2, we can produce **Square, Triangular, Sawtooth, Staircase, and Sine waves**.  
These signals can be visualized on an oscilloscope or used to drive DACs for analog waveform output.

---

## Circuit Connections
* Port P2 Connected to DAC0808  to convert digital output into an analog signal  
- DAC output → Can be viewed on **CRO/DSO** for waveform observation  

---

## Theory – Waveform Generation
Microcontrollers like the 8051 can generate waveforms by writing digital values to a port at controlled intervals.  

1. **Square Wave** – Alternates between HIGH (0xFF) and LOW (0x00) at fixed delays.  
2. **Triangular Wave** – Increases output from 0 to 255 and decreases back to 0.  
3. **Sawtooth Wave** – Continuously increases output from 0 to 255, then resets.  
4. **Staircase Wave** – Steps in discrete levels (e.g., 3-step, 5-step) by incrementing output in fixed jumps.  
5. **Sine Wave** – Uses a **lookup table** of sampled sine values stored in an array to approximate a sine wave.  

With a DAC, these digital values are converted into smooth analog waveforms.

---

## Expected Output
* **Square Wave:** A high-low pulse signal on CRO.  
* **Triangular Wave:** A linear rise and fall waveform.  
* **Sawtooth Wave:** A continuous rising ramp with sharp fall.  
* **Staircase Wave:** Discrete step-like waveforms (3-step or 5-step).  
* **Sine Wave:** A smooth periodic waveform approximating a sine curve.  

All outputs can be verified on a CRO/DSO connected to the DAC output.


