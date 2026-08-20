# 🚧 IoT Pothole & Speed Breaker Detection System

An IoT-based road condition monitoring system that uses an **ESP32** and an **ultrasonic sensor** to detect potential potholes and speed breakers. The system provides real-time alerts using an LCD and buzzer and logs detection data to **Google Sheets via Wi-Fi**.

> 🎓 This project was developed as a college IoT subject project and focuses on integrating embedded hardware, sensors, Wi-Fi communication, and cloud-based data logging.

## 📌 Project Overview

Poor road conditions such as potholes and speed breakers can contribute to vehicle damage and accidents. This project measures the distance between an ultrasonic sensor and the road surface to identify significant changes in road height.

Based on the measured distance, the ESP32 processes the road condition and:

* Displays the measured distance on a 16×2 LCD
* Detects potential potholes and speed breakers
* Activates a buzzer for alerts
* Connects to a Wi-Fi network
* Sends distance and road status data to Google Sheets

## ✨ Features

* 📏 Real-time distance measurement
* 🕳️ Pothole detection
* 🚧 Speed breaker detection
* 🔊 Buzzer-based alerts
* 📟 16×2 I2C LCD output
* 📶 Wi-Fi connectivity using ESP32
* ☁️ Google Sheets cloud logging
* 📊 Stores distance and road status data for monitoring

## 🛠️ Components Used

| Component                   |    Quantity |
| --------------------------- | ----------: |
| ESP32                       |           1 |
| Ultrasonic Sensor (HC-SR04) |           1 |
| 16×2 I2C LCD                |           1 |
| Buzzer                      |           1 |
| Jumper Wires                | As required |
| Power Supply                |           1 |

## 🔌 Pin Connections

### Ultrasonic Sensor

| HC-SR04 Pin | ESP32 Pin |
| ----------- | --------: |
| TRIG        |    GPIO 5 |
| ECHO        |   GPIO 18 |
| VCC         |        5V |
| GND         |       GND |

### Buzzer

| Buzzer Pin | ESP32 Pin |
| ---------- | --------: |
| Positive   |   GPIO 19 |
| Negative   |       GND |

### I2C LCD

| LCD Pin | ESP32 Pin |
| ------- | --------: |
| SDA     |   GPIO 21 |
| SCL     |   GPIO 22 |
| VCC     |        5V |
| GND     |       GND |

## ⚙️ Working Principle

The ultrasonic sensor continuously measures the distance between the sensor and the road surface. The ESP32 processes this measurement and classifies the road condition according to predefined distance thresholds.

```text
Ultrasonic Sensor
        ↓
Distance Measurement
        ↓
      ESP32
     ↙  ↓  ↘
   LCD Buzzer Wi-Fi
                ↓
         Google Apps Script
                ↓
           Google Sheets
```

### Detection Logic

The road condition is determined by comparing the measured distance with configured thresholds:

* A significantly **smaller distance** may indicate a raised surface or `Speed Breaker`.
* A significantly **larger distance** may indicate a depression or `Pothole Ahead`.
* Distances within the normal calibrated range are classified as `Normal Road`.

> **Note:** Detection thresholds depend on the sensor's mounting height and physical setup. They should be calibrated using real measurements before deployment.

When a potential pothole or speed breaker is detected, the system activates the buzzer and displays the road status on the LCD.

## 📟 Example LCD Output

### Pothole Detection

```text
Distance:12.5cm
Pothole Ahead
```

### Speed Breaker Detection

```text
Distance:7.5cm
Speed Breaker
```

## ☁️ Google Sheets Integration

The ESP32 connects to Wi-Fi and sends the following information to a Google Apps Script Web App:

* Distance
* Road Status

Example request format:

```text
?distance=12.50&status=Pothole%20Ahead
```

The Google Apps Script receives the data and stores it in Google Sheets for monitoring and future analysis.

## 💻 Software and Libraries

The project is developed using **Arduino IDE** with the following libraries:

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>
```

### Required Libraries

* Wire
* LiquidCrystal_I2C
* WiFi
* HTTPClient

## 🚀 How to Run

### 1. Clone the Repository

```bash
git clone https://github.com/Onkar0726/iot-pothole-speed-breaker-detection.git
```

### 2. Open the Project

Navigate to the `src` folder and open the Arduino source code in **Arduino IDE**.

### 3. Install Required Libraries

Install the required libraries using the Arduino Library Manager.

### 4. Configure Wi-Fi

Update the Wi-Fi credentials in the source code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

### 5. Configure Google Apps Script

Add your Google Apps Script Web App URL:

```cpp
const char* serverName = "YOUR_GOOGLE_APPS_SCRIPT_WEB_APP_URL";
```

### 6. Connect the Hardware

Connect the ultrasonic sensor, LCD, and buzzer according to the pin connections listed above.

### 7. Select the ESP32 Board

In Arduino IDE, select:

```text
Tools → Board → ESP32 Dev Module
```

Select the correct COM port and upload the code.

## 📂 Project Structure

```text
iot-pothole-speed-breaker-detection/
│
├── src/
│   └── pothole_speed_breaker_detection.ino
│
├── images/
│   ├── hardware-setup.jpg
│   ├── lcd-output.jpg
│   └── google-sheets-output.png
│
├── .gitignore
├── LICENSE
└── README.md
```

> The exact filenames in the `images` folder may differ depending on the files included in the repository.

## 🔮 Future Improvements

* Add a GPS module to record pothole locations
* Display detected road issues on a map
* Add severity levels based on pothole depth
* Include timestamps with every detection
* Create a web dashboard for monitoring
* Use multiple sensors for improved accuracy
* Reduce false detections through filtering and calibration
* Explore computer vision or machine learning for advanced road analysis

## 👨‍💻 Author

**Onkar Londhe**

GitHub: https://github.com/Onkar0726

## 📄 License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

---

⭐ If you found this project useful, consider giving the repository a star!
