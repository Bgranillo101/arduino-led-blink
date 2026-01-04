# Arduino LED Blinking Sequence (External LED)

## Overview
This project demonstrates core embedded systems concepts using an Arduino Uno R3 to control an external LED through a 220 Ω current-limiting resistor. The system evolved from a basic LED blink into a more advanced firmware design incorporating non-blocking timing and PWM-based brightness control.

The project emphasizes safe hardware interfacing, real-time timing techniques, and microcontroller-based signal modulation, serving as a strong foundation for more complex embedded and firmware systems.

---

## Hardware Components
- Arduino Uno R3  
- 3 × LED  
- 3 × 220 Ω resistor  
- Breadboard  
- Jumper wires  
- USB cable  

---

## Circuit Schematic

The following schematic was created using Autodesk Tinkercad and represents the external LED circuit with a 220 Ω current-limiting resistor connected to digital pin 13 of the Arduino Uno, as well as a push button connected to pin 2 for blink rate control.

![Arduino LED Circuit Schematic](docs/led_blink3.png)

---

## Simulation

A live simulation of this circuit was created using Autodesk Tinkercad. The simulation allows users to view the circuit, inspect wiring, and observe LED behavior without physical hardware.

🔗 **Tinkercad Circuit Simulation:**  
[Click here to view the simulation](https://www.tinkercad.com/things/erGzwExGLf8-ledblink)

---

## Firmware
```cpp
const int ledPin = 9;   // PWM-capable pin
int brightness = 0;
int fadeAmount = 5;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  analogWrite(ledPin, brightness);
  brightness += fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(30);
}
```

---

## Code Explanation

## Code Explanation
The firmware uses **Pulse Width Modulation (PWM)** to control LED brightness rather than a simple ON/OFF digital output.

* **Pin Configuration:** The LED is connected to digital pin 9, which supports hardware PWM.
* **Signal Generation:** `analogWrite()` outputs a PWM signal with a duty cycle proportional to the brightness value (0–255).
* **Logic Flow:** The brightness value is incremented or decremented on each loop iteration, creating a smooth fade effect.
* **Direction Control:** When the brightness reaches its minimum or maximum value, the direction of change is reversed.
* **Core Concept:** This implementation demonstrates basic PWM control and signal modulation on a microcontroller.

---

## Electrical Considerations
An external LED is interfaced with the Arduino through a **220 Ω current-limiting resistor** to ensure safe operation.

| Parameter | Value |
| :--- | :--- |
| **Arduino Output Voltage** | 5 V |
| **Typical LED Forward Voltage** | ~2.0 V |
| **Resistor Value** | 220 Ω |

The resistor limits current to approximately **13–15 mA**, keeping both the LED and the microcontroller’s I/O pin within safe operating limits. PWM varies perceived brightness by adjusting duty cycle rather than voltage level.

---

## Testing & Validation

### Test Procedure
1.  Assemble the LED and resistor circuit according to the schematic.
2.  Upload the firmware to the Arduino Uno using the Arduino IDE.
3.  Power the board via USB.
4.  Observe LED brightness behavior.

### Expected Behavior
* LED brightness gradually increases from OFF to full brightness.
* LED brightness then gradually decreases back to OFF.
* The fade pattern repeats continuously.

### Results
The LED brightness transitioned smoothly with no flickering or instability, confirming correct PWM output and proper hardware wiring.

---

## Limitations
* **Timing:** PWM implementation currently uses a blocking `delay()` for fade timing.
* **Flexibility:** Brightness transition rate is fixed in firmware.
* **Control:** No external input or runtime configuration is implemented.

> These limitations are acceptable for demonstrating PWM fundamentals but would be addressed in more advanced embedded designs.

---

## Future Improvements
 
* Implement a finite state machine for structured LED behavior.
* Add serial output for debugging and real-time monitoring.

---

## Skills Demonstrated

* **Embedded C/C++ programming**
* **Microcontroller digital I/O and PWM configuration**
* **Safe hardware interfacing using current-limiting resistors**
* **Signal modulation and timing control**
* **Breadboard prototyping**
* **Firmware testing and validation**
* **Professional technical documentation using Markdown**
