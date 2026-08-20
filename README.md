# 🚧 IoT Pothole & Speed Breaker Detection System

An IoT-based road monitoring system that detects potential **potholes and speed breakers** using an ultrasonic sensor. The system provides real-time alerts through an LCD and buzzer and sends detection data to **Google Sheets using Wi-Fi** for logging and monitoring.

## 📌 Project Overview

Poor road conditions such as potholes and speed breakers can cause accidents and vehicle damage. This project uses an **ESP32** and an **ultrasonic sensor** to measure the distance between the sensor and the road surface.

Based on the measured distance, the system classifies the road condition and:

* Displays the distance on a 16×2 LCD
* Detects potholes and speed breakers
* Activates a buzzer as an alert
* Connects to Wi-Fi
* Sends distance and road status data to Google Sheets

## ✨ Features

* 📏 Real-time distance measurement
* 🕳️ Pothole detection
* 🚧 Speed breaker detection
* 🔊 Buzzer warning system
* 📟 16×2 I2C LCD display
* 📶 Wi-Fi connectivity using ESP32
* ☁️ Cloud logging using Google Sheets
* 📊 Stores distance and detection status for monitoring

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

| Buzzer   | ESP32 Pin |
| -------- | --------: |
| Positive |   GPIO 19 |
| Negative |       GND |

### I2C LCD

| LCD Pin | ESP32 Pin |
| ------- | --------: |
| SDA     |   GPIO 21 |
| SCL     |   GPIO 22 |
| VCC     |        5V |
| GND     |       GND |

## ⚙️ Working Principle

The ultrasonic sensor continuously measures the distance between the sensor and the road surface.

The ESP32 processes this distance and determines the road condition based on predefined thresholds.

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

* **Distance < 10 cm** → `Speed Breaker`
* **Distance > 8 cm** → `Pothole Ahead`
* Otherwise → `Normal Road`

When a pothole or speed breaker is detected, the buzzer is activated and the result is displayed on the LCD.

> **Note:** The distance thresholds can be calibrated according to the height and mounting position of the sensor.

## 📟 LCD Output

Example output:

```text
Distance:12.5cm
Pothole Ahead
```

Or:

```text
Distance:7.5cm
Speed Breaker
```

## ☁️ Google Sheets Integration

The ESP32 connects to Wi-Fi and sends the following data to a Google Apps Script Web App:

* Distance
* Road Status

Example request:

```text
?distance=12.50&status=Pothole%20Ahead
```

The Google Apps Script receives this information and stores it in Google Sheets for future monitoring and analysis.

## 💻 Software and Libraries

The project is developed using Arduino IDE with the following libraries:

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
git clone https://github.com/Onkar0726/IOT_Pothole_breaker_detection.git
```

### 2. Open the Project

Open the Arduino source code in **Arduino IDE**.

### 3. Install Required Libraries

Install the required libraries from the Arduino Library Manager.

### 4. Configure Wi-Fi

Update your Wi-Fi credentials:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

### 5. Configure Google Apps Script URL

Replace the Web App URL if required:

```cpp
const char* serverName = "YOUR_GOOGLE_APPS_SCRIPT_WEB_APP_URL";
```

### 6. Select ESP32 Board

In Arduino IDE:

```text
Tools → Board → ESP32 Dev Module
```

Select the correct COM port and upload the code.

## 📂 Project Structure

```text
IOT_Pothole_breaker_detection/
│
├── Pothole_detection.ino
├── README.md
└── images/
    ├── circuit-diagram.jpg
    └── project-demo.jpg
```

## 🔮 Future Improvements

* Add GPS module to record pothole location
* Display detected potholes on Google Maps
* Add severity levels for potholes
* Store timestamp automatically
* Create a web dashboard for monitoring
* Use multiple sensors for better accuracy
* Add machine learning or computer vision for advanced road detection

## 👨‍💻 Author

**Onkar Londhe**

GitHub: https://github.com/Onkar0726

## 📄 License

This project is created for educational and learning purposes.

---

⭐ If you found this project useful, consider giving the repository a star!
