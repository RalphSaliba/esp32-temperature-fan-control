#include <Arduino.h>
#include <DHT.h>

#define DHTPIN 8
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
   Serial.begin(115200);
   dht.begin();
   Serial.println("Sensor initialisiert");
}

void loop() {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) {
   Serial.println("Die Daten könnten vom Sensor nicht gelesen werden");
   return;
  }
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println("°C");
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println("%");
    delay(2000);
}