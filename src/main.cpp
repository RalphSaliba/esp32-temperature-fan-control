#include <Arduino.h>

void setup()
{
    Serial.begin(115200);
    delay(3000); // Gives Windows time to mount the USB CDC port
}

void loop()
{
    Serial.println("HELLO FROM ESP32-S3!");
    delay(1000);
}