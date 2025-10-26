//Assignment 1 - Task A
//Control LEDs and display mode using buttons.
// Name: Fareena Shahbaz
// REG #: 23-NTU-CS-FL-1024

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// --- Configuration Constants ---
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C

// Pin configuration
const int LED1_PIN = 18;
const int LED2_PIN = 17;
const int LED3_PIN = 16; 
const int BTN_MODE = 34; // Button to cycle modes (Input_Pullup wired to GND)
const int BTN_RESET = 35; // Button to reset to OFF (Input_Pullup wired to GND)
const int BUZZER_PIN = 25; 

// Debounce constants
const unsigned long DEBOUNCE_DELAY = 25; // Minimum stable time for button press confirmation

//brief OLED Display Object
//Initializes the SSD1306 display driver object using I2C communication.

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Enumeration for LED operational modes
enum Mode { BOTH_OFF, ALT_BLINK, BOTH_ON, PWM_FADE };
Mode currentMode = BOTH_OFF;

// Timer and state variables
unsigned long lastToggle = 0;
const unsigned long blinkInterval = 400; // Duration for each ON/OFF state in ALT_BLINK mode

// Button Debounce variables
unsigned long lastModePress = 0;
unsigned long lastResetPress = 0;
int lastModeState = HIGH;
// Tracks the previous stable reading of the mode button (HIGH when released)
int lastResetState = HIGH;
bool modePressed = false;  // Flag to ensure the mode change action triggers only once per press cycle
bool resetPressed = false;

int fadeVal = 0; // Current duty cycle value (0-255) for PWM fading
int fadeDir = 1; // Direction of fade: 1 for rising (up), -1 for falling (down)

// --- Function Declarations ---
void setLedsToOff();
void setLedsToHigh();
void updateOLED(const char *msg);
void handleModeChange();

void setup() {
  Serial.begin(115200);
  
  // Configure all LED pins as OUTPUT
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  // Configure buttons with internal pull-up resistors (read LOW when pressed)
  pinMode(BTN_MODE, INPUT_PULLUP);
  pinMode(BTN_RESET, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);
  
  // Initialize I2C communication for OLED (ESP32 standard pins 21/22)
  Wire.begin(21, 22); 
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println("OLED failed!");
    for (;;); // Halt if display fails to initialize
  }

  updateOLED("BOTH OFF");
  setLedsToOff(); // Ensure LEDs start in a clean OFF state
  Serial.println("Setup complete");
}

