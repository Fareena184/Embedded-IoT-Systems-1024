# Week 4 Home Task + Bonus task — Display Name and Emojis on OLED

##  Project Overview
This project uses an **SSD1306 OLED display** with the **ESP32** to show the student's name, ID, and simple emoji faces using ASCII characters.  
It demonstrates drawing lines, rectangles, and text on the OLED screen with different font sizes.

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
1. **First screen:** Draws two diagonal lines forming an “X”.  
2. **Second screen:** Displays the name and registration number inside a rectangular box.  
3. **Third screen:** Shows two ASCII-style emoji faces (`-_-` and `^_^`).  
4. Each display updates every **2 seconds**.

---

##  Libraries Required
Install the following via **Arduino Library Manager**:
- **Adafruit GFX Library**
- **Adafruit SSD1306**
- **Wire**

---

##  Author
**Name:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024  
**Course:** Embedded IoT Systems (Fall 2025)

