# 🫁 Arduino-based Digital Spirometer

<div align="center">
  

*An affordable digital spirometer solution using Arduino*

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![Status: Prototype](https://img.shields.io/badge/Status-Prototype-orange)](https://github.com/yourusername/arduino-spirometer)

</div>

## 📋 Overview

This project implements a digital spirometer using Arduino for measuring and analyzing lung function. It captures important pulmonary metrics including:

- **Flow Rate**: Real-time measurement of airflow during exhalation
- **Volume**: Total exhaled volume (FVC - Forced Vital Capacity)
- **FEV1**: Forced Expiratory Volume in the first second
- **FEV1/FVC Ratio**: An important clinical indicator of respiratory health

<div align="center">
  <p>
    <a href="https://github.com/MostafaMousaaa/Intelligent-Respiratory-Monitoring-Spirometery/blob/main/spirovideo.mp4">
      <img src="https://github.com/MostafaMousaaa/Intelligent-Respiratory-Monitoring-Spirometery/blob/main/Img.png" alt="Demonstration Video" width="600"/>
    </a><br>
    <i>Click to watch the demonstration video</i>
  </p>
</div>

## 🔧 Components

- Arduino Uno/Nano
- Flow sensor with pulse output
- 16x2 LCD display
- LEDs (green and red for visual feedback)
- Buzzer for audio feedback
- Pushbutton for test initiation
- Mouthpiece (with hygienic considerations)

## ⚙️ How It Works

The spirometer measures airflow during exhalation using a flow sensor that generates pulses proportional to the flow rate. The built-in algorithm:

1. Detects the start of exhalation
2. Measures flow rate in real-time 
3. Calculates cumulative volume
4. Records FEV1 at exactly 1 second
5. Completes the test after 6 seconds
6. Calculates the FEV1/FVC ratio
7. Provides visual and auditory feedback

## 📊 Clinical Significance

The FEV1/FVC ratio helps in diagnosing:

| Condition | Typical FEV1/FVC Ratio |
|-----------|------------------------|
| Normal | > 70-80% |
| Obstructive (e.g., COPD, asthma) | < 70% |
| Restrictive (e.g., pulmonary fibrosis) | Normal or increased |

## 🚀 Getting Started

1. Connect the hardware components according to the pin configuration in the code
2. Upload the code to your Arduino board
3. Open serial monitor at 9600 baud rate for detailed readings
4. Press the button to initiate the test
5. Exhale forcefully through the mouthpiece for at least 6 seconds
6. Read the results on the LCD display and serial monitor

## 📜 Code Highlights

```c
// Flow rate calculation
flowRate = (pulseCount / calibrationFactor) * (1000.0 / 250.0);

// FEV1 recording at exactly 1 second
if (!fev1_recorded && (elapsed >= 1000)) {
  fev1_volume = totalMilliLitres;
  fev1_recorded = true;
}

// FEV1/FVC ratio calculation
float ratio = (fvc > 0) ? (fev1 / fvc) * 100.0 : 0;
```

## 📝 Notes

- For accurate results, maintain proper posture and seal lips tightly around the mouthpiece
- Clean and sanitize the mouthpiece between users
- Calibration may be required for precise measurements

## 📚 References

- American Thoracic Society guidelines for spirometry
- Miller MR, et al. Standardisation of spirometry. Eur Respir J. 2005;26(2):319-38

---

<div align="center">
  <p>Developed as part of Medical Equipment Course | SBME 2023</p>
</div>
