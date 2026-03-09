# IoT Enabled Smart Exhaust Fan using ESP32

An **IoT-based Smart Exhaust Fan system** that monitors air quality and temperature using sensors and automatically controls a ventilation fan. The system can also be monitored and controlled remotely using the **Blynk IoT platform**.

---

# 📌 Project Overview

Indoor air quality and ventilation are important for maintaining a healthy environment. This project uses an **ESP32 microcontroller** along with environmental sensors to detect air quality and temperature and automatically control an exhaust fan.

The system reads:

* **Temperature and Humidity** using the **DHT11 sensor**
* **Air Quality / Gas Levels** using the **MQ135 gas sensor**

If the air quality crosses a predefined threshold, the ESP32 activates a **12V exhaust fan** using an **L298N motor driver**.

Unlike many similar projects that use a **relay module**, this implementation uses an **L298N motor driver**, which allows better control of the fan and enables possible **PWM speed control**.

---

# 🧰 Hardware Components

| Component          | Description                           |
| ------------------ | ------------------------------------- |
| ESP32 DevKit V1    | Main microcontroller with WiFi        |
| MQ135 Gas Sensor   | Detects air quality and harmful gases |
| DHT11 Sensor       | Measures temperature and humidity     |
| L298N Motor Driver | Drives the exhaust fan                |
| 12V DC Fan         | Ventilation fan                       |
| 12V Power Supply   | Powers the fan                        |
| Jumper Wires       | Electrical connections                |

---

# ⚙️ System Architecture

```
MQ135 Sensor  ----\
                   \
                    --> ESP32 --> L298N Motor Driver --> Exhaust Fan
                   /
DHT11 Sensor  ----/

             |
             |
          WiFi
             |
         Blynk App
```

The ESP32 reads sensor values, processes them, and controls the fan accordingly while also communicating with the **Blynk IoT platform**.

---

# 🔌 Circuit Diagram

The complete circuit diagram for the project is provided below.

![Circuit Diagram](docs/circuit_diagram.png)

For detailed wiring and pin connections refer to:

```
docs/circuit_connections.txt
```

This file contains the full pin mapping and connection details.

---

# 📱 Blynk IoT Dashboard

The system can be monitored and controlled using the **Blynk mobile application**.

![Blynk Dashboard](images/blynk.png)

Features available through Blynk:

* Monitor sensor readings
* Turn the fan ON/OFF remotely
* Real-time monitoring through WiFi

---

# 📷 Hardware Setup

### Internal View

![Internal Setup](images/view_from_in.png)

### External View

![External Setup](images/view_from_out.png)

---

# 🎥 Project Demonstration

A working demonstration of the project is available in the repository.

You can find the video in:

```
videos/
```

Download or view the demonstration video directly from the GitHub repository.

---

# 💻 Source Code

The Arduino code for the project is available in:

```
codes/smart_exhaust_fan.ino
```

Upload the code to the ESP32 using the **Arduino IDE**.

Required libraries:

```
Blynk
DHT Sensor Library
Adafruit Unified Sensor Library
```

---

# 🚀 Working Principle

1. The **DHT11 sensor** measures temperature and humidity.
2. The **MQ135 sensor** measures air quality and gas concentration.
3. ESP32 continuously monitors these sensor values.
4. If air quality exceeds the defined threshold:

   * ESP32 activates the fan through the **L298N motor driver**.
5. Sensor data and fan control can be monitored using the **Blynk IoT app**.

---

# 📁 Repository Structure

```
iot-smart-exhaust-fan-esp32
│
├── codes
│   └── smart_exhaust_fan.ino
│
├── docs
│   ├── circuit_connections.txt
│   └── circuit_diagram.png
│
├── images
│   ├── blynk.png
│   ├── view_from_in.png
│   └── view_from_out.png
│
├── videos
│
├── LICENSE
└── README.md
```

---

# 📜 License

This project is licensed under the **MIT License**.

---

# 👨‍💻 Author
**Nisarg Vyas**
Computer Science Engineering Student
