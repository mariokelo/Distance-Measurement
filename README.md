# Distance Measurement Sensor

An ultrasonic distance sensor that displays real-time measurements on
a 16x2 LCD screen with a visual proximity alert system using green and
red LEDs.

## How it works

An HC-SR04 ultrasonic sensor fires a 10µs pulse and measures the
time it takes for the echo to return. That duration is converted to
centimeters using the speed of sound.

The result is shown on an I2C LCD display and also printed to Serial.
A two-LED indicator gives instant visual feedback on proximity:

- **Green LED on** — object is more than 10 cm away (safe)
- **Red LED blinking** — object is within 10 cm, with blink speed
  increasing as the object gets closer

## Hardware

- Arduino (Uno or compatible)
- HC-SR04 ultrasonic sensor
- 16x2 I2C LCD display (address `0x27`)
- Green LED + resistor
- Red LED + resistor
- Connecting wires / breadboard

## Wiring

| Component       | Arduino Pin |
|-----------------|-------------|
| Ultrasonic TRIG | D7          |
| Ultrasonic ECHO | D8          |
| Red LED         | D9          |
| Green LED       | D10         |
| LCD SDA         | A4          |
| LCD SCL         | A5          |

> Use a 220Ω resistor in series with each LED to limit current.

## LED behavior

| Distance     | Green LED | Red LED         |
|--------------|-----------|-----------------|
| > 10 cm      | ON        | OFF             |
| 6 – 10 cm    | OFF       | Slow blink      |
| 0 – 5 cm     | OFF       | Fast blink      |

Blink speed is mapped proportionally — at 10 cm the interval is
500 ms, at 0 cm it drops to 50 ms.

## Serial output

With Serial Monitor open at **9600 baud**:

```
Distance: 42 cm
Distance: 41 cm
Distance: 9 cm
```

## Dependencies
Must install via the Arduino Library Manager:
- [LiquidCrystal I2C](https://github.com/johnrickman/LiquidCrystal_I2C)
