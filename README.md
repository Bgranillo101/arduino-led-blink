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

The following schematic was created using Autodesk Tinkercad and represents the external LED circuit with a 220 Ω current-limiting resistor connected to digital pin 13 of the Arduino Uno.

![Arduino LED Circuit Schematic](docs/led_blink_schematic.png)


## Simulation

A live simulation of this circuit was created using Autodesk Tinkercad. The simulation allows users to view the circuit, inspect wiring, and observe LED behavior without physical hardware.

🔗 **Tinkercad Circuit Simulation:**  
[Click here to view the simulation](https://www.tinkercad.com/things/erGzwExGLf8-ledblink)


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
