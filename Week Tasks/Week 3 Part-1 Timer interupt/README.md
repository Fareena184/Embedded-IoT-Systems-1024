# Timer Interrupt (Week 3 - Lecture 1 & 2)

**Course:** Embedded IoT Systems (Fall 2025)  
**Student:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024  

## Description
This project demonstrates the use of **hardware interrupts** on the ESP32.  
When the button connected to GPIO34 is pressed, an interrupt is triggered that **toggles the LED** connected to GPIO2.

##  Hardware Setup
- **Button:** GPIO34 → GND  
- **LED:** GPIO2 → On-board LED  

##  Working
- The button press triggers the **FALLING edge interrupt**.
- The ISR (`handleButton`) toggles the LED state instantly.
- The main loop remains **free for other tasks**, showing non-blocking interrupt-based control.

## Key Concepts
- External Interrupts  
- ISR (Interrupt Service Routine)  
- Non-blocking LED control
