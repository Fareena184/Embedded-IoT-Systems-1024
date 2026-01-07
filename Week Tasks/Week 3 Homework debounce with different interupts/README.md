# Button Debounce using Interrupt

**Course:** Embedded IoT Systems (Fall 2025)  
**Student:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024  

## Description
This project demonstrates how to handle **button debouncing** using an **interrupt service routine (ISR)** on the ESP32.  
Each time the button is pressed, the ISR checks if enough time has passed since the last press to avoid multiple triggers caused by button bounce.

## Hardware Setup
| Component | GPIO | Description        |
|------------|------|--------------------|
| LED        | 4    | On-board LED output |
| Button     | 27   | Connected to GND   |

- The button is configured with an **internal pull-up resistor**.  
- When pressed, the signal goes **LOW (FALLING edge)**.

##  Working Principle
1. Button press triggers an **external interrupt**.  
2. ISR checks the elapsed time using `millis()` to ensure debounce delay (50 ms).  
3. If valid, it toggles the LED state.  
4. The `loop()` remains empty since all logic is interrupt-driven.

##  Key Concepts
- Interrupt-driven input handling  
- Debouncing using software timing (`millis()`)  
- Non-blocking LED control
