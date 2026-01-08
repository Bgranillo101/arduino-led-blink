// ===============================
// Optional Debug Configuration
// ===============================
#define DEBUG 1   // Change to 0 to disable serial debugging

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

// ===============================
// State Variables
// ===============================
int currentLED = 0;

void setup() {
#if DEBUG
  Serial.begin(9600);
  Serial.println("Serial debugging enabled");
#endif

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

#if DEBUG
    Serial.print("Active LED index: ");
    Serial.print(currentLED);
    Serial.print(" | Pin: ");
    Serial.println(ledPins[currentLED]);
#endif

    // Move to next LED
    currentLED++;
    if (currentLED >= numLEDs) {
      currentLED = 0;
    }
  }
}
