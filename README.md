# S32K144 Smart Parking Assistance System - Version 2.0

## Project Overview
This repository contains the embedded software for a vehicle parking assistance system developed on the NXP S32K144 microcontroller. The system integrates ultrasonic distance measurement (SRF05) and motion detection (PIR) to provide real-time proximity monitoring via UART telemetry.

## Technical Specifications
- **Microcontroller:** NXP S32K144 (Arm Cortex-M4F)
- **Development Environment:** S32 Design Studio for S32 Platform
- **SDK Version:** S32K144_SDK_gcc_RTM_3.0.0
- **Peripherals:** - LPUART1 (Data Transmission)
  - PORT/GPIO (Sensor Interfacing)
  - FTM/LPIT (Timing Management)

## Current Status and Implementation (v0.7)
The project is currently at 70% completion, focusing on stable peripheral communication and initial sensor integration.

### System Stability Challenges
The development process is currently addressing several stability factors to reach 100% reliability:
- **UART Communication:** Successfully implemented and stable for data monitoring.
- **PIR Sensor Stability:** Investigating false triggers caused by EMI (Electromagnetic Interference) and software-based debounce logic.
- **SRF05 Accuracy:** Analyzing signal jitter and optimizing trigger/echo timing to improve distance measurement precision.
- **Sensitivity Calibration:** Testing hardware sensitivity settings and software thresholds for optimal detection range.

### Version Control Strategy
This project underwent a structural recovery after a metadata corruption event.
- **Main Branch:** Current working version with restored IDE compatibility.
- **Old-version Branch:** Preserved as a technical archive for troubleshooting and legacy analysis of initial configuration errors.

## Installation and Deployment
1. Clone the repository.
2. Open S32 Design Studio.
3. Select `File -> Import -> General -> Existing Projects into Workspace`.
4. Point to the project directory and click Finish.
5. Open the `.mex` configuration file and click `Update Code` to synchronize drivers.
6. Build and Flash the `.elf` binary to the S32K144 Evaluation Board.

## Development Roadmap
- Implement software filters to reduce SRF05 signal jitter.
- Refine PIR detection logic to eliminate false positives.
- Finalize system integration and responsiveness.