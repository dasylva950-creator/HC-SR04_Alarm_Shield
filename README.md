# HC-SR04\_Alarm\_Shield

An Arduino UNO R3 proximity alarm shield with a custom KiCAD PCB layout



HC-SR04 Ultrasonic Alarm Shield



A custom Arduino Uno R3 shield that triggers an audible and visual alarm when an object enters a 50-centimeter threshold. This project combines embedded C++ programming, ultrasonic sensor integration, and a custom PCB designed in KiCad.



Features:

Precision Tracking: Uses the HC-SR04 ultrasonic sensor to calculate real-time distance.

Dual Alert System: Triggers a high-output active buzzer and a bright red LED simultaneously.

Custom Shield Form Factor: Designed to plug directly onto an Arduino Uno R3 without messy jumper wires.

Safety Threshold: Hardcoded 50cm boundary zone for immediate proximity alerts.



Hardware Components:

Microcontroller: Arduino Uno R3

Sensor: HC-SR04 Ultrasonic Distance Sensor

Indicators: 1x Active Buzzer, 1x Red LED

Passives: 1x 220Ω Resistor (for LED protection)

PCB: Custom designed dual-layer board



Pin Mapping:





VCC: Connect to the 5V pin on the Arduino.

Trig: Connect to digital Pin 9.

Echo: Connect to digital Pin 10.

GND: Connect to any GND pin on the Arduino.

Buzzer / LED (Positive): Connect to digital Pin 13 (through a 220Ω resistor for LEDs).

Buzzer / LED (Negative): Connect to GND



Software \& Engineering Challenges

The coding phase was the most challenging aspect of this project. Specifically, managing the precise timing required by the HC-SR04 sensor and handling signal bouncing issues required significant troubleshooting. 



How I Solved It:

1\. Pulse Timing: I utilized the `pulseIn()` function to accurately measure the microsecond travel time of the sound wave, converting it to centimeters using the speed of sound formula: `Distance = (Time \* 0.0343) / 2`.

2\. Logic Optimization: I implemented a strict conditional threshold check to prevent the buzzer and LED from lagging or stuttering when an object hovers exactly at the 50cm line.



Gallery \& Design Files



PCB Layout (KiCad)

\[KiCad PCB Layout](images/pcb\_layout.png)

Figure 1: 2D/3D render of the custom shield designed in KiCad.



You can prototype this project on a breadboard. 



Installation \& Usage

1\. Clone this repository:

&#x20;  ```bash

&#x20;  git clone https://github.com

&#x20;  ```

2\. Open `src/YOUR\_CODE\_FILE\_NAME.ino` in the Arduino IDE.

3\. Connect your Arduino Uno R3 via USB.

4\. Select Tools > Board > Arduino Uno\*\* and the correct COM port.

5\. Click Upload.



