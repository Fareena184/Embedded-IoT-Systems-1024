# Week 4 Lecture 3 — OLED Display on ESP32

##  Project Overview
This project demonstrates how to interface an **SSD1306 OLED display** with the **ESP32** using the **Adafruit_GFX** and **Adafruit_SSD1306** libraries.  
It displays lines forming an "X" pattern and then shows text messages on the screen.

---

##  Hardware Setup
- **Microcontroller:** ESP32  
- **Display:** 0.96" SSD1306 OLED (I2C)
- **Connections:**
  - SDA → GPIO 21  
  - SCL → GPIO 22  
  - VCC → 3.3V  
  - GND → GND

---

##  Working
1. Initializes the OLED display at address **0x3C**.  
2. Draws two diagonal lines forming an “X”.  
3. Displays the text:
   - `"Hello"` (small font)
   - `"CS-A"` (larger font)  
4. Text and graphics are updated every 2 seconds.

---

## Libraries Required
Install the following libraries via **Arduino Library Manager**:
- **Adafruit GFX Library**
- **Adafruit SSD1306**
- **Wire**

---

##  Author
**Name:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024  
**Course:** Embedded IoT Systems (Fall 2025)

