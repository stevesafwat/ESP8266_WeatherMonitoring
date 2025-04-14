# 🌦️ IoT Weather Station with ESP8266 – Real-Time Environmental Monitoring
Monitor temperature, humidity, rain, and light levels remotely using an ESP8266, DHT11, rain sensor, and LDR—displayed on an LCD and Blynk IoT cloud!

_____________________________________________________________________________________________________________________________________________________________

# 📌 Project Overview
This IoT-based weather monitoring system uses an ESP8266 microcontroller to collect real-time environmental data from multiple sensors:

🌡️ DHT11 – Measures temperature and humidity

🌧️ Raindrop Sensor – Detects rainfall intensity (analog)

☀️ LDR (Light Sensor) – Monitors ambient light levels (digital)

The data is displayed locally on a 16x2 I2C LCD and sent wirelessly to the Blynk IoT platform for remote monitoring via smartphone.

_______________________________________________________________________________________________________________________________________________________________

# ✨ Key Features
✅ Real-time sensor readings (updated every 2 seconds)
✅ Blynk Cloud Integration – View data remotely via virtual pins (V0-V3)
✅ Local LCD Display – Shows temperature, humidity, rain, and light status
✅ Wi-Fi Connectivity – Connects to a mobile hotspot for IoT functionality
✅ Error Handling – Checks for invalid sensor readings

_______________________________________________________________________________________________________________________________________________________________

# 🛠️ Hardware Components
ESP8266 (NodeMCU) – Wi-Fi-enabled microcontroller

DHT11 Sensor – Temperature & humidity

Raindrop Sensor (Analog) – Rain detection

LDR (Light Dependent Resistor) – Ambient light sensing

I2C 16x2 LCD – Local data display

Breadboard & Jumper Wires – Circuit connections

_______________________________________________________________________________________________________________________________________________________________


# 📡 Software & Libraries Used
Arduino IDE – Programming environment

Blynk IoT Platform – Remote monitoring & alerts

Libraries:

ESP8266WiFi (Wi-Fi connectivity)

BlynkSimpleESP8266 (Blynk cloud integration)

DHT.h (DHT11 sensor interface)

LiquidCrystal_I2C (LCD control)

Wire.h (I2C communication)

_______________________________________________________________________________________________________________________________________________________________

# 🔧 How It Works
Sensors collect data (temperature, humidity, rain, light).

ESP8266 processes readings and sends them to:

16x2 LCD (local display)

Blynk App (remote monitoring via Wi-Fi)

Blynk Dashboard visualizes data in real time.

System checks for sensor errors (e.g., DHT11 failures).

_______________________________________________________________________________________________________________________________________________________________

# 🚀 Potential Improvements
🔋 Low-Power Mode – Battery optimization for outdoor use

📶 MQTT/ThingSpeak Integration – Alternative IoT platforms

🌧️ Waterproof Enclosure – For outdoor deployment

🔔 Blynk Notifications – Alerts for rain or extreme temperatures

_______________________________________________________________________________________________________________________________________________________________

# 🎯 Ideal For
IoT enthusiasts learning sensor integration

Smart agriculture (rain & humidity monitoring)

Home weather stations (indoor/outdoor tracking)

STEM/Educational projects (Arduino + ESP8266)

_______________________________________________________________________________________________________________________________________________________________

# Circuit Wiring Description
Power Connections:

Connect all components to a common ground (GND) on the ESP8266

Provide 3.3V or 5V power to each sensor as needed

Sensor Connections:

DHT11 Sensor:

Data pin → ESP8266 D1 (GPIO5)

VCC → 3.3V/5V

GND → GND
--------------------------------
Raindrop Sensor (Analog):

Signal pin → ESP8266 A0

VCC → 5V

GND → GND

LDR (Light Sensor):

Signal pin → ESP8266 D2 (GPIO4)

VCC → 3.3V/5V

GND → GND
--------------------------------
I2C LCD Display (16x2):

SDA → ESP8266 D5 (GPIO14)

SCL → ESP8266 D6 (GPIO12)

VCC → 5V

GND → GND
--------------------------------
Important Notes:

The LCD uses I2C address 0x27 (as defined in code)

Raindrop sensor outputs analog values (0-1023) mapped to 0-100% in code

LDR provides digital output (HIGH/LOW) based on light threshold

All sensors share common ground with ESP8266
---------------------------------------------

Troubleshooting Tips:

If LCD doesn't work, verify I2C address with a scanner

Check all power connections if sensors aren't responding

Ensure proper WiFi credentials for Blynk connection

Verify sensor pins match the code definitions

