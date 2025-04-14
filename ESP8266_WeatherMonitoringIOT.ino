#include <ESP8266WIFI.h> //ESP8266 WIFI Master Library for Connection
#include <BlynksimplesP8266.h> //Blynk Library for communicating between ESP8266 and Blynk Cloud
#include <DHT.h> //DHT11 Library to initialize the sensor and read temperature and humidity values
#include <Wire.h> //Wire Library is used for I2C communication between the I2C Module and LCD 16x2
#include <LiquidCrystal_I2C.h> // 16x2 LCD Library is used to initialize the LCD Display and print the sensor values

//#include is used to use libraries that is installed in Arduino IDE

char auth[] = "VA_8gE102bI0h_WMTg-M9U6SDJKMuQk"; //Blynk Cloud Authentication Token to communicate with ESP8266
char ssid[] = "OPPO F11 Pro"; //Mobile-Hotspot SSID
char pass[] = "steve123"; //Mobile-Hotspot Password

#define DHTPIN D1    // DHT11 sensor is connected to pin D1
#define DHTYPE DHT11   // DHT11 is our sensor type
#define RAINDROPPIN A0  // Raindrop sensor is connected to Analog pin A0
#define LDRPIN D2    // LDR sensor is connected to pin D2

//#defining is used to show the user where the sensors are connected

DHT dht(DHTPIN, DHTYPE); //initializes the pins and type of the DHT11

const uint8_t LCD_AODR = 0x27; // Set the I2C address of the LCD display

LiquidCrystal_I2C led(LCD_AODR, 16, 2); // Set the I2C address of the LCD display

void setup() //starting the project
Serial.begin(9600); //start communication between ESP8266 and Arduino IDE Serial Monitor at 9600 bits per second
Blynk.begin(auth, ssid, pass); //starting Blynk Cloud by sending Authentication Token,Mobile-Hotspot SSID, and Password
dht.begin(); //start the DHT to initialize and work

Wire.begin(D5, D6); //wiring connection of SDA and SQL to initialize I2C Module and 16x2 LCD

lcd.begin(); //Start the 16x2 LCD

lcd.backlight(); //Turn on LCD Backlight

// Print the headings on the LCD display
lcd.setCursor(0, 0);
lcd.print("R: L: ");
lcd.setCursor(0, 1);
lcd.print("H: T: ");
}

void loop() //functions to run continuously on the ESP8266
{
    delay(2000);  // Wait for 2 seconds before taking a new reading
    float humidity = dht.readHumidity(); //reads and sends humidity value to Blynk and LCD
    float temperature = dht.readTemperature(); //reads and sends temperature value to Blynk and LCD
    int raindrop = analogRead(RAINDROPPIN); // Read the analog input from the raindrop sensor
    raindrop = map(raindrop, 0, 1023, 0, 100); // Map the analog input to a range of 0-100
    int light = digitalRead(LDRPIN); // Read the digital input from the LDR sensor
    if (isnan(humidity) || isnan(temperature)) { //isnan = no valid readings
    Serial.println("Failed to read from DHT sensor!");
    return;
}

Blynk.virtualWrite(V0, raindrop); // Send the raindrop value to Blynk virtual pin V0
Blynk.virtualWrite(V1, humidity); // Send humidity value to Blynk virtual pin V1
Blynk.virtualWrite(V2, temperature); // Send temperature value to Blynk virtual pin V2
Blynk.virtualWrite(V3, light); // Send the light value to Blynk virtual pin V3

// Print the values on the LCD display
    lcd.setCursor(2, 0);
    lcd.print(raindrop);
    lcd.setCursor(10, 0);
    lcd.print(light);
    lcd.setCursor(2, 1);
    lcd.print(humidity);
    lcd.setCursor(10, 1);
    lcd.print(temperature);
}