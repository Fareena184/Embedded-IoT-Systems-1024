# Assignment 1 - Task B  
### Short Press → Toggle LED | Long Press (>1.5s) → Play Buzzer Tone  
**Author:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024  
**Course:** Embedded IoT Systems (Fall 2025)  
**University:** National Textile University, Faisalabad  

---

## Wokwi Project Link
You can view and simulate this project on Wokwi:  
[Wokwi Simulation Link](https://wokwi.com/projects/445804337034818561)

---

## Overview
This project demonstrates **multi-function button handling** using the **ESP32** microcontroller.  
A single button performs **two actions** based on press duration:  
- **Short Press:** Toggles the LED ON/OFF  
- **Long Press (>1.5s):** Plays a buzzer tone  

An **OLED display** shows the current state of the LED or buzzer, providing clear feedback to the user.

---

## Main Components and Technologies

| Component | Description |
|------------|-------------|
| **ESP32** | Main microcontroller used for button detection and output control |
| **Push Button** | Acts as input for short and long press detection |
| **LED** | Visual indicator toggled via button press |
| **Buzzer** | Produces sound when a long press is detected |
| **OLED Display (SSD1306)** | Displays messages such as “LED ON”, “LED OFF”, and “BUZZER ON” |
| **Arduino IDE** | Used for programming, compiling, and uploading the ESP32 sketch |

---

## Working Principle

The button is connected with an **internal pull-up resistor** (logic LOW when pressed).  
The program measures the **duration** of each press using `millis()` and classifies it as:  

| Press Type | Duration | Action |
|-------------|-----------|--------|
| **Short Press** | Less than 1.5 seconds | Toggles the LED ON/OFF |
| **Long Press** | 1.5 seconds or more | Activates the buzzer and displays “BUZZER ON” on the OLED |

The system includes **debounce logic** to filter out unwanted signal noise and ensure stable operation.

---

## File Description

| File | Description |
|------|-------------|
| `main.cpp` | Contains the complete implementation for detecting short/long presses, controlling LED and buzzer, and displaying updates on OLED |

---

## Functions Overview

| Function | Purpose |
|-----------|----------|
| `updateOLED(const char *msg)` | Clears the OLED and displays the current device state (LED/Buzzer) |
| `playBuzzerTone()` | Plays a 1000 Hz tone for 500 ms when a long press is detected |

---

## Timing and Debouncing

| Parameter | Description | Value |
|------------|-------------|--------|
| **DEBOUNCE_DELAY** | Filters switch noise | 50 ms |
| **LONG_PRESS_TIME** | Minimum duration to trigger a long press | 1500 ms (1.5 seconds) |

These constants ensure accurate press detection and prevent flickering or false triggering.

---

## How to Run

1. **Open** this code in Arduino IDE.  
2. **Select Board:** `ESP32 Dev Module`  
3. **Connect** your ESP32 board via USB.  
4. **Upload** the code.  
5. Use:
   - **Short Press (GPIO 34):** Toggle the LED ON/OFF.  
   - **Long Press (>1.5s):** Play buzzer tone and display “BUZZER ON”.  

---

## OLED Display Outputs

| Event | OLED Text | Action |
|--------|------------|--------|
| Initial State | “LED OFF” | LED is OFF |
| Short Press | “LED ON” / “LED OFF” | LED toggles |
| Long Press | “BUZZER ON” | Buzzer plays 500ms tone |

---

## Summary
This task demonstrates **button press duration detection**, **debounce handling**, and **multi-output control** on the ESP32.  
It is a fundamental experiment in **event-based embedded programming**, emphasizing **user interaction** and **real-time feedback** through both sound and display.

---
  
