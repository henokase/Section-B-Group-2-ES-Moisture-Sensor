# Section-B-Group-2-ES-Moisture-Sensor

## GROUP MEMBERS
 1. Fissiha Akele --- ETS0675/14
 2. Haylemeskel Haylemaryam --- ETS0756/14
 3. Gelead Worku --- ETS0689/14
 4. Haymanot Aweke --- ETS0757/14
 5. Henok Asegdew --- ETS0776/14
 6. Hemenawit Girma --- ETS0772/14

# 🌱 Soil Moisture Sensor with Buzzer Alert (Arduino)

This project reads soil moisture levels using an analog soil moisture sensor and triggers a buzzer when the soil is too dry. It provides real-time feedback via the Serial Monitor.

## 🛠️ Components Used

Component          
-----------------------
Arduino Uno/Nano
Soil Moisture Sensor
Buzzer
Jumper Wires
Breadboard

---

## 🔌 Wiring

| Arduino Pin | Component                | Notes                            |
|-------------|--------------------------|----------------------------------|
| A0          | Soil Sensor (Analog Out) | Analog signal read               |
| GND         | Soil Sensor & Buzzer GND | Shared ground                    |
| VCC         | Soil Sensor              | 5V power                         |
| D8          | Buzzer                   | Digital output to control buzzer |

---

## 🧠 How It Works

- The soil moisture sensor outputs an analog value depending on moisture levels:
  - **Wet soil → Lower values (~300)**
  - **Dry soil → Higher values (~800)**
- This value is mapped to a percentage (0–100%).
- If the moisture drops below **30%**, a buzzer turns on to indicate dry soil.
- Status is printed in the Serial Monitor every 2 seconds.

---

## 💻 Arduino Code

The code is located in [`soil-moisture.ino`](./soil-moisture.ino).

```cpp
// Sample Output in Serial Monitor:
Moisture: 22%
Status: Soil is DRY
--------------------------
Moisture: 55%
Status: Soil is OK
--------------------------
