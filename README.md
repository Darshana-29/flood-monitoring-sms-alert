# Flood Monitoring System with SMS Alert

An Arduino-based flood monitoring system that monitors rising water levels using an ultrasonic sensor and float sensor and provides real-time visual, audible, and mobile alerts when the water level crosses a predefined threshold.

## Overview

The system uses Arduino UNO as the main controller. An HC-SR04 ultrasonic sensor is placed above the water container to measure the distance between the sensor and the water surface, while a float sensor is placed inside the container to detect the presence and rise of water.

The sensor readings are processed by Arduino and compared with a predefined threshold level. When the water level crosses the threshold, the system activates a buzzer and LED, displays the alert status on a 16x2 LCD, and provides a mobile alert through email and alarm notification.

## Components Used

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- Float Sensor
- 16x2 LCD Display
- Buzzer
- LED
- GSM SIM800L Module
- 4x4 PCB

## Working

1. The ultrasonic sensor measures the distance between the sensor and the water surface.
2. The float sensor detects the presence and rise of water.
3. Arduino UNO processes the sensor readings.
4. The readings are compared with a predefined threshold level.
5. When the water level crosses the threshold, the buzzer and LED are activated.
6. The 16x2 LCD displays the water-level and flood-alert status.
7. A mobile alert is provided through email and alarm notification.

## Technologies Used

- Arduino UNO
- Embedded C / Arduino Programming
- Ultrasonic Sensor Interfacing
- Float Sensor Interfacing
- LCD Interfacing
- Digital Output Control

## Applications

- Flood-prone areas
- Water-level monitoring
- Early warning systems
- Water storage and monitoring
- Disaster management

## Advantages

- Low-cost implementation
- Real-time water-level monitoring
- Multiple sensing methods
- Visual and audible alerts
- Mobile notification capability
- Easy to modify and extend

## Future Scope

- Reliable GSM/SMS communication
- IoT-based remote monitoring
- Mobile application integration
- Cloud-based data logging
- Weather and rainfall data integration
- Machine-learning-based flood prediction

## Project Status

Completed

The prototype successfully demonstrates water-level monitoring, threshold-based flood detection, LCD display, buzzer and LED alerts, and mobile notifications.

## Project Prototype

![Flood Monitoring Prototype](flood%20monitoring%20image.jpeg)
