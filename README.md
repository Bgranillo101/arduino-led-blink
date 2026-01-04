# Arduino LED Blinking Sequence (External LED)

## Overview
This project demonstrates fundamental embedded systems concepts using an Arduino Uno R3 to control an external LED through a 220 Ω current-limiting resistor. The firmware toggles a digital output pin at fixed one-second intervals, introducing microcontroller I/O configuration, timing control, and safe hardware interfacing.

This project serves as a foundational exercise for more advanced embedded systems, firmware, and hardware-software integration work.

---

## Hardware Components
- Arduino Uno R3  
- 1 × LED  
- 1 × 220 Ω resistor  
- Breadboard  
- Jumper wires  
- USB cable  

---

## Circuit Schematic

The following schematic was created using Autodesk Tinkercad and represents the external LED circuit with a 220 Ω current-limiting resistor connected to digital pin 13 of the Arduino Uno.

![Arduino LED Circuit Schematic](docs/led_blink_schematic.png)

---

## Simulation

A live simulation of this circuit was created using Autodesk Tinkercad. The simulation allows users to view the circuit, inspect wiring, and observe LED behavior without physical hardware.

🔗 **Tinkercad Circuit Simulation:**  
[Click here to view the simulation](https://www.tinkercad.com/things/erGzwExGLf8-ledblink)

---

## Firmware
```cpp
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
```

---

## Code Explanation

The firmware is written using the Arduino framework and follows the standard `setup()` and `loop()` execution model.

- `setup()` runs once when the microcontroller powers on or resets. In this function, digital pin 13 is configured as an output using `pinMode()`.
- `loop()` executes continuously after initialization. The program sets pin 13 HIGH to turn the LED on, waits for 1000 milliseconds, sets the pin LOW to turn the LED off, and waits another 1000 milliseconds before repeating.

This structure demonstrates basic digital output control and timing behavior on a microcontroller.

---

## Electrical Considerations

An external LED was connected to the Arduino through a 220 Ω current-limiting resistor to prevent excessive current draw and protect both the LED and the microcontroller.

- Arduino output voltage: 5 V  
- Typical LED forward voltage: ~2.0 V  
- Resistor value: 220 Ω  

Using Ohm’s Law, the circuit limits current to approximately 13–15 mA, which is within the safe operating range for standard LEDs and Arduino I/O pins.

---

## Testing & Validation

### Test Procedure
1. Assemble the LED and resistor circuit according to the schematic
2. Upload the firmware to the Arduino Uno using the Arduino IDE
3. Power the board via USB
4. Observe LED behavior

### Expected Behavior
- LED turns ON for 1 second
- LED turns OFF for 1 second
- Pattern repeats continuously

### Results
The LED blinked consistently at the expected interval with no abnormal behavior, confirming correct firmware operation and hardware wiring.

---

## Limitations

- The program uses blocking delays (`delay()`), which prevents the microcontroller from performing other tasks concurrently
- The blink interval is fixed and cannot be changed at runtime
- No input or feedback mechanisms are implemented

These limitations are acceptable for a foundational project, but would need to be addressed in more advanced embedded systems applications.

---

## Future Improvements

- Replace blocking delays with non-blocking timing using `millis()`
- Add a push button to allow user control of the blink rate
- Implement PWM to control LED brightness
- Expand to multiple LEDs with different timing patterns
- Add serial output for debugging and runtime monitoring

---

## Skills Demonstrated

- Embedded C/C++ programming
- Microcontroller digital I/O configuration
- Safe hardware interfacing using current-limiting resistors
- Timing and control logic
- Breadboard prototyping
- Firmware deployment and debugging
- Technical documentation using Markdown
