#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <HTTPClient.h>

// ==== WiFi Credentials ====
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";
// ==== Google Script Web App URL ====
const char* serverName = "YOUR_GOOGLE_APPS_SCRIPT_URL";

// ==== Pin Definitions ====
#define TRIG_PIN    5
#define ECHO_PIN    18
#define BUZZER_PIN  19

// ==== LCD Setup ====
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);  // For ESP32: SDA = 21, SCL = 22

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("LCD Ready");
  delay(1000);
  lcd.clear();

  WiFi.begin(ssid, password);
  lcd.print("Connecting WiFi");

  int tries = 0;
  while (WiFi.status() != WL_CONNECTED && tries < 20) {
    delay(500);
    Serial.print(".");
    tries++;
  }

  lcd.clear();
  if (WiFi.status() == WL_CONNECTED) {
    lcd.print("WiFi Connected");
    Serial.println("\nWiFi Connected");
  } else {
    lcd.print("WiFi Failed");
    Serial.println("\nWiFi Failed");
  }

  delay(1500);
  lcd.clear();
}

void loop() {
  // Measure distance
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * 0.0343 / 2;

  // Display distance
  lcd.setCursor(0, 0);
  lcd.print("Distance:");
  lcd.print(distance, 1);
  lcd.print("cm  ");

  String status = "Normal Road";
if (distance <= 8) {
    status = "Speed Breaker";
    digitalWrite(BUZZER_PIN, HIGH);
}
else if (distance >= 12) {
    status = "Pothole Ahead";
    digitalWrite(BUZZER_PIN, HIGH);
}
else {
    status = "Normal Road";
    digitalWrite(BUZZER_PIN, LOW);
}

  // Display status
  lcd.setCursor(0, 1);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print(status);

  // Replace spaces for URL encoding
  status.replace(" ", "%20");

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    String url = serverName;
    url += "?distance=" + String(distance, 2) + "&status=" + status;

    Serial.println("Sending to Google Sheets:");
    Serial.println(url);

    http.begin(url);
    http.setFollowRedirects(HTTPC_FORCE_FOLLOW_REDIRECTS);  // Handle 302 properly
    int httpCode = http.GET();

    Serial.print("HTTP Response Code: ");
    Serial.println(httpCode);

    if (httpCode == 200) {
      String payload = http.getString();
      Serial.println("Response: " + payload);
    } else {
      Serial.println("Failed to send data.");
    }

    http.end();
  } else {
    Serial.println("WiFi not connected.");
  }

  delay(700);
}
