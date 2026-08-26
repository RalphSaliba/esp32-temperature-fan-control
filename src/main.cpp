#include <Arduino.h>
#include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
// OLED display width and height, in pixels
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
   // Wire.begin(8, 9);
    //if(!(display.begin(SSD1306_SWITCHCAPVCC, 0x3C))) {
    // Serial.println("Allokation fehlgeschlagen");
    //for(;;);
   // }
   // display.clearDisplay();
   // display.setTextSize(2);
   // display.setTextColor(SSD1306_WHITE, SSD1306_BLACK);
   // display.setCursor(20, 25);
   // display.println("Hello, World!");
   // display.display();
   Serial.begin(115200);
   delay(2000);
}

void loop() {
    Serial.println("Hello");
    delay(1000);
}