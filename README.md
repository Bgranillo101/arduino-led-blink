# arduino-led-blink
Arduino LED blinking project using an external LED and a 220Ω resistor.


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

### ASCII Diagram

  Arduino Uno
 ┌───────────┐
 │           │
 │     D13 o─┼────[220Ω]────>|───── GND
 │           │               LED
 └───────────┘


### Connection Table

| Arduino Pin | Connection |
|------------|------------|
| D13 | 220 Ω resistor |
| Resistor | LED anode (long leg) |
| LED cathode (short leg) | GND |

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
