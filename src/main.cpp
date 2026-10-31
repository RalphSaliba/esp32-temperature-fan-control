#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#include <DHT.h>

#define DHTPIN 10
#define DHTTYPE DHT22
#define MOSFETPIN 12
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
float threshold = 10.0;

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
   Serial.begin(115200);
   Wire.begin(8, 9);
   if(!(display.begin(0x3C, true))) { 
    Serial.println("Display konnte nicht initialisiert werden");
    for(;;);
   }
   display.setTextSize(1);
   display.setTextColor(SH110X_WHITE, SH110X_BLACK);
   dht.begin();
   Serial.println("Sensor initialisiert");
   digitalWrite(MOSFETPIN, LOW);
   pinMode(MOSFETPIN, OUTPUT);
}

void loop() {
  delay(2000);
  display.clearDisplay();
  display.setCursor(0, 0);
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
   display.println("Sensorfehler");
   display.display();
   digitalWrite(MOSFETPIN, LOW);
   return;
  }
    if (t >= threshold) digitalWrite(MOSFETPIN, HIGH);
    else digitalWrite(MOSFETPIN, LOW);
    display.print("Temperature: ");
    display.print(t);
    display.println("K");
    display.print("Humidity: ");
    display.print(h);
    display.println("%");
    display.display();
}