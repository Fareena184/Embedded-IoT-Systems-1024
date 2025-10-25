#include <Arduino.h>

#define LED_PIN     4      // On-board LED
#define BUTTON_PIN  27     // Button to GND
#define DEBOUNCE_MS 50     // Debounce time

volatile bool ledState = false;         // LED state (on/off)
volatile uint32_t lastButtonMs = 0;     // Last button press time
////////////////////1024 FAREENA SHAHBAZ/////////
// Button ISR: toggle LED (with debounce)
void IRAM_ATTR onButton() {
  uint32_t now = millis();
  if (now - lastButtonMs > DEBOUNCE_MS) {
    lastButtonMs = now;
    ledState = !ledState;               // Toggle state
    digitalWrite(LED_PIN, ledState);    // Turn LED ON or OFF
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Button interrupt (FALLING = pressed)
  attachInterrupt(BUTTON_PIN, onButton, FALLING);
}

void loop() {
  // nothing needed, all handled by interrupt
}
