# Demand-Actuated Traffic Control System 🚦

![C++](https://img.shields.io/badge/Language-C++-blue.svg)
![Platform](https://img.shields.io/badge/Platform-Arduino-00979D.svg)
![Architecture](https://img.shields.io/badge/Architecture-FSM-success.svg)

## 📌 Project Overview
A smart, demand-actuated traffic light controller built with C++ for the Arduino platform. Instead of relying on traditional, execution-blocking time delays, this system utilizes an **Asynchronous Finite State Machine (FSM)**. 

It dynamically monitors a side-road via an HC-SR04 ultrasonic sensor and triggers state transitions in real-time while maintaining strict fairness cooldowns for the main traffic road.

## 🎬 Demonstration
*(Watch the system execute non-blocking, edge-triggered state transitions)*

![Traffic System Demo](./Simulation_demo.mp4) 
> *Note: Simulation recorded in Tinkercad.*

## ⚙️ Core Engineering Features
This project was developed with a focus on firmware optimization and memory management:
* **Non-Blocking Architecture:** Replaced all `delay()` functions with `millis()` chronometer tracking, allowing the microcontroller to poll the sensor continuously without freezing execution.
* **Finite State Machine (FSM):** Implemented an enumerated FSM (`greenState`, `yellowState`, `redState`) to manage logic predictably and cleanly.
* **Edge-Triggered Detection:** Utilized boolean state flags to ensure the system reacts to the exact moment of vehicle detection rather than spamming continuous level-triggered outputs.

## 🔌 Hardware Architecture
* **Microcontroller:** Arduino Uno (ATmega328P)
* **Sensor:** HC-SR04 Ultrasonic Distance Sensor
* **Actuators:** 3x Standard LEDs (Red, Yellow, Green)
* **Passives:** 3x 220Ω Current-Limiting Resistors

### Schematics & Wiring
* 🖼️ **[View Breadboard Wiring Diagram](./Ultrasonic_FSM_Controller.png)**
* 📄 **[Download Official Circuit Schematic (PDF)](./Schematics.pdf)**
