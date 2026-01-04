const int ledPins[] = {9, 10, 11};
const int numLEDs = 3;
unsigned long previousMillis = 0;
int currentLED = 0;
const long interval = 500;

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    // Turn off all LEDs
    for (int i = 0; i < numLEDs; i++) {
      digitalWrite(ledPins[i], LOW);
    }
    // Turn on the current LED
    digitalWrite(ledPins[currentLED], HIGH);

    // Move to next LED
    currentLED++;
    if (currentLED >= numLEDs) currentLED = 0;
  }
}
