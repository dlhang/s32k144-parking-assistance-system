# S32K144 Parking Assistance System

An embedded parking assistance prototype designed using the NXP S32K144 microcontroller.  
The system measures the distance to nearby objects using an ultrasonic sensor and detects motion using a PIR sensor. Real-time distance data is transmitted through UART for monitoring and debugging.

## System Overview

This project demonstrates sensor interfacing and basic driver usage on the NXP S32K144 platform.  
The system periodically measures object distance using an ultrasonic sensor and detects motion through a PIR sensor, providing visual feedback through an LED and sending distance data via UART.

## Hardware Components

- NXP S32K144 microcontroller (S32K144 EVB)
- SRF05 / HC-SR05 ultrasonic distance sensor
- PIR motion sensor
- LED indicator
- USB-UART interface for serial monitoring

## System Architecture

Ultrasonic Sensor → S32K144 → UART → Serial Monitor  
PIR Sensor → S32K144 → LED Indicator

1. The ultrasonic sensor measures the distance to nearby objects using trigger and echo signals.
2. The S32K144 captures the echo pulse duration to calculate object distance.
3. A PIR sensor detects motion in the environment.
4. Distance data is formatted and transmitted via UART to a serial monitor.
5. The LED indicator shows motion detection status.

## Features

- Ultrasonic distance measurement
- PIR motion detection
- Real-time UART distance monitoring
- LED status indication
- Embedded C implementation using NXP SDK

## Development Environment

- NXP S32 Design Studio
- NXP S32 SDK
- Embedded C programming language

## Possible Improvements

- Add buzzer warning when object is too close
- Implement multi-sensor parking detection
- Add CAN communication for automotive integration
- Display distance on LCD/OLED screen
- Implement filtering for more stable distance measurement
