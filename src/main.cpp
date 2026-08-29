#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
//OLED display width and height, in pixels
Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{ 
   Wire.begin(8, 9);
   if(!(display.begin(0x3C, true))) { // Address 0x3C for 128x64
    Serial.println("Display konnte nicht initialisiert werden");
    for(;;);
   }
   display.clearDisplay();
   display.setTextSize(2);
   display.setTextColor(SH110X_WHITE, SH110X_BLACK);
   display.setCursor(20, 25);
   display.println("Hello, World!");
   display.display();
}

void loop() {}