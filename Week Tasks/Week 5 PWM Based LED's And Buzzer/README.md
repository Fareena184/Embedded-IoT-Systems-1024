# Week 5  — LED & Buzzer PWM Demo

**Course:** Embedded IoT Systems (Fall 2025)  
**Student:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024

---

## Project Overview
This project demonstrates using the **ESP32 PWM (LEDC)** API to:
- Generate tones on a buzzer (using `ledcWriteTone`)
- Produce smooth brightness fades on two LEDs (using `ledcWrite`)

It includes short buzzer patterns (beeps, frequency sweep, melody) in `setup()` and a continuous cross-fade between two LEDs in `loop()`.

---

## Hardware
- **Microcontroller:** ESP32 development board  
- **Buzzer:** Active/passive buzzer connected to `BUZZER_PIN` (GPIO 27)  
- **LED 1:** Connected to `LED1_PIN` (GPIO 18)  
- **LED 2:** Connected to `LED2_PIN` (GPIO 19)  
- Use appropriate current-limiting resistors for LEDs (e.g., 220 Ω). If using a passive buzzer, ensure it supports the frequencies used.
