# Smart Helmet-Based Bike Safety System

A low-cost embedded safety system designed to encourage helmet usage among two-wheeler riders by controlling bike ignition based on helmet detection and providing real-time alerts when the helmet is removed while riding.

## 🚀 Features

* Detects whether the rider is wearing the helmet.
* Transmits helmet status wirelessly using 433 MHz RF communication.
* Prevents bike ignition when the helmet is not worn.
* Monitors helmet status continuously while the bike is running.
* Activates a buzzer and LED when the helmet is removed while riding.
* Automatically disables the bike ignition when the helmet is removed.
* LCD provides real-time system status.
* Designed as a low-cost and practical safety solution.

## 🏗️ System Architecture

The system consists of two major modules:

### 1. Helmet Unit — Transmitter

The helmet unit contains:

* Helmet detection switch
* 433 MHz RF transmitter
* Battery

The switch detects whether the helmet is being worn and sends the corresponding status wirelessly to the bike unit.

### 2. Bike Unit — Receiver

The bike unit contains:

* 433 MHz RF receiver
* Arduino / ATmega328 microcontroller
* Relay
* Buzzer
* LED
* LCD

The microcontroller processes the received helmet status and controls the bike ignition and alert system.

## 🔄 Working

```text
Helmet Detection
       ↓
Helmet Worn?
   ↙       ↘
 YES       NO
  ↓         ↓
RF Signal  Ignition OFF
  ↓
RF Receiver
  ↓
Microcontroller
  ↓
Ignition Control
  +
Real-Time Monitoring
  ↓
Helmet Removed?
  ↓
Buzzer + LED Alert
  ↓
Ignition OFF
```

## 💻 Software

* Embedded C / C++
* Arduino IDE
* Digital input/output
* Conditional statements
* Relay control
* Buzzer and LED control
* LCD interfacing

## 🔧 Hardware

| Component                   | Quantity |
| --------------------------- | -------: |
| Arduino Uno / ATmega328     |        1 |
| 433 MHz RF Transmitter      |        1 |
| 433 MHz RF Receiver         |        1 |
| Helmet Switch / Push Button |        1 |
| Relay Module                |        1 |
| Buzzer                      |        1 |
| LED + Resistor              |      2–3 |
| Battery                     |        1 |
| Connecting Wires            |        — |
| Breadboard / PCB            |        1 |

Estimated component cost: **₹800–₹1200**

## 🧠 Control Logic

### Helmet worn

```text
Helmet detected
      ↓
RF signal = HIGH
      ↓
Microcontroller receives signal
      ↓
Ignition ON
```

### Helmet not worn before starting

```text
Helmet not detected
      ↓
RF signal = LOW
      ↓
Ignition OFF
```

### Helmet removed while riding

```text
Helmet status changes
HIGH → LOW
      ↓
Buzzer ON
LED ON
      ↓
Warning displayed on LCD
      ↓
Ignition OFF
```

## 📁 Repository Structure

```text
smart-helmet-bike-safety-system/
│
├── code/
│   ├── helmet_transmitter/
│   │   └── helmet_transmitter.ino
│   │
│   └── bike_receiver/
│       └── bike_receiver.ino
│
├── circuit/
│   └── circuit-diagram.png
│
├── documentation/
│   └── project-report.pdf
│
├── images/
│   └── project-setup.jpg
│
└── README.md
```

## 🎯 Objective

The primary objective of this project is to reduce unsafe riding caused by failure to wear a helmet by creating an automatic helmet-dependent ignition system with real-time rider alerts.

## 🔮 Future Improvements

Possible future improvements include:

* More robust helmet-wearing detection.
* Improved wireless communication reliability.
* Compact PCB-based implementation.
* Rechargeable battery integration.
* Vehicle-independent installation.
* Additional rider safety monitoring features.

## 👥 Project Contribution

Contributed to the design, implementation, testing and documentation of the Smart Helmet-Based Bike Safety System, including hardware integration, embedded programming, system logic and project presentation.

## 📜 License

This project is intended for educational and prototype purposes.
