# Embedded Multi-Sensor Monitoring and Control System

## Project Overview

This project implements a **real-time Data Acquisition and Control System** using an Arduino Uno. The system continuously acquires data from multiple sensors and automatically controls various actuators based on predefined threshold conditions.

The project demonstrates sensor interfacing, embedded automation, real-time monitoring, and actuator control using multiple input and output devices.

---

## Problem Statement

Design and develop a Data Acquisition and Control System using a microcontroller to acquire data from multiple sensors and control different actuators based on predefined threshold conditions.

The system continuously displays sensor readings and device status information through the Serial Monitor.

---

## Objectives

* Acquire real-time data from multiple sensors
* Monitor environmental and object detection conditions
* Implement threshold-based automatic control
* Interface multiple actuators with Arduino Uno
* Display real-time system status through Serial Monitor
* Demonstrate embedded automation and control concepts

---

## Features

* Real-time sensor data acquisition
* IR-based object detection
* Temperature monitoring with automatic DC motor control
* Gas leakage detection with LED alert indication
* Ultrasonic distance measurement
* Stepper motor automation
* Continuous serial monitoring
* Threshold-based decision making

---

## Components Used

| Component                 | Function                  |
| ------------------------- | ------------------------- |
| Arduino Uno               | Main Controller           |
| IR Sensor                 | Object Detection          |
| MQ-2 Gas Sensor           | Gas Leakage Detection     |
| LM35 Temperature Sensor   | Temperature Monitoring    |
| HC-SR04 Ultrasonic Sensor | Distance Measurement      |
| DC Motor                  | Temperature-Based Control |
| Stepper Motor             | Distance-Based Automation |
| LED                       | Gas Leakage Alert         |

---

## Pin Configuration

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

## Functional Description

### 1. IR Sensor Operation

The IR sensor detects the presence of an object.

#### Operation

**If object is detected:**

```text
Object Detected
```

**If object is not detected:**

```text
No Object Detected
```

---

### 2. Gas Leakage Detection and Alert System

The MQ-2 gas sensor continuously monitors gas concentration.

#### Operation

**If gas leakage is detected:**

```text
GAS LEAKAGE DETECTED !!!
```

* LED blinks continuously as an emergency warning indicator.

**If no gas is detected:**

```text
No Gas Detected
```

* LED remains OFF.

---

### 3. Temperature Monitoring and DC Motor Control

The LM35 temperature sensor continuously measures ambient temperature.

#### Threshold

```text
20°C
```

#### Operation

Temperature value is displayed on the Serial Monitor.

**If temperature ≥ 20°C**

* DC motor turns ON.

**If temperature < 20°C**

* DC motor turns OFF.

---

### 4. Ultrasonic Distance Measurement and Stepper Motor Control

The HC-SR04 ultrasonic sensor measures object distance.

#### Threshold

```text
15 cm
```

#### Operation

Distance value is displayed on the Serial Monitor.

**If distance < 15 cm**

* Stepper motor rotates clockwise.
* Stepper motor rotates anticlockwise.
* Automatic motion cycle is performed.

**If distance ≥ 15 cm**

* Stepper motor remains stopped.

---

## System Workflow

1. Read sensor values continuously.
2. Process sensor data.
3. Compare values with predefined thresholds.
4. Execute corresponding control actions.
5. Display sensor values and system status.
6. Repeat continuously.

---

## Circuit Diagram

The complete circuit includes:

* Arduino Uno
* MQ-2 Gas Sensor
* LM35 Temperature Sensor
* IR Sensor
* HC-SR04 Ultrasonic Sensor
* L293D Motor Driver
* DC Motor
* Stepper Motor
* LED Indicator

---

## Sample Serial Monitor Output

```text
===== SYSTEM STATUS =====

Object Detected
-------------------

No Gas Detected
-------------------

Temperature : 27.50 C
DC Motor ON
-------------------

Distance : 10.25 cm
Object Close
-------------------
```

---

## Folder Structure

```text
Embedded-Multi-Sensor-Monitoring-and-Control-System
│
├── code
│   └── data_acquisition_system.ino
│
├── circuit
│   ├── circuit_diagram.png
│   └── wiring_diagram.pdf
│
├── images
│   ├── serial_output1.png
│   └── serial_output2.png
│
├── README.md
└── LICENSE
```

---

## Applications

* Industrial Monitoring Systems
* Smart Safety Systems
* Environmental Monitoring
* Sensor-Based Automation
* Embedded Control Systems
* Academic Embedded Projects
* Laboratory Demonstrations

---

## Future Improvements

* IoT Integration
* Wi-Fi Based Monitoring
* Cloud Data Logging
* Mobile Application Interface
* LCD/OLED Display Integration
* Web Dashboard Monitoring
* Remote Control System

---

## Expected Outcome

The system accurately acquires sensor data, displays real-time values on the Serial Monitor, and automatically controls actuators according to predefined threshold conditions.

---

## Conclusion

This project successfully demonstrates real-time embedded data acquisition, sensor interfacing, threshold-based automation, and actuator control using Arduino Uno.

The system provides an effective platform for understanding embedded monitoring, sensor integration, and automation concepts commonly used in modern industrial and smart monitoring applications.

---

## Author

**Ritheshwaran A**
B.E. Electronics and Communication Engineering (ECE)
College of Engineering Guindy (CEG), Anna University
