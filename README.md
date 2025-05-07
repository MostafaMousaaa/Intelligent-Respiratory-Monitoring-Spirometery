# 🫁 Arduino-based Digital Spirometer

https://github.com/user-attachments/assets/9213ecd2-90bc-4221-8fc7-90098d8d4f6e


<div align="center">

*An affordable and accessible digital spirometer solution using Arduino for respiratory function analysis.*

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![Status: Prototype](https://img.shields.io/badge/Status-Prototype-orange)](https://github.com/MostafaMousaaa/Intelligent-Respiratory-Monitoring-Spirometery)

</div>

## 📋 Table of Contents

- [🌟 Overview](#-overview)
- [🎬 Demonstration](#-demonstration)
- [✨ Features](#-features)
- [📊 Clinical Significance](#-clinical-significance)
- [🛠️ Components Required](#-components-required)
- [⚙️ How It Works](#️-how-it-works)

## 🌟 Overview

This project presents an Arduino-based digital spirometer designed for measuring key lung function parameters. It aims to provide an accessible and cost-effective tool for preliminary respiratory assessment. The system captures and analyzes expiratory airflow to determine vital pulmonary metrics.

## 🎬 Demonstration

<div align="center">
  <p>
    <img src="https://github.com/MostafaMousaaa/Intelligent-Respiratory-Monitoring-Spirometery/blob/main/Img.png" alt="Demonstration Video Screenshot" width="600"/>
  </p>
  <p>
    <video width="600" controls>
       https://github.com/user-attachments/assets/9213ecd2-90bc-4221-8fc7-90098d8d4f6e
       
    
  </p>
</div>

## ✨ Features

-   **Real-time Flow Rate Measurement**: Captures instantaneous airflow during exhalation.
-   **Forced Vital Capacity (FVC)**: Measures the total volume of air exhaled forcefully.
-   **Forced Expiratory Volume in 1 Second (FEV1)**: Measures the volume of air exhaled in the first second of forced expiration.
-   **FEV1/FVC Ratio Calculation**: Provides a critical clinical indicator for assessing respiratory health and identifying potential obstructive or restrictive patterns.
-   **User-Friendly Interface**: Utilizes a 16x2 LCD for displaying results and test status.
-   **Auditory and Visual Feedback**: Incorporates LEDs and a buzzer for test guidance and completion signals.
-   **Serial Data Output**: Allows for detailed data logging and analysis via the serial monitor.
-   **Portable and Low-Cost**: Built with readily available and affordable components.

## 📊 Clinical Significance

The FEV1/FVC ratio helps in diagnosing:

| Condition | Typical FEV1/FVC Ratio |
|-----------|------------------------|
| Normal | > 70-80% |
| Obstructive (e.g., COPD, asthma) | < 70% |
| Restrictive (e.g., pulmonary fibrosis) | Normal or increased (`≥ 70-80%`, but with reduced FVC and FEV1) |

*Note: These are general guidelines. Clinical diagnosis should always be made by a qualified healthcare professional.*

## 🛠️ Components Required

| Component                                  | Quantity | Notes                                                                 |
|--------------------------------------------|----------|-----------------------------------------------------------------------|
| Arduino Uno/Nano (or compatible)           | 1        | Microcontroller                                                       |
| Flow Sensor (e.g., YF-S201)                | 1        | Pulse output type                                                     |
| 16x2 LCD Display                           | 1        | I2C module recommended for simpler wiring                             |
| Green LED                                  | 1        | For test readiness/completion indication                              |
| Red LED                                    | 1        | For test in progress/error indication                                 |
| Buzzer (5V)                                | 1        | Auditory feedback                                                     |
| Pushbutton (momentary)                     | 1        | Test initiation                                                       |
| Resistors (220Ω)                           | 2+       | Current limiting for LEDs (adjust as needed)                          |
| Resistors (10kΩ)                           | 1 (opt)  | For pushbutton pulldown (if not using internal pull-up)             |
| Breadboard                                 | 1        | Prototyping                                                           |
| Jumper Wires                               | Several  | Connections                                                           |
| Disposable Mouthpiece                      | Several  | Ensure hygienic use                                                   |
| Power Supply for Arduino                   | 1        | USB or external                                                       |

## ⚙️ How It Works

The spirometer operates based on the principle of measuring airflow during a forced exhalation:

1.  **Initialization**: Upon startup, the system initializes the LCD, sensors, and awaits user input.
2.  **Test Initiation**: The user presses a pushbutton to start the spirometry test.
3.  **Exhalation Detection**: The system monitors the flow sensor. Once airflow is detected (start of exhalation), the measurement process begins.
4.  **Flow Rate Measurement**: The flow sensor generates electrical pulses proportional to the rate of airflow. The Arduino counts these pulses over short intervals (e.g., 250ms) to calculate the instantaneous flow rate (Liters/minute or Liters/second).
5.  **Volume Calculation**: The calculated flow rate is integrated over time to determine the cumulative volume of air exhaled (in milliliters or Liters).
    `Volume = Flow Rate × Time Interval`
6.  **FEV1 Recording**: The system precisely records the total volume exhaled at the 1-second mark from the start of exhalation. This is the FEV1.
7.  **Test Duration**: The test continues for a predefined duration (typically 6 seconds, as per ATS guidelines for FVC).
8.  **FVC Recording**: At the end of the 6-second exhalation period, the total accumulated volume is recorded as the FVC.
9.  **Ratio Calculation**: The FEV1/FVC ratio is calculated: `Ratio = (FEV1 / FVC) * 100%`.
10. **Results Display**: Key parameters (FVC, FEV1, FEV1/FVC ratio) are displayed on the LCD and sent to the serial monitor.
11. **Feedback**: Visual (LEDs) and auditory (buzzer) cues guide the user through the test (e.g., start, ongoing, end).

---

<div align="center">
  <p>Developed as part of the Medical Equipment Course | SBME 2026</p>
  <p>
-   Mostafa Mousa
-   Amaar Yasser
-   Ahmed Adeil
-   Zeyad Wael
-   Hussein Mohamed</p>
</div>
