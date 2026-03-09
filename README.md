# IoT Enabled Smart Exhaust Fan (ESP32)

An IoT-based smart exhaust fan system that automatically controls ventilation based on environmental conditions such as humidity and air quality.

The system uses an **ESP32 microcontroller** along with **DHT11** and **MQ135 gas sensors** to monitor environmental conditions and automatically activate an exhaust fan when thresholds are exceeded. The system also supports **manual control and real-time monitoring through the Blynk mobile application**.

---

## Features

* Automatic fan control based on humidity and air quality
* Real-time monitoring through the Blynk mobile application
* Manual fan control using the mobile interface
* Wi-Fi based remote monitoring and control
* Low-cost IoT automation system

---

## Hardware Components

* ESP32 DevKit V1
* DHT11 Temperature and Humidity Sensor
* MQ135 Gas Sensor (Air Quality Sensor)
* L298N Motor Driver
* DC Motor / Exhaust Fan
* External Power Supply
* Connecting wires and breadboard

---

## System Architecture

The system continuously monitors environmental conditions using sensors connected to the ESP32.

* **DHT11** measures temperature and humidity
* **MQ135** detects air quality including smoke, CO₂, and other gases
* **ESP32** processes sensor data and decides whether the fan should run
* **L298N motor driver** controls the exhaust fan motor
* **Blynk mobile application** provides real-time monitoring and manual control

When the sensor readings exceed predefined thresholds, the ESP32 automatically activates the exhaust fan to improve ventilation.

---

## Circuit Setup

![Circuit Diagram](images/circuit.jpg)

---

## Hardware Setup

![Hardware Setup](images/setup.jpg)

---

## Sensor Thresholds

| Parameter   | Threshold |
| ----------- | --------- |
| Humidity    | 60%       |
| Smoke / Gas | 200 ppm   |
| Air Quality | 300 ppm   |
| CO₂         | 400 ppm   |

If any of these thresholds are exceeded, the exhaust fan is automatically turned ON.

---

## Blynk Dashboard

The **Blynk mobile application** is used to monitor environmental data and control the exhaust fan remotely.

The dashboard displays:

* Air Quality Level
* Temperature
* Humidity
* Fan Status

It also includes a **manual control switch** that allows the user to override the automatic mode.

---

## Code

The ESP32 firmware used for this project is available in the following directory:

code/smart_exhaust_fan.ino

The code handles:

* Sensor data acquisition
* Environmental threshold detection
* Motor driver control
* Blynk communication over Wi-Fi

---

## Demo Video

(Add your YouTube demo video link here)

Example:

https://youtube.com/your-video-link

---

## Applications

This project can be used in several real-world applications:

* Smart home ventilation systems
* Kitchen exhaust automation
* Indoor air quality monitoring
* Industrial ventilation systems
* IoT-based environmental monitoring

---

## Future Improvements

* Integration with additional sensors (CO₂, PM2.5, etc.)
* Data logging and analytics using cloud services
* Mobile notifications for poor air quality
* Integration with home automation platforms

---

## Author

**Nisarg Vyas**
B.Tech Computer Science and Engineering
IIIT Vadodara (IIITV-ICD)

Interested in **Robotics, Embedded Systems, and IoT-based automation projects**.
