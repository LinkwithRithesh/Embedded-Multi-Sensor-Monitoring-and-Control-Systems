# Embedded Multi-Sensor Monitoring and Control System

![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)
![Language](https://img.shields.io/badge/Language-C%2B%2B-orange)
![Embedded%20Systems](https://img.shields.io/badge/Domain-Embedded%20Systems-green)
![Status](https://img.shields.io/badge/Status-Completed-brightgreen)
![License](https://img.shields.io/badge/License-MIT-yellow)

Arduino-based embedded automation system featuring real-time multi-sensor data acquisition, environmental monitoring, and threshold-based control of motors and alert devices.

---

# Project Overview

The **Embedded Multi-Sensor Monitoring and Control System** is a real-time embedded automation project developed using **Arduino Uno (ATmega328P)**.

The system continuously acquires data from multiple sensors and automatically controls various actuators based on predefined threshold values. It demonstrates practical implementation of embedded monitoring, sensor interfacing, data acquisition, decision-making logic, and automated control systems.

The project integrates:

* IR Sensor for object detection
* MQ-2 Gas Sensor for gas leakage monitoring
* LM35 Temperature Sensor for temperature monitoring
* HC-SR04 Ultrasonic Sensor for distance measurement
* DC Motor control using L293D Motor Driver
* Stepper Motor automation
* LED-based alert indication

All sensor readings and device statuses are displayed in real-time through the Serial Monitor.

---

# Problem Statement

Design and develop a microcontroller-based Data Acquisition and Control System capable of acquiring real-time data from multiple sensors and automatically controlling output devices according to predefined threshold conditions.

The system should continuously monitor environmental conditions, process sensor data, execute control actions, and provide real-time feedback to the user.

---

# Project Specifications

| Parameter             | Value                               |
| --------------------- | ----------------------------------- |
| Platform              | Arduino Uno                         |
| Microcontroller       | ATmega328P                          |
| Programming Language  | Embedded C++                        |
| Simulation Software   | Proteus Professional                |
| Sensors Used          | 4                                   |
| Actuators Used        | 3                                   |
| Temperature Threshold | 20°C                                |
| Distance Threshold    | 15 cm                               |
| Serial Baud Rate      | 9600 bps                            |
| Project Type          | Data Acquisition and Control System |

---

# System Architecture

```text
                  +------------------+
                  |   Arduino Uno    |
                  +------------------+
                           |
      --------------------------------------------------
      |              |              |                  |
      |              |              |                  |
   IR Sensor      MQ-2 Gas      LM35 Sensor      HC-SR04 Sensor
 Object Detection   Sensor      Temperature      Distance
                   Monitoring    Monitoring      Measurement
      |              |              |                  |
      --------------------------------------------------
                           |
          ---------------------------------------
          |                 |                   |
          |                 |                   |
        LED             DC Motor         Stepper Motor
      Alert System      Control           Automation
```

---

# Features

* Real-time sensor data acquisition
* IR-based object detection
* Gas leakage monitoring and alert indication
* Temperature-based automatic DC motor control
* Ultrasonic distance measurement
* Automatic stepper motor operation
* Continuous Serial Monitor output
* Threshold-based decision making
* Embedded automation and control implementation
* Proteus simulation support

---

# Hardware Components

| Component                 | Function                |
| ------------------------- | ----------------------- |
| Arduino Uno               | Main Controller         |
| IR Sensor                 | Object Detection        |
| MQ-2 Gas Sensor           | Gas Leakage Detection   |
| LM35 Temperature Sensor   | Temperature Monitoring  |
| HC-SR04 Ultrasonic Sensor | Distance Measurement    |
| L293D Motor Driver        | DC Motor Control        |
| ULN2003 Driver            | Stepper Motor Interface |
| DC Motor                  | Automated Actuation     |
| Stepper Motor             | Distance-Based Motion   |
| LED                       | Alert Indication        |

---

# Hardware Specifications

* Microcontroller: ATmega328P
* Operating Voltage: 5V
* Motor Driver: L293D
* Stepper Driver: ULN2003
* Communication: UART Serial Communication
* Baud Rate: 9600 bps
* Temperature Threshold: 20°C
* Distance Threshold: 15 cm

---

# Pin Configuration

| Arduino Pin | Connected Device        |
| ----------- | ----------------------- |
| D2          | IR Sensor               |
| D3          | MQ-2 Gas Sensor         |
| D4          | LED                     |
| D5          | DC Motor Input 1        |
| D13         | DC Motor Input 2        |
| D7          | Ultrasonic Trigger      |
| D8          | Ultrasonic Echo         |
| D9          | Stepper Motor Coil A    |
| D10         | Stepper Motor Coil B    |
| D11         | Stepper Motor Coil C    |
| D12         | Stepper Motor Coil D    |
| A0          | LM35 Temperature Sensor |

---

# Functional Description

## 1. IR Sensor Operation

The IR sensor continuously detects the presence of nearby objects.

### Operation

**If an object is detected:**

```text
Object Detected
```

**If no object is detected:**

```text
No Object Detected
```

---

## 2. Gas Leakage Detection and Alert System

The MQ-2 gas sensor continuously monitors the environment for gas leakage.

### Operation

**If gas leakage is detected:**

```text
GAS LEAKAGE DETECTED !!!
```

* LED blinks repeatedly as an emergency warning signal.

**If no gas is detected:**

```text
No Gas Detected
```

* LED remains OFF.

---

## 3. Temperature Monitoring and DC Motor Control

The LM35 sensor continuously measures ambient temperature.

### Threshold Temperature

```text
20°C
```

### Operation

**If Temperature ≥ 20°C**

```text
DC Motor ON
```

The DC motor is activated through the L293D motor driver.

**If Temperature < 20°C**

```text
DC Motor OFF
```

The DC motor remains stopped.

---

## 4. Ultrasonic Distance Measurement and Stepper Motor Control

The HC-SR04 sensor continuously measures object distance.

### Threshold Distance

```text
15 cm
```

### Operation

**If Distance < 15 cm**

```text
Object Close
```

* Stepper motor rotates clockwise.
* Stepper motor rotates anticlockwise.

**If Distance ≥ 15 cm**

```text
Object Far
```

* Stepper motor remains stopped.

---

# System Workflow

```text
Start
  |
Initialize Arduino
  |
Read IR Sensor
  |
Read Gas Sensor
  |
Read Temperature Sensor
  |
Read Ultrasonic Sensor
  |
Compare with Threshold Values
  |
Execute Control Actions
  |
Display Results on Serial Monitor
  |
Repeat Continuously
```

---

# Circuit Diagram

## Proteus Circuit Design

![Circuit Diagram](circuit/circuit_diagram.jpg)

The complete Proteus project file is available inside the **model** folder.

---

# Simulation Model

The Proteus simulation project file is available at:

```text
model/data_acquisition_and_control_system.pdsprj
```

Open the project using **Proteus Professional** and run the simulation to observe real-time operation.

---

# Serial Monitor Output

## Output 1

![Serial Output 1](output/serial_output1.png)

## Output 2

![Serial Output 2](output/serial_output2.png)

---

# How to Run

## Clone Repository

```bash
git clone https://github.com/LinkwithRithesh/Embedded-Multi-Sensor-Monitoring-and-Control-System.git
```

## Arduino IDE Setup

1. Open Arduino IDE
2. Open `data_code.ino`
3. Select:

```text
Tools → Board → Arduino Uno
```

4. Upload the code to Arduino Uno
5. Open Serial Monitor
6. Set baud rate to:

```text
9600
```

7. Observe sensor readings and actuator responses

---

# Repository Structure

```text
Embedded-Multi-Sensor-Monitoring-and-Control-System
│
├── circuit
│   ├── circuit_diagram.jpg
│   └── wiring_diagram.pdf
│
├── model
│   └── data_acquisition_and_control_system.pdsprj
│
├── output
│   ├── serial_output1.png
│   └── serial_output2.png
│
├── code
│   └── data_code.ino
│
├── README.md
└── LICENSE
```

---

# Applications

* Industrial Monitoring Systems
* Embedded Automation Systems
* Environmental Monitoring
* Smart Safety Systems
* Sensor-Based Automation
* Real-Time Control Systems
* Educational Embedded Projects
* Industrial Process Monitoring

---

# Future Enhancements

* IoT Integration
* Wi-Fi Monitoring
* Cloud Data Logging
* Mobile Application Interface
* LCD/OLED Display Module
* Web Dashboard Monitoring
* Wireless Sensor Network
* Remote Monitoring System
* Data Analytics Integration

---

# Learning Outcomes

This project demonstrates:

* Sensor Interfacing
* Embedded System Design
* Data Acquisition Techniques
* Real-Time Monitoring
* Threshold-Based Automation
* Motor Driver Interfacing
* Stepper Motor Control
* Serial Communication
* Embedded Decision Making
* Industrial Automation Concepts

---

# Project Status

✅ Proteus Simulation Completed

✅ Sensor Integration Completed

✅ Real-Time Monitoring Implemented

✅ Actuator Control Implemented

✅ Serial Communication Verified

✅ System Testing Completed

---

# Project Resources

Google Drive Folder:

```text
https://drive.google.com/drive/u/0/folders/1DKsZYU_bfopb9j0VWOTwYdVp9OY8z6Tq
```

---

# Author

**Ritheshwaran A**

B.E. Electronics and Communication Engineering

College of Engineering Guindy (CEG)

Anna University

GitHub: https://github.com/LinkwithRithesh

---

# License

This project is licensed under the MIT License.

© 2026 Ritheshwaran A
