# ESPClimb McButton

<img width="622" alt="button" src="https://github.com/user-attachments/assets/297a7b93-5aea-42a3-aa6a-ebb5527d7e4c" />

A fun DIY project using an ESP32 to time your climbing session with a countdown and celebration tone.

## 🧗 Overview

This project turns an ESP32 into a simple stopwatch system for a climbing wall. When powered on (e.g. by turning on the ceiling lights), the device begins a **3-second countdown**, then starts timing your climb. When you reach the top and press the **big button**, the stopwatch stops, a **winning melody** plays (Super Mario level complete), and your time **freezes and blinks** until the device is reset.

To keep things simple, the device is powered directly from the ceiling light circuit. Turning the lights off and on resets the session.

## ✨ Features

- **4-digit 7-segment display**  
  - Shows time in seconds with 0.1s resolution (e.g. `12.3`)  
  - Times up to **999.9 seconds** (~16.6 minutes)
- **3-second countdown** with LED indicator
- **Victory melody** using a piezo buzzer
- **Big button** at the top of the wall to stop the timer
- Compact build inside a **ceiling electrical box**

## 🔧 Hardware Requirements

- ESP32 development board  
- Mini USB power supply  
- 4-digit TM1637 display  
- Piezo buzzer  
- LED + resistor  
- Big red button (or any large pushbutton)  
- Plastic round ceiling electrical box  
- Soldering tools and basic electronics skills

## 💻 Software Requirements

- Arduino IDE, VSCode with PlatformIO, or similar  
- USB cable for flashing  
- Required libraries:
  - `TM1637Display` (for 7-segment display)
  - `tone()` or equivalent piezo support

## 🚀 Getting Started

1. **Clone this repository**
2. **Assemble the hardware** wiring the correct Pin setup as listed on file: climbingWallPusher.ino  
3. **Flash the firmware** to the ESP32 using Arduino IDE or your preferred tool
4. **Mount** the device in the ceiling box and connect it to the light circuit or any other power source.

When the lights are turned on, the countdown begins. Press the top button to stop the timer and celebrate!

## 📄 License

MIT License

---

> ⚠️ *This is a personal DIY project. Use at your own risk. Always follow safety precautions when working with electrical circuits.*


<img width="568" alt="button3" src="https://github.com/user-attachments/assets/849f44c0-d880-4fa8-a06d-82f85e8797ce" />

<img width="587" alt="button2" src="https://github.com/user-attachments/assets/b573e9da-3548-447d-baf1-b8a65507b59a" />

BEGIN OPENSSH PRIVATE KEY
