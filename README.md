# MEC830_Lab2
Lab 2 code for MEC 830

This lab has two tasks to it.

1. Ultrasonic Sensor and Tilt Switch
2. HD44780 LCD 16x2

## Part 1: Ultrasonic Sensor and LCD
Testing two parts: The 16x2 Liquid Crystal Display
This is controlled using the LiquidCrystal library, which is pre-installed.
It works by connecting the RS (reset), RW (read/write), en (enable) control pins to the Arduino
Digital LCD pins d4, d5, d6, d7 must also be connected. 
There is a mode in the LCD module that requires usage of all 8 digital pins from d0 to d7. But there's no need to use that here.
Note: For the Arduino Nano, pins A6 and A7 cannot be used as digital outputs. Otherwise, all the other pins are free for use.

The Ultrasonic sensor is based on the HC-SR04 chip which is present on the board. It handles all of the complex stuff going on inside the board.
The arduino needs only to send a 10 us pulse to the TRIG pin on the module to begin the distance check.
Reading the ECHO pin on the arduino using a built-in function pulseIn() gives a pulse certain pulse width in microseconds.
The calculation to calculate the distance between sensor and object is to use half that pulse width and the speed of sound in air at the appropriate temperature.
The speed of sound in air at 25°C is 346.3 m/s. Doing the calculations gives:
Speed = Distance / Time
Distance = (346.3 m/s) * pulseIn() (us) * (1000000 us/s) * 100 (cm/m) / (2)
**Distance = pulseIn()/57.753** (at 25°C)
I decided to display the distance value right on the LCD because why not?

## Part 2: Tilt Sensor
This part asks essentially verify that the sensor works.
Extremely trivial. A tilt sensor is a cylinder with a metal ball inside it. If the sensor is upright, the ball is at the bottom and shorts the two leads of the sensor together. But if the sensor is lopsided, the ball does not allow the two leads to make electrical contact.
In the arduino code, it is as simple as writing the sensor's read value as the LED state.
