# 🚧 IoT Pothole & Speed Breaker Detection System

An IoT-based road condition monitoring system built using an **ESP32** and an **ultrasonic sensor** to detect potential potholes and speed breakers. The system provides real-time alerts through an LCD and buzzer and logs detection data to **Google Sheets via Wi-Fi**.

> 🎓 This project was developed as my first college IoT project, focusing on the integration of embedded hardware, sensors, Wi-Fi communication, and cloud-based data logging.

## 📌 Project Overview

Poor road conditions such as potholes and speed breakers can cause vehicle damage and contribute to accidents. This project uses an ultrasonic sensor to continuously measure the distance between the sensor and the road surface.

The ESP32 processes the measured distance to identify significant changes in road height and performs the following actions:

* 📏 Displays the measured distance on a 16×2 LCD
* 🕳️ Detects potential potholes
* 🚧 Detects potential speed breakers
* 🔊 Activates a buzzer when an abnormal road condition is detected
* 📶 Connects to Wi-Fi
* ☁️ Sends distance and road status data to Google Sheets

## ✨ Features

* Real-time distance measurement
* Pothole detection
* Speed breaker detection
* Buzzer-based alerts
* 16×2 I2C LCD output
* Wi-Fi connectivity using ESP32
* HTTP communication with Google Apps Script
* Google Sheets data logging

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

The ultrasonic sensor continuously measures the distance between the sensor and the road surface.

The ESP32 processes this measurement and compares it with predefined distance thresholds. Based on the measured distance, the system identifies changes in the road surface and classifies them as a potential pothole, speed breaker, or normal road condition.

```text
Ultrasonic Sensor
        ↓
Distance Measurement
        ↓
      ESP32
     ↙   ↓   ↘
   LCD  Buzzer  Wi-Fi
                   ↓
          Google Apps Script
                   ↓
             Google Sheets
```

When an abnormal road condition is detected, the buzzer is activated, the status is displayed on the LCD, and the data is sent to Google Sheets.

> **Note:** Detection thresholds depend on the sensor mounting height and physical setup. They should be calibrated using real-world measurements for improved accuracy.

## 📟 Example Output

### Pothole Detection

```text
Distance: 12.5cm
Pothole Ahead
```

### Speed Breaker Detection

```text
Distance: 7.5cm
Speed Breaker
```

## ☁️ Google Sheets Integration

The ESP32 sends data to a Google Apps Script Web App using HTTP GET requests.

The following data is logged:

* Distance
* Road status

Example request format:

```text
?distance=12.50&status=Pothole%20Ahead
```

The Google Apps Script receives the data and stores it in Google Sheets for monitoring and analysis.

## 💻 Technologies Used

* **ESP32**
* **Arduino IDE**
* **Embedded C++**
* **I2C Communication**
* **Wi-Fi**
* **HTTPClient**
* **Google Apps Script**
* **Google Sheets**

## 📚 Required Libraries

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>
```

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Onkar0726/iot-pothole-speed-breaker-detection.git
```

### 2. Open the Project

Open the Arduino source code located in the `src` folder using **Arduino IDE**.

### 3. Install Required Libraries

Install the required libraries using the Arduino Library Manager:

* LiquidCrystal_I2C

The following libraries are included with the ESP32 Arduino framework:

* Wire
* WiFi
* HTTPClient

### 4. Configure Wi-Fi

Update the Wi-Fi credentials in the source code:

```cpp
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
```

### 5. Configure Google Apps Script

Add your deployed Google Apps Script Web App URL:

```cpp
const char* serverName = "YOUR_GOOGLE_APPS_SCRIPT_WEB_APP_URL";
```

### 6. Connect the Hardware

Connect the ultrasonic sensor, I2C LCD, and buzzer according to the pin configuration shown above.

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

## 🔮 Future Improvements

* Add GPS to record the location of detected potholes
* Display road issues on a map
* Add timestamps to each detection
* Implement data filtering to reduce false detections
* Add pothole severity levels
* Create a web dashboard for monitoring
* Use multiple sensors for improved accuracy
* Explore computer vision for advanced road condition detection

## 👨‍💻 Author

**Onkar Londhe**

GitHub: https://github.com/Onkar-726

## 📄 License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

---

⭐ If you found this project useful, consider giving the repository a star!
