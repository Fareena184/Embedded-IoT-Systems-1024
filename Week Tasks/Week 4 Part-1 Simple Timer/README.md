# LED Blink using Hardware Timer  
**Week 4 Part-1 – LED Blink**  
**Course:** Embedded IoT Systems (Fall 2025)  
**Student:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024  

---

##  Description
This project demonstrates how to use an **ESP32 hardware timer interrupt** to toggle an LED at a fixed interval.  
Instead of using `delay()` or the main loop, a **hardware timer** is configured to trigger an **ISR (Interrupt Service Routine)** every second, which toggles the LED state.

---

##  Hardware Setup

| Component | GPIO | Description      |
|------------|------|------------------|
| LED        | 2    | On-board LED output |

- The LED blinks automatically every **1 second** using a timer interrupt.  
- The main loop remains **free** for other processing tasks.

---

## Working Principle
1. A **hardware timer** (`hw_timer_t`) is initialized with:
   - Clock frequency of 80 MHz  
   - Prescaler of 80 → tick = 1 µs  
2. The timer is configured to trigger every **1,000,000 µs (1 second)**.  
3. On each interrupt, the **`onTimer()` ISR** toggles the LED using `digitalWrite()`.  
4. The `loop()` function is left empty, showing how timers can handle periodic tasks efficiently.

---

## Key Concepts
- Hardware timers on ESP32  
- Interrupt Service Routine (ISR)  
- Non-blocking LED blinking  
- Timer-based scheduling

---

## Tools & Environment
- **Board:** ESP32 Development Board  
- **IDE:** Arduino IDE  
- **Language:** C++ (Arduino Framework)
