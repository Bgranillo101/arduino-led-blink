// ===============================
// Optional Debug Configuration 
// DEBUG 1 is on   DEBUG 0 off
// ===============================
#define DEBUG 1 

// ===============================
// State Machine Definition
// ===============================
enum State {
  LED1_ON,
  LED2_ON,
  LED3_ON
};

State currentState = LED1_ON; // Initialize to first state

// ===============================
// Hardware Configuration
// ===============================
const int ledPins[] = {9, 10, 11};
const int numLEDs = 3;

// ===============================
// Timing Variables
// ===============================
unsigned long previousMillis = 0;
const long interval = 500;

void setup() {
#if DEBUG
  Serial.begin(9600);
  Serial.println("System Initialized: State Machine Active");
#endif

  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // 1. Turn off all LEDs before switching states
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // 2. State Machine Logic
    switch (currentState) {
      case LED1_ON:
        digitalWrite(ledPins[0], HIGH);
        logState("LED 1 (Pin 9)");
        currentState = LED2_ON; // Transition
        break;

      case LED2_ON:
        digitalWrite(ledPins[1], HIGH);
        logState("LED 2 (Pin 10)");
        currentState = LED3_ON; // Transition
        break;

      case LED3_ON:
        digitalWrite(ledPins[2], HIGH);
        logState("LED 3 (Pin 11)");
        currentState = LED1_ON; // Loop back
        break;
    }
  }
}

// Helper function for clean serial output
void logState(String label) {
#if DEBUG
  Serial.print("Current State: ");
  Serial.println(label);
#endif
}
