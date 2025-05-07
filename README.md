# Electronic Spirometer Project

![Version](https://img.shields.io/badge/version-1.0-blue)
![License](https://img.shields.io/badge/license-MIT-green)

## Overview
This project implements an Arduino-based electronic spirometer that measures key lung function parameters including FVC (Forced Vital Capacity), FEV1 (Forced Expiratory Volume in 1 second), and calculates the FEV1/FVC ratio.

## Table of Contents
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [How It Works](#how-it-works)
- [Installation](#installation)
- [Clinical Significance](#clinical-significance)
- [Interpreting Results](#interpreting-results)
- [Troubleshooting](#troubleshooting)
- [References](#references)

## Components
- Arduino board
- Flow sensor (connected to pin 2)
- Button (connected to pin 3)
- Red LED (connected to pin 6)
- Green LED (connected to pin 7)
- Buzzer (connected to pin 8)
- Connecting wires

## Circuit Diagram

## How It Works
1. Press the button to prepare the device for a test
2. The red LED will flash and a short beep will sound to indicate readiness
3. Exhale forcefully into the flow sensor
4. The device will measure airflow for 6 seconds
5. When measurement completes, the green LED lights up and a confirmation beep sounds
6. Results (FVC, FEV1, and FEV1/FVC ratio) are displayed in the serial monitor
7. System resets after 2 seconds of no flow, ready for the next test

## Installation

## Clinical Significance
- **FVC**: Total volume of air that can be forcibly exhaled
- **FEV1**: Volume of air exhaled in the first second
- **FEV1/FVC Ratio**: Important diagnostic indicator for obstructive and restrictive lung diseases
  - Normal values: 70-80% or higher
  - Lower values may indicate obstructive diseases (asthma, COPD)

## Interpreting Results

## Troubleshooting

## References