void loop() {
  unsigned long now = millis();

  // --- MODE Button Handler (Non-Blocking Debounce Logic) ---
  int readingMode = digitalRead(BTN_MODE);
  
  // Check if the pin state has changed
  if (readingMode != lastModeState) {
    lastModePress = now; // Reset the debounce timer if state is unstable
  }
  
  // If the pin state has been stable longer than the debounce time
  if ((now - lastModePress) > DEBOUNCE_DELAY) {
    // If stable state is LOW (pressed) AND the action hasn't been triggered yet
    if (readingMode == LOW && !modePressed) {
      modePressed = true;
      digitalWrite(LED3_PIN, HIGH); // Temporary LED3 ON as visual feedback for press
      handleModeChange(); // Execute mode cycle action
      Serial.println("Mode button pressed");
    }
    // If stable state is HIGH (released), reset the trigger flag and turn off feedback LED
    else if (readingMode == HIGH) {
      modePressed = false;
      digitalWrite(LED3_PIN, LOW);
    }
  }
  
  lastModeState = readingMode; // Save the current stable reading for the next iteration

  // --- RESET Button Handler (Non-Blocking Debounce Logic) ---
  int readingReset = digitalRead(BTN_RESET);
  
  // Check if the pin state has changed
  if (readingReset != lastResetState) {
    lastResetPress = now;
  }
  
  // If the pin state has been stable longer than the debounce time
  if ((now - lastResetPress) > DEBOUNCE_DELAY) {
    // If stable state is LOW (pressed) AND the action hasn't been triggered yet
    if (readingReset == LOW && !resetPressed) {
      resetPressed = true;
      digitalWrite(LED3_PIN, HIGH); // Temporary LED3 ON as visual feedback for press
      // Execute Reset action: Force mode to BOTH_OFF
      currentMode = BOTH_OFF;
      updateOLED("BOTH OFF");
      setLedsToOff();
      Serial.println("Reset button pressed");
    }
    // If stable state is HIGH (released), reset the trigger flag and turn off feedback LED
    else if (readingReset == HIGH) {
      resetPressed = false;
      digitalWrite(LED3_PIN, LOW);
    }
  }
  
  lastResetState = readingReset;

  // --- LED behavior based on currentMode ---
  switch (currentMode) {
    case BOTH_OFF:
      // LEDs are managed by setLedsToOff() when the mode is selected/reset
      break;

    case ALT_BLINK:
      // Non-blocking timer logic to toggle LEDs without stopping the loop
      if (now - lastToggle >= blinkInterval) {
        lastToggle = now;
        static bool toggle = false;
        toggle = !toggle;
        
        // Use analogWrite(255/0) for reliable ON/OFF on the PWM pins
        analogWrite(LED1_PIN, toggle ? 255 : 0);
        analogWrite(LED2_PIN, toggle ? 0 : 255);
        digitalWrite(LED3_PIN, LOW); 
      }
      break;

    case BOTH_ON:
      // LEDs are fully ON, set by setLedsToHigh() during mode change
      break;

    case PWM_FADE:
      // Increment/decrement fade value (duty cycle 0-255)
      fadeVal += fadeDir * 1; 
      
      // Check limits (0 and 180) and reverse direction
      if (fadeVal >= 180) { fadeVal = 180; fadeDir = -1; }
      if (fadeVal <= 0) 	 { fadeVal = 0;   fadeDir = 1;  }
      
      // Apply the calculated duty cycle to the LEDs
      analogWrite(LED1_PIN, fadeVal);
      analogWrite(LED2_PIN, fadeVal);
      digitalWrite(LED3_PIN, LOW); // LED3 remains off in fade mode
      
      delay(20); // Small blocking delay to control the visual speed of the fade
      break;
  }
}


//brief Turns all connected LEDs off reliably.
//Uses analogWrite(0) for pins 17 and 18 to ensure the PWM hardware
//is properly reset, preventing residual brightness or flicker.

void setLedsToOff() {
  analogWrite(LED1_PIN, 0); 
  analogWrite(LED2_PIN, 0); 
  digitalWrite(LED3_PIN, LOW); 
}
 
//brief Sets all connected LEDs to full brightness.
//Uses analogWrite(255) for pins 17 and 18 to set 100% duty cycle,
//which is more reliable than digitalWrite(HIGH) after a pin has been used for PWM.

void setLedsToHigh() {
  analogWrite(LED1_PIN, 255); 
  analogWrite(LED2_PIN, 255); 
  digitalWrite(LED3_PIN, HIGH); 
}


//brief Cycles the LED mode and calls the necessary setup functions for the new mode.\
//Updates the currentMode variable, displays the new mode on the OLED, 
//and resets mode-specific variables (like fadeVal or lastToggle).
//
void handleModeChange() {
    // Cycle to the next mode (0, 1, 2, 3, then back to 0)
    currentMode = (Mode)((currentMode + 1) % 4);
    
    // Set initial state for the new mode
    switch (currentMode) {
      case BOTH_OFF:    
        updateOLED("BOTH OFF");   
        setLedsToOff();
        break;
      case ALT_BLINK:   
        updateOLED("ALT BLINK");  
        setLedsToOff();
        lastToggle = millis(); // Reset blink timer on entry to start blinking immediately
        break;
      case BOTH_ON:     
        updateOLED("BOTH ON");    
        setLedsToHigh();
        break;
      case PWM_FADE:    
        updateOLED("PWM FADE");   
        fadeVal = 0; 
        fadeDir = 1; 
        // PWM loop will start control immediately
        break;
    }
}

//brief Clears the OLED and displays a new message.
void updateOLED(const char *msg) {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 20);
  display.println(msg);
  display.display();
}