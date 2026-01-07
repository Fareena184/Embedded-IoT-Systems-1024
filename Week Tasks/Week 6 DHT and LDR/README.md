# Week 6 — DHT and LDR Sensor Display using ESP32 and OLED

##  Project Overview
This project demonstrates how to use **ESP32** to read environmental data from a **DHT11 (or DHT22)** sensor and a **Light Dependent Resistor (LDR)**.  
The collected **temperature**, **humidity**, and **light intensity** data are displayed on an **SSD1306 OLED display** and also printed on the **Serial Monitor**.

---

##  Hardware Setup

###  Components Used
- ESP32 Development Board  
- DHT11 (or DHT22) Temperature & Humidity Sensor  
- LDR (Light Dependent Resistor)  
- SSD1306 OLED Display (I2C)  
- 10kΩ Resistor (for LDR voltage divider)  
- Jumper Wires & Breadboard  

###  Pin Connections

| Component | Pin | ESP32 GPIO |
|------------|-----|-------------|
| DHT Data   | →   | 14 |
| OLED SDA   | →   | 21 |
| OLED SCL   | →   | 22 |
| LDR Output | →   | 34 |
| VCC        | →   | 3.3V |
| GND        | →   | GND |

---

##  Working Principle

1. The **DHT11** sensor measures **temperature** and **humidity**.  
2. The **LDR** sensor measures **light intensity**, converted into a voltage value using `analogRead()`.  
3. All sensor readings are displayed on the **OLED screen** and printed on the **Serial Monitor** for monitoring.  
4. The display updates every **2 seconds**.

---

##  Required Libraries

Install the following libraries from **Arduino Library Manager**:
- `Adafruit SSD1306`
- `Adafruit GFX`
- `DHT sensor library`

---

