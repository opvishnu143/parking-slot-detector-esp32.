# parking-slot-detector-esp32.
# Smart Parking Slot Detector (ESP32)

## Problem
Drivers in a mall cellar waste time searching for free parking slots.

## What it does
Monitors two parking slots (A1, A2). An LCD shows each slot's status, an LED turns off when a slot is occupied, and a buzzer sounds when both slots are full.

## Hardware
- ESP32 DevKit
- 2 push buttons (stand-in for IR proximity sensors)
- 2 LEDs
- Buzzer
- 16x2 I2C LCD

## How it works
Each slot is read as a digital input. LOW means occupied, HIGH means free. The ESP32 updates the LCD, LEDs, and buzzer every 500 ms.

## Simulation
Built and tested in Wokwi: [your Wokwi link]
Demo video: [your video link]

## Challenges
- Pin conflicts between the I2C LCD and other parts. Solved by moving the LCD to GPIO 19 (SDA) and GPIO 22 (SCL).
- The ESP32's "CLK" label is an internal flash pin, not a usable GPIO.
- A button wired on both sides shorted the signal. Fixed by wiring one side to GND and the other to the GPIO.

## What I learned
Digital input reading, pull-up resistors, I2C display setup, and debugging wiring with the Serial Monitor.

## Next steps
- Replace push buttons with real IR proximity sensors
- Add fire and gas sensors with an alarm
- Test on real ESP32 hardware
- Explore Bluetooth (BLE) to send slot status to a phone

## Note on test mode
The demo video used a test flag that sounds the buzzer when either slot is full, so one button could trigger it. The final code uses the rule: buzzer only when both are full.
