# Flood Monitoring System with SMS Alert

An Arduino-based flood monitoring system designed to monitor water levels in real time and provide early warnings through visual, audible, and SMS alerts.

## Overview

The system uses an HC-SR04 ultrasonic sensor and a float sensor to monitor the water level. Arduino UNO processes the sensor readings and compares them with predefined thresholds.

When the water level reaches a critical threshold:
- The 16x2 LCD displays the water level/status.
- The buzzer provides an audible warning.
- The GSM SIM800L module sends an SMS alert.

## Components Used

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Float Sensor
- 16x2 LCD Display
- Buzzer
- GSM SIM800L Module
- 4x4 PCB

## Working

1. The ultrasonic sensor measures the distance between the sensor and the water surface.
2. The float sensor provides an additional water-level trigger.
3. Arduino UNO processes the sensor data.
4. The readings are compared with predefined threshold levels.
5. The LCD displays the current water-level status.
6. When the danger threshold is reached, the buzzer is activated.
7. The GSM SIM800L sends an SMS alert to the concerned person.

## Technologies Used

- Arduino
- Embedded C
- Ultrasonic Sensing
- GSM Communication
- LCD Interfacing
- Sensor Interfacing

## Project Status

Completed
