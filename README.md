# ESP32-S3 Temperature Monitoring and Fan Control

## Overview
The purpose of the circuit is to measure temperature and humidity and provide cooling if a specified temperature threshold is crossed. These values are measured by the DHT22 sensor, display on an OLED display screen and read by the ESP32 microcontroller. The microcontroller sends the appropriate signal, turning the fan on if the threshold is met or crossed.

## Features 
Temperature and humidity measurement

Live readings on the OLED display

Automatic fan switching based on a temperature threshold

Serial output for monitoring and debugging

## Hardware Components
| Component | Purpose |
|---|---|
| ESP32-S3 supermini| Main microcontroller |
| DHT22 | Measures temperature and humidity |
| OLED display (SH1106G) | Displays sensor readings |
| MOSFET (IRLZ44N) | Switches the fan on and off |
| Diode (1N4007) | Protects against voltage spikes |
| 4.7kΩ resistor | Limits the brief current flowing while the Gate charges or discharges |
| 10kΩ  pulldown resistor | Provides a path from Gate to GND so the MOSFET stays off when the GPIO is floating |
| DC fan | Provides cooling |

## How It Works
The ESP32 microcontroller reads the temperature and humidity values measured by the DHT22 sensor. The values are then flashed on the OLED display, whose data line connects to GPIO8. The microcontroller compares the temperature value to a configured threshold and sends a HIGH or LOW signal. The MOSFET, whose Gate is connected to the selected GPIO12, switches the fan accordingly. When the temperature condition is met, the ESP32-S3 sets GPIO12 to HIGH, activating the N-channel MOSFET. The MOSFET acts as an electronic switch, allowing current to flow from the 5 V supply through the fan and then through the MOSFET to ground. When the GPIO output is LOW, the MOSFET switches off and interrupts the fan's current path. The flyback diode connected over the fan's wires serves to contain the voltage spike caused by the collapse of the fan's magnetic field, circulating the current until the energy dissipates.

## Circuit and Wiring
![ESP32-S3 temperature monitoring and fan control circuit]
The following table summarizes the connections between the ESP32-S3, the sensors, the display, and the fan control circuit.

| Component | Pin / Terminal | ESP32-S3 Pin / Connection |
|---|---|---|
| DHT22 | VCC | 3.3 V |
| DHT22 | GND | GND |
| DHT22 | DATA | GPIO10 |
| OLED display (SH1106G) | VCC | 3.3 V |
| OLED display (SH1106G) | GND | GND |
| OLED display (SH1106G) | SDA | GPIO8 |
| OLED display (SH1106G) | SCL | GPIO9 |
| MOSFET (IRLZ44N) | Gate | GPIO12, through the gate resistor |
| MOSFET (IRLZ44N) | Source | GND |
| MOSFET (IRLZ44N) | Drain | Fan negative terminal |
| DC fan | Positive terminal | +5 V supply |
| Diode (1N4007) | Cathode (marked end) | Fan positive terminal |
| 1N4007 diode | Anode | Fan negative terminal |
| Gate pulldown resistor | One end | MOSFET Gate |
| Gate pulldown resistor | Other end | GND |

**Note:** The ESP32-S3, fan supply, and MOSFET source must share a common ground for the control signal to work correctly.
## Software and Setup
### Development Environment
- **IDE:** Visual Studio Code
- **Build system:** PlatformIO
- **Framework:** Arduino
- **Target board:** ESP32-S3 SuperMini

### Libraries
The project uses the following libraries:
- `DHT sensor library` — for reading temperature and humidity from the DHT22 sensor.
- `Adafruit SH110X` — for controlling the SH1106G OLED display.
- `Adafruit GFX Library` — for rendering text and graphics on the display.

### Setup Instructions

1. Install [Visual Studio Code](https://code.visualstudio.com/).
2. Install the [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode).
3. Clone this repository and open the project folder in Visual Studio Code.
4. Allow PlatformIO to install the required dependencies specified in `platformio.ini`.
5. Connect the ESP32-S3 board to your computer via USB.
6. Build the project using PlatformIO.
7. Upload the firmware to the board.
8. Open the PlatformIO Serial Monitor at 115200 baud to view the serial output.

### Configuration

The board configuration, framework, library dependencies, and build settings are defined in `platformio.ini`.

The temperature threshold and GPIO assignments can be adjusted in the source code as needed.
