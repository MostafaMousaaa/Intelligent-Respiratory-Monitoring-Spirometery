# 🫁 Arduino-based Digital Spirometer

<div align="center">

*An affordable and accessible digital spirometer solution using Arduino for respiratory function analysis.*

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=flat&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![Status: Prototype](https://img.shields.io/badge/Status-Prototype-orange)](https://github.com/MostafaMousaaa/Intelligent-Respiratory-Monitoring-Spirometery)

</div>

## 📋 Table of Contents

- [Overview](#-overview)
- [Features](#-features)
- [Clinical Significance](#-clinical-significance)
- [Components Required](#-components-required)
- [Hardware Setup](#-hardware-setup)
- [Software Setup](#-software-setup)
- [How It Works](#️-how-it-works)
- [Getting Started](#-getting-started)
- [Code Highlights](#-code-highlights)
- [Demonstration](#-demonstration)
- [Important Considerations](#-important-considerations)
- [Future Enhancements](#-future-enhancements)
- [Contributing](#-contributing)
- [License](#-license)
- [References](#-references)
- [Disclaimer](#-disclaimer)

## 🌟 Overview

This project presents an Arduino-based digital spirometer designed for measuring key lung function parameters. It aims to provide an accessible and cost-effective tool for preliminary respiratory assessment. The system captures and analyzes expiratory airflow to determine vital pulmonary metrics.

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

-   Arduino Uno/Nano (or compatible microcontroller)
-   Flow sensor (e.g., YF-S201 or similar, with pulse output)
-   16x2 LCD Display (with I2C module recommended for simpler wiring)
-   LEDs:
    -   1 x Green LED (for indicating test readiness/completion)
    -   1 x Red LED (for indicating test in progress/error)
-   Buzzer (5V)
-   Pushbutton (momentary)
-   Resistors (e.g., 220Ω for LEDs, 10kΩ for pushbutton pulldown if needed)
-   Breadboard and jumper wires
-   Disposable mouthpiece (ensure hygienic use)
-   Power supply for Arduino (USB or external)

## 🔌 Hardware Setup

1.  **Flow Sensor**: Connect VCC to 5V, GND to GND, and the signal pin to a digital interrupt pin on the Arduino (e.g., D2 or D3).
2.  **LCD Display**:
    *   If using I2C LCD: Connect VCC to 5V, GND to GND, SDA to A4, SCL to A5.
    *   If using parallel LCD: Connect according to standard LCD wiring (RS, E, D4-D7, V0, etc.).
3.  **LEDs**: Connect the anode (longer leg) of each LED to a digital pin via a current-limiting resistor (e.g., 220Ω), and the cathode (shorter leg) to GND.
4.  **Buzzer**: Connect one pin to a digital pin and the other to GND.
5.  **Pushbutton**: Connect one terminal to a digital pin and the other to GND. Enable the internal pull-up resistor for the pin in software, or use an external pull-down resistor (10kΩ to GND) with the other terminal connected to 5V.

*(A Fritzing diagram or a clear photo of the circuit would be highly beneficial here. Consider creating one and adding it.)*

## 💻 Software Setup

1.  **Arduino IDE**: Download and install the latest version of the [Arduino IDE](https://www.arduino.cc/en/software).
2.  **Libraries**:
    *   `LiquidCrystal_I2C` (if using an I2C LCD): Install via the Arduino Library Manager. Search for "LiquidCrystal I2C" by Frank de Brabander.
    *   `Wire.h` (for I2C communication, usually included with Arduino IDE).
3.  **Clone the Repository (Optional)**:
    ```bash
    git clone https://github.com/MostafaMousaaa/Intelligent-Respiratory-Monitoring-Spirometery.git
    cd Intelligent-Respiratory-Monitoring-Spirometery
    ```
4.  **Upload Sketch**: Open the `.ino` file in the Arduino IDE, select your board and port, and upload the sketch.

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

## 🚀 Getting Started

Follow these steps to set up and use the Arduino Spirometer:

1.  **Assemble Hardware**: Connect all components as described in the [Hardware Setup](#-hardware-setup) section. Ensure all connections are secure.
2.  **Power Up**: Connect the Arduino to your computer via USB or to an appropriate power supply.
3.  **Upload Code**:
    *   Open the project sketch (`.ino` file) in the Arduino IDE.
    *   Select the correct board (e.g., "Arduino Uno", "Arduino Nano") from `Tools > Board`.
    *   Select the correct COM port from `Tools > Port`.
    *   Click the "Upload" button.
4.  **Open Serial Monitor**: Once uploaded, open the Serial Monitor (`Tools > Serial Monitor` or `Ctrl+Shift+M`). Set the baud rate to 9600.
5.  **Prepare for Test**:
    *   Attach a clean, disposable mouthpiece to the flow sensor inlet.
    *   Ensure the user is in a comfortable, upright position (sitting or standing).
6.  **Initiate Test**:
    *   The LCD will display a "Ready" message.
    *   Press the pushbutton to start the test.
7.  **Perform Maneuver**:
    *   Take a deep breath in.
    *   Seal lips tightly around the mouthpiece.
    *   Exhale as forcefully and completely as possible for at least 6 seconds. The device will provide feedback.
8.  **View Results**: After the test duration (e.g., 6 seconds), the results (FVC, FEV1, FEV1/FVC ratio) will be displayed on the LCD and printed to the Serial Monitor.
9.  **Repeat (Optional)**: Press the button again to perform another test. It's common practice to perform at least three acceptable maneuvers.

## 📜 Code Highlights

Key sections of the Arduino code include:

```c
// --- Pin Definitions & Global Variables ---
// ... (e.g., pins for LCD, LEDs, button, flow sensor)
// volatile unsigned long pulseCount = 0;
// float calibrationFactor = 4.5; // Example: Adjust based on your sensor

// --- Interrupt Service Routine (ISR) for Flow Sensor ---
void countPulse() {
  pulseCount++;
}

// --- Flow Rate Calculation (typically in loop or timed function) ---
unsigned long currentTime = millis();
if (currentTime - lastReadTime >= 250) { // Read every 250ms
  detachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN));
  flowRate = (pulseCount / calibrationFactor) * (1000.0 / (currentTime - lastReadTime)); // L/min or L/s
  totalMilliLitres += (flowRate / 60.0) * (currentTime - lastReadTime); // Convert L/min to mL/ms
  pulseCount = 0;
  lastReadTime = currentTime;
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), countPulse, RISING);
}

// --- FEV1 Recording at exactly 1 second ---
if (testingInProgress && !fev1_recorded && (millis() - testStartTime >= 1000)) {
  fev1_volume = totalMilliLitres;
  fev1_recorded = true;
}

// --- FEV1/FVC Ratio Calculation ---
float ratio = 0;
if (fvc_volume > 0) {
  ratio = (fev1_volume / fvc_volume) * 100.0;
}
```
*Note: The code snippets above are illustrative. Refer to the actual source code for the complete implementation.*

## 🎬 Demonstration

<div align="center">
  <p>
    <a href="https://github.com/MostafaMousaaa/Intelligent-Respiratory-Monitoring-Spirometery/blob/main/spirovideo.mp4">
      <img src="https://github.com/MostafaMousaaa/Intelligent-Respiratory-Monitoring-Spirometery/blob/main/Img.png" alt="Demonstration Video Screenshot" width="600"/>
    </a><br>
    <i>Click the image to watch the demonstration video of the spirometer in action.</i>
  </p>
</div>

## 📝 Important Considerations

-   **Hygiene**: Always use a new, clean, or sterilized mouthpiece for each user to prevent cross-contamination. Dispose of used mouthpieces appropriately.
-   **Calibration**: The `calibrationFactor` in the code is crucial for accuracy. This factor depends on your specific flow sensor and may need adjustment. Calibrate against a known volume or a commercial spirometer if possible.
-   **Posture and Technique**: For reliable results, the user should maintain proper posture (e.g., sitting upright) and ensure a tight seal with their lips around the mouthpiece. A forceful and complete exhalation is necessary.
-   **Environmental Factors**: Temperature and humidity can affect air density and flow sensor readings. Consider these if high precision is required.
-   **Not a Medical Device**: This project is for educational and prototyping purposes. It is **not a certified medical device** and should not be used for self-diagnosis or to replace professional medical advice or equipment.

## 🔮 Future Enhancements

-   [ ] **Data Logging to SD Card**: Store test results directly on an SD card for later retrieval.
-   [ ] **Bluetooth Connectivity**: Transmit data wirelessly to a smartphone app or computer for advanced analysis and visualization.
-   [ ] **Graphical User Interface (GUI)**: Develop a simple PC or mobile application to display flow-volume loops and trend data.
-   [ ] **Improved Sensor Integration**: Experiment with more accurate medical-grade flow sensors.
-   [ ] **Automatic Calibration Routine**: Implement a feature for easier sensor calibration.
-   [ ] **Battery Power Option**: Add support for portable battery operation.
-   [ ] **Flow-Volume Loop Display**: If a graphical display is used, attempt to plot the flow-volume loop.

## 🤝 Contributing

Contributions are welcome! If you have suggestions for improvements, bug fixes, or new features, please feel free to:

1.  Fork the repository.
2.  Create a new branch (`git checkout -b feature/YourFeatureName`).
3.  Make your changes.
4.  Commit your changes (`git commit -m 'Add some feature'`).
5.  Push to the branch (`git push origin feature/YourFeatureName`).
6.  Open a Pull Request.

Please ensure your code adheres to a consistent style and includes comments where necessary.

## 📜 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE.md) file for details.
[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)

## 📚 References

-   American Thoracic Society (ATS) / European Respiratory Society (ERS) Task Force. (2005). Standardisation of spirometry. *European Respiratory Journal*, 26(2), 319-338. [DOI: 10.1183/09031936.05.00034805](https://erj.ersjournals.com/content/26/2/319)
-   Miller, M. R., Hankinson, J., Brusasco, V., Burgos, F., Casaburi, R., Coates, A., ... & Wanger, J. (2005). Standardisation of spirometry. *European respiratory journal*, 26(2), 319-338.

## ⚠️ Disclaimer

This Arduino-based Digital Spirometer is an educational and experimental project. It is **NOT A MEDICAL DEVICE** and has not undergone regulatory approval for medical use. The measurements obtained are for informational purposes only and should **not** be used for self-diagnosis, clinical diagnosis, treatment decisions, or to replace consultation with qualified healthcare professionals. The accuracy of this device may vary and is dependent on proper calibration, component quality, and user technique. Use at your own risk.

---

<div align="center">
  <p>Developed as part of the Medical Equipment Course | SBME 2026</p>
  <p>Contact: [Your Name/Email (Optional)]</p>
</div>
