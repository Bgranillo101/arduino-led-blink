# Arduino LED Blinking Sequence (Multi-LED System)

## Overview
This project demonstrates core embedded systems concepts using an Arduino Uno R3 to control multiple external LEDs. The system has evolved from a basic single-LED blink into an advanced firmware design incorporating **non-blocking timing** and **multi-channel output**.

The project emphasizes safe hardware interfacing, state-based logic, and real-time timing techniques (avoiding `delay()`), serving as a strong foundation for more complex embedded and firmware systems.

---

## Hardware Components
- Arduino Uno R3  
- **3 × LED** (Red, Yellow, Green)  
- **3 × 220 Ω resistor** - Breadboard  
- Jumper wires  
- USB cable  

---

## Circuit Schematic

The following circuit expands the initial design to include three independent LED channels. Each LED is protected by a 220 Ω current-limiting resistor connected to PWM-capable digital pins (9, 10, and 11).

![Arduino LED Circuit Schematic](docs/led_blink4.png)

---


### ASCII Diagram
```text
        Arduino Uno
       ┌───────────┐
 D9  o─┤─[220Ω]─>| LED1 (Red)    ──┐
 D10 o─┤─[220Ω]─>| LED2 (Yellow) ──┼─ GND
 D11 o─┤─[220Ω]─>| LED3 (Green)  ──┘
       └───────────┘
```

---

## Simulation

A live simulation of this multi-LED circuit was created using Autodesk Tinkercad. The simulation allows users to view the circuit, inspect wiring, and observe LED behavior without physical hardware.

🔗 **Tinkercad Circuit Simulation:**  
[Click here to view the simulation](https://www.tinkercad.com/things/erGzwExGLf8-ledblink)

---

## Firmware
```cpp
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
```

---

## Code Explanation

The firmware transitions from simple modulation to a **Finite State Machine (FSM)** approach using time-based triggers to control multiple LEDs efficiently and safely.

### Non-Blocking Timing
By using `millis()`, the code calculates the elapsed time since the last update instead of relying on `delay()`. This prevents the microcontroller from entering a “frozen” state and allows for future expansion (such as reading sensors or handling inputs) without interrupting the LED sequence.

### Array Processing
LED pins are stored in an array, making the design scalable. Adding a fourth or fifth LED only requires updating the `ledPins` array and the `numLEDs` constant—no major logic changes are needed.

### Sequential Logic
The system cycles through the indices of the LED array, turning on one LED at a time. Once the final LED is reached, the index resets to the beginning, creating a clean “chaser” or *Knight Rider–style* effect.

---

## Electrical Considerations

Multiple LEDs are interfaced with the Arduino, each using its own **220 Ω current-limiting resistor** to ensure safe operation.

| Parameter                   | Value        |
|-----------------------------|--------------|
| Total Arduino Current Limit | ~200 mA      |
| Current per Active LED      | ~13–15 mA    |
| Resistor Value              | 220 Ω        |

Because the firmware ensures that **only one LED is active at any given time**, the total current draw remains well within the safe operating limits of the Arduino Uno’s ATmega328P microcontroller.

---

## Testing & Validation

### Test Procedure
1. Assemble the 3-LED circuit on the breadboard.
2. Upload the updated firmware using the Arduino IDE.
3. Verify that only **one LED is lit at any given time**.
4. Measure the timing interval to confirm it matches the **500 ms requirement**.

### Expected Behavior
- LED 1 turns **ON** for 500 ms, then **OFF**
- LED 2 turns **ON** for 500 ms, then **OFF**
- LED 3 turns **ON** for 500 ms, then **OFF**
- The sequence loops back to LED 1

### Results
The LEDs transitioned in a clean, predictable sequence. The use of `millis()` ensures consistent timing while allowing the processor to remain responsive, avoiding blocking delay loops.

---

## Limitations
- **Fixed Sequence:** The LED order is hardcoded in the array.
- **No Input Control:** Timing cannot be adjusted without re-uploading the firmware.
- **Single Pattern:** Only one animation pattern is currently implemented.

---

## Future Improvements
- Implement a true *Knight Rider* (oscillating forward and backward) pattern.
- Integrate a push button to cycle through different animation modes or speeds.
- Add Serial Monitor output to track the current LED state in real time.

---

## Skills Demonstrated
- **Non-Blocking Firmware Design:** Implementing timing logic using `millis()`
- **Data Structures:** Using arrays to manage hardware pin assignments
- **Multi-Channel Hardware Interfacing:** Managing multiple I/O paths simultaneously
- **State Logic:** Creating sequential execution patterns
- **Scalable Code Architecture:** Writing modular, extensible firmware
- **Professional Technical Documentation:** Using Markdown for clear project communication
