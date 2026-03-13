// CARE-AI Fall Detection Sensor - Arduino Code
// =============================================
// 
// This code runs on an Arduino/ESP32 with MPU6050 accelerometer/gyroscope
// to detect falls and send alerts to the IoT hub.

#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

// MPU6050 I2C Address
const int MPU6050_ADDR = 0x68;

// WiFi credentials (replace with your network)
const char* WIFI_SSID = "your_wifi_ssid";
const char* WIFI_PASSWORD = "your_wifi_password";

// CARE-AI API endpoint
const char* API_ENDPOINT = "http://192.168.1.100:8000/api/v1/fall-detection/realtime";
const char* USER_ID = "elderly-001";

// Thresholds
const float FALL_THRESHOLD_G = 3.0;  // 3g acceleration
const float POST_FALL_STILLNESS = 0.5;  // Low movement after fall

// Sensor data
float accelX, accelY, accelZ;
float gyroX, gyroY, gyroZ;
float temperature;

// Fall detection state
bool potentialFall = false;
unsigned long fallTime = 0;
const int STILLNESS_CHECK_DURATION = 2000;  // 2 seconds

void setup() {
  Serial.begin(115200);
  
  // Initialize I2C
  Wire.begin();
  
  // Initialize MPU6050
  initMPU6050();
  
  // Connect to WiFi
  connectWiFi();
  
  Serial.println("CARE-AI Fall Detection System Ready");
}

void loop() {
  // Read sensor data
  readMPU6050();
  
  // Calculate acceleration magnitude
  float accelMagnitude = sqrt(accelX*accelX + accelY*accelY + accelZ*accelZ);
  float accelMagnitudeG = accelMagnitude / 9.8;
  
  // Check for fall
  if (!potentialFall && accelMagnitudeG > FALL_THRESHOLD_G) {
    // High impact detected
    potentialFall = true;
    fallTime = millis();
    Serial.println("! High impact detected - monitoring for fall confirmation");
  }
  
  // Check for post-fall stillness
  if (potentialFall) {
    if (millis() - fallTime > STILLNESS_CHECK_DURATION) {
      // Check if person is still (low movement)
      if (accelMagnitudeG < 1.5) {
        // Fall confirmed!
        Serial.println("!! FALL DETECTED - Sending alert!");
        sendFallAlert(accelMagnitudeG);
        potentialFall = false;
      } else {
        // Movement detected, false alarm
        Serial.println("Movement detected - false alarm");
        potentialFall = false;
      }
    }
  }
  
  // Send regular readings every second
  static unsigned long lastSend = 0;
  if (millis() - lastSend > 1000) {
    sendSensorReading();
    lastSend = millis();
  }
  
  delay(20);  // 50Hz sampling rate
}

void initMPU6050() {
  // Wake up MPU6050
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // Wake up
  Wire.endTransmission(true);
  
  // Configure accelerometer (±8g)
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x1C);  // ACCEL_CONFIG register
  Wire.write(0x10);  // ±8g
  Wire.endTransmission(true);
  
  // Configure gyroscope (±500°/s)
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x1B);  // GYRO_CONFIG register
  Wire.write(0x08);  // ±500°/s
  Wire.endTransmission(true);
  
  Serial.println("MPU6050 initialized");
}

void readMPU6050() {
  Wire.beginTransmission(MPU6050_ADDR);
  Wire.write(0x3B);  // Starting register
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_ADDR, 14, true);
  
  // Read accelerometer (±8g scale = 4096 LSB/g)
  int16_t accelXRaw = Wire.read() << 8 | Wire.read();
  int16_t accelYRaw = Wire.read() << 8 | Wire.read();
  int16_t accelZRaw = Wire.read() << 8 | Wire.read();
  
  // Read temperature
  int16_t tempRaw = Wire.read() << 8 | Wire.read();
  
  // Read gyroscope (±500°/s scale = 65.5 LSB/°/s)
  int16_t gyroXRaw = Wire.read() << 8 | Wire.read();
  int16_t gyroYRaw = Wire.read() << 8 | Wire.read();
  int16_t gyroZRaw = Wire.read() << 8 | Wire.read();
  
  // Convert to physical units
  accelX = accelXRaw / 4096.0 * 9.8;  // m/s²
  accelY = accelYRaw / 4096.0 * 9.8;
  accelZ = accelZRaw / 4096.0 * 9.8;
  
  gyroX = gyroXRaw / 65.5;  // °/s
  gyroY = gyroYRaw / 65.5;
  gyroZ = gyroZRaw / 65.5;
  
  temperature = tempRaw / 340.0 + 36.53;  // °C
}

void connectWiFi() {
  Serial.print("Connecting to WiFi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 30) {
    delay(500);
    Serial.print(".");
    attempts++;
  }
  
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nWiFi connected!");
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("\nWiFi connection failed!");
  }
}

void sendFallAlert(float magnitude) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected - cannot send alert");
    return;
  }
  
  HTTPClient http;
  http.begin(API_ENDPOINT);
  http.addHeader("Content-Type", "application/json");
  
  // Create JSON payload
  StaticJsonDocument<256> doc;
  doc["user_id"] = USER_ID;
  doc["fall_detected"] = true;
  doc["magnitude"] = magnitude;
  doc["accelerometer_x"] = accelX;
  doc["accelerometer_y"] = accelY;
  doc["accelerometer_z"] = accelZ;
  doc["timestamp"] = millis();
  
  String payload;
  serializeJson(doc, payload);
  
  int httpCode = http.POST(payload);
  
  if (httpCode > 0) {
    Serial.printf("Alert sent! Response: %d\n", httpCode);
  } else {
    Serial.printf("Failed to send alert: %s\n", http.errorToString(httpCode).c_str());
  }
  
  http.end();
}

void sendSensorReading() {
  // Send regular sensor reading for continuous monitoring
  // This would be sent less frequently in production
  
  Serial.printf("Accel: (%.2f, %.2f, %.2f) m/s² | Gyro: (%.1f, %.1f, %.1f) °/s | Temp: %.1f°C\n",
                accelX, accelY, accelZ,
                gyroX, gyroY, gyroZ,
                temperature);
}
