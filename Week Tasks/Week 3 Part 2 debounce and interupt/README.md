# Debounce using Timer Interrupt  
**Week 3 – Lecture 3**  
**Course:** Embedded IoT Systems (Fall 2025)  
**Student:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024  

---

##  Description
This project demonstrates **software debouncing** on the **ESP32** using a **hardware timer interrupt** instead of traditional delay-based methods.  
When the push button is pressed, an interrupt starts a **one-shot timer** that waits for a short debounce interval (50 ms).  
If the button is still pressed after that time, the LED state is toggled.

---

##  Hardware Setup

| Component | GPIO | Description              |
|------------|------|--------------------------|
| LED        | 4    | On-board LED (output)    |
| Button     | 34   | Connected to GND (input) |

- The button uses an **internal pull-up resistor**.  
- Idle state: **HIGH**, Pressed state: **LOW (FALLING edge)**.  

---

##  Working Principle

1. **Button ISR (`onButtonISR`)** triggers on a **FALLING edge**.  
2. It starts a **one-shot hardware timer** for 50 ms.  
3. After 50 ms, **timer ISR (`onDebounceTimer`)** checks whether the button is still pressed.  
4. If yes, the LED on GPIO 4 is toggled.  
5. The variable `debounceActive` ensures that no new presses are handled during the debounce period.

---

##  Key Concepts
- Hardware timer interrupts (`hw_timer_t`)  
- Software debouncing using timing logic  
- Edge-triggered external interrupts  
- Non-blocking event handling (no delays in loop)  

---

##  Code Behavior Summary
- The **`setup()`** function initializes the LED, button, and timer.  
- The **`loop()`** function remains empty because **interrupts handle all logic asynchronously**.  
- The LED toggles cleanly on each button press, even with switch bounce.  

---

## Tools & Environment
- **Board:** ESP32 Development Board  
- **IDE:** Arduino IDE  
- **Language:** C++ (Arduino Framework)

---
