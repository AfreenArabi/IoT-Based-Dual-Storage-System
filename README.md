# IoT-Based Dual Storage System for Efficient Post-Harvest Management

## Project Overview

The **IoT-Based Dual Storage System for Efficient Post-Harvest Management** is designed to monitor and manage storage conditions for agricultural crops using IoT technology.

The system consists of two independent storage sections:

- **Long-Duration Crops:** Onion and Potato
- **Short-Duration Crops:** Tomato and Mirchi

An ESP32-based monitoring system continuously collects environmental parameters such as temperature, humidity, CO, CH₄, and light conditions. The measured values are compared with predefined threshold limits.

When abnormal conditions are detected, the system activates the exhaust fan and buzzer to maintain suitable storage conditions and provide alerts.

The storage conditions can be monitored locally through a **16×2 LCD**, remotely through **ThingSpeak Cloud**, and through a **mobile application**. The system is powered using a solar panel with rechargeable battery backup.

## Objectives

- Monitor storage conditions continuously.
- Provide separate storage management for long-duration and short-duration crops.
- Monitor temperature and humidity.
- Monitor gas concentration using MQ sensors.
- Monitor light conditions using an LDR sensor.
- Compare sensor values with predefined threshold limits.
- Automatically activate the exhaust fan during abnormal conditions.
- Provide alert indications using a buzzer.
- Display real-time values on a 16×2 LCD.
- Upload sensor data to ThingSpeak Cloud.
- Provide remote monitoring through a mobile application.
- Reduce post-harvest crop losses.
- Support reliable operation using solar power and battery backup.

## System Architecture

The proposed system consists of two independent storage sections for different categories of crops.

Each storage section contains an ESP32 microcontroller, environmental sensors, a 16×2 LCD display, exhaust fan, and buzzer.

The ESP32 collects and processes the sensor data. The measured values are compared with predefined threshold limits. Based on the conditions, the system controls the exhaust fan and buzzer.

Through Wi-Fi connectivity, the monitored data is uploaded to ThingSpeak Cloud. The same storage information can also be accessed through the mobile application.

The system architecture and block diagram are provided separately in the `Diagrams` folder.

## Storage Sections

### Long-Duration Storage

- Onion
- Potato

### Short-Duration Storage

- Tomato
- Mirchi

## Hardware Components

- ESP32 Microcontroller
- DHT11 Temperature and Humidity Sensor
- MQ-135 Gas Sensor
- MQ-4 Gas Sensor
- LDR Sensor
- 16×2 LCD Display
- DC Exhaust/Cooling Fan
- Buzzer
- Solar Panel
- Rechargeable Lithium-Ion Battery
- Connecting Wires

The ESP32 performs sensor data acquisition, data processing, threshold comparison, actuator control, LCD display, and Wi-Fi communication.

## Software and Cloud Platform

- Arduino IDE
- ESP32
- Wi-Fi
- ThingSpeak Cloud
- Mobile Application

The Arduino IDE is used for programming the ESP32 and integrating the required libraries for Wi-Fi, ThingSpeak, DHT sensors, and LCD communication. It is also used for debugging and checking sensor readings through the Serial Monitor.

The ESP32 source codes for the long-duration and short-duration crop storage sections are available in the `Arduino_Code` folder.

## Working Methodology

### 1. System Initialization

The ESP32 initializes the connected sensors, LCD, Wi-Fi connection, exhaust fan, and buzzer.

### 2. Sensor Data Collection

The sensors continuously collect environmental information from the storage sections.

### 3. Data Processing

The ESP32 processes the sensor readings and compares them with predefined threshold values.

### 4. Automatic Control

When abnormal environmental conditions are detected, the exhaust fan is activated and the buzzer provides an alert.

### 5. LCD Monitoring

The 16×2 LCD displays the real-time monitored parameters and alert information.

### 6. ThingSpeak Cloud Monitoring

The ESP32 transmits sensor data through Wi-Fi to ThingSpeak Cloud for real-time monitoring and graphical visualization.

### 7. Mobile Application

The mobile application provides remote monitoring of the storage conditions and related information.

### 8. Continuous Monitoring

The system continuously performs sensing, processing, threshold comparison, automatic control, and data transmission.

## Experimental Results

The system was experimentally tested using separate setups for long-duration and short-duration crops.

The experimental results include:

- Long-duration crop storage hardware setup
- Short-duration crop storage hardware setup
- Real-time LCD monitoring outputs
- Temperature and humidity alert notifications
- ThingSpeak cloud graphs
- Mobile application monitoring outputs

The project includes ThingSpeak results for **Onion, Potato, Tomato, and Mirchi**, along with separate mobile monitoring interfaces for the crops.

## Experimental Setup

The hardware setup demonstrates the integration of the ESP32, sensors, LCD, exhaust fan, buzzer, and power supply for crop storage monitoring.

The experimental setup images are available in the `Hardware_Setup` folder.

## LCD Monitoring Results

The 16×2 LCD provides real-time local monitoring of the storage parameters.

The LCD output images include normal storage conditions and alert conditions such as:

- Temperature Alert
- Humidity Alert
- Carbon Monoxide Alert
- Methane Alert
- Onion Storage Conditions
- Potato Storage Conditions
- Tomato Storage Conditions
- Mirchi Storage Conditions

The LCD result images are available in the `LCD_Results` folder.

## ThingSpeak Results

ThingSpeak Cloud is used to visualize the monitored sensor data through graphical representations.

The project includes cloud graphs for:

- Onion Storage
- Potato Storage
- Tomato Storage
- Mirchi Storage

The ThingSpeak result images are available in the `ThingSpeak_Results` folder.

## Mobile Application Results

The mobile application provides remote access to the monitored storage information.

The project includes mobile monitoring interfaces for:

- Onion
- Potato
- Tomato
- Mirchi

The mobile application result images are available in the `Mobile_Application_Results` folder.

The LCD, ThingSpeak Cloud, and mobile application represent the same monitored storage conditions through different interfaces:

- **LCD:** Local monitoring
- **ThingSpeak:** Cloud-based monitoring and graphical visualization
- **Mobile Application:** Remote monitoring

## Advantages

- Continuous environmental monitoring
- Separate monitoring for different crop durations
- Automatic ventilation control
- Buzzer-based alerts
- Real-time LCD monitoring
- ThingSpeak Cloud monitoring
- Mobile application monitoring
- Solar power with battery backup
- Improved storage management
- Reduction of post-harvest losses

## Applications

- Agricultural crop storage
- Farm-level storage systems
- Agricultural warehouses
- Cold storage facilities
- Vegetable storage facilities
- Rural crop storage and collection centers

## Conclusion

The **IoT-Based Dual Storage System for Efficient Post-Harvest Management** provides continuous monitoring and automated management of storage conditions for long-duration and short-duration crops.

The ESP32 processes sensor data, compares environmental conditions with predefined limits, and controls the exhaust fan and buzzer when required.

The system provides local monitoring through the **16×2 LCD** and remote monitoring through **ThingSpeak Cloud** and the **mobile application**.

The integration of IoT monitoring, automated control, cloud connectivity, mobile monitoring, and solar-powered operation provides an effective approach for improving crop storage management and reducing post-harvest losses.

Overall, the proposed system demonstrates how IoT-based sensing, automatic control, cloud monitoring, and mobile technology can be integrated to support reliable and efficient post-harvest crop storage.
