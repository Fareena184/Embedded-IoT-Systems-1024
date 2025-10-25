# ESP32 DHT11 + LDR + OLED Integration

This project demonstrates how to integrate **DHT11 (temperature & humidity)** and **LDR (light intensity)** sensors with an **OLED display (SSD1306)** using the **ESP32** microcontroller.

---

##  Overview

The ESP32 reads environmental data from two sensors:
- **DHT11** → Temperature and Humidity
- **LDR** → Light intensity (in ADC and Voltage)

The data is displayed in real time on a **128x64 OLED display** using the **Adafruit SSD1306** and **GFX** libraries.  
All readings are also printed to the **Serial Monitor** for debugging.

---

##  Hardware Connections

| Component | Pin (ESP32) | Description |
|------------|-------------|--------------|
| DHT11 Data | 14 | Digital Input |
| LDR | 36 | Analog Input (ADC) |
| OLED SDA | 21 | I2C Data |
| OLED SCL | 22 | I2C Clock |

---

##  Libraries Used

Make sure to install the following libraries via the Arduino Library Manager:

- **Adafruit GFX Library**
- **Adafruit SSD1306**
- **DHT Sensor Library**
- **Adafruit Unified Sensor**

---

##  How It Works

1. The ESP32 initializes the **DHT11**, **LDR**, and **OLED**.
2. Reads temperature, humidity, and light levels every 2 seconds.
3. Displays all sensor data on the OLED screen.
4. Also logs data to the Serial Monitor.

---


##  Author

**Name:** Fareena Shahbaz  
**Reg #:** 23-NTU-CS-FL-1024  
**Course:** Embedded IoT Systems (Fall 2025)  
**Week 6 Home Task**

---

##  Summary

This project combines two sensors (DHT11 + LDR) to measure and display environmental conditions.  
It provides a foundation for IoT-based weather and light monitoring applications using ESP32.

