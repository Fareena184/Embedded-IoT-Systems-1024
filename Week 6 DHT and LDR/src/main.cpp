//Week-6  
//DHT and LDR Sensor Display using ESP32 and OLED
//Embedded IoT System fall-2025
// Name:fareena shahbaz REG # 23-NTU-CS-FL-1024
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

// --- Pin configuration ---
#define DHTPIN 14        // DHT22 data pin
#define DHTTYPE DHT11  // Change to DHT11 if needed

#define SDA_PIN 21       // I2C SDA
#define SCL_PIN 22       // I2C SCL

// --- OLED setup ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// --- DHT sensor setup ---
DHT dht(DHTPIN, DHTTYPE);

// --- Setup function ---
void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  // Initialize I2C on custom pins
  Wire.begin(SDA_PIN, SCL_PIN);

  // Initialize OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("SSD1306 allocation failed");
    for (;;);
  }
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Initializing...");
  display.display();

  // Initialize DHT sensor
  dht.begin();
  delay(1000);
}

// --- Main loop ---
void loop() {
  float temperature = dht.readTemperature();///important
  float humidity = dht.readHumidity();///important

  // Check if read failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Error reading DHT11 sensor!");
    return;
  }

  // Print values on Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" °C  |  Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Display on OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.println("Hello IoT");
  display.setCursor(0, 16);
  display.print("Temp: ");
  display.setTextSize(2);
  display.print(temperature);
  display.setTextSize(1);
  display.println(" C");
  display.setCursor(0, 32);
  display.print("Humidity: ");
  display.setTextSize(2);
  display.print(humidity);
  display.setTextSize(1);
  display.println(" %");
  display.display();

  delay(2000); // update every 2 seconds
}
// ////
////////////////code no. 2 With LDR/////////////////

// #include <Arduino.h>
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>

// #define LDR_PIN 34
// #define SDA_PIN 21
// #define SCL_PIN 22
// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64

// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// void setup() {
//   Serial.begin(115200);
//   Wire.begin(SDA_PIN, SCL_PIN);
//   display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
//   display.clearDisplay();
//   display.setTextColor(SSD1306_WHITE);
// }

// void loop() {
//   int adcValue = analogRead(LDR_PIN);
//   float voltage = (adcValue / 4095.0) * 3.3;

//   display.clearDisplay();
//   display.setTextSize(1);
//   display.setCursor(0,10);
//   display.print("LDR ADC: "); display.println(adcValue);
//   display.print("Voltage: "); display.print(voltage, 2); display.println(" V");
//   display.display();

//   Serial.printf("ADC: %d  |  Voltage: %.2f V\n", adcValue, voltage);
//   delay(1000);
// }
