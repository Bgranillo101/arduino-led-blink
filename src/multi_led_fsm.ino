const int ledPins[] = {9, 10, 11}; // Array of LED pins
const int numLEDs = 3;
unsigned long previousMillis = 0;
int currentLED = 0;
const long interval = 500; // Sequence speed in ms

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();

  // Non-blocking timing check
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // Turn off all LEDs (Reset state)
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // Turn on the current LED in the sequence
    digitalWrite(ledPins[currentLED], HIGH);

    // Increment index and wrap around
    currentLED++;
    if (currentLED >= numLEDs) {
      currentLED = 0;
    }
  }
}
