const int ledPin = 13;
const int buttonPin = 2;

unsigned long previousMillis = 0;
long interval = 1000;
bool ledState = LOW;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    interval = 250;   // fast blink
  } else {
    interval = 1000;  // normal blink
  }

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}
