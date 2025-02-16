#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "helper.h"
#include "bitmap_resources.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // OLED I2C address

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
  Serial.begin(9600);

  // Display initialization
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed
  }

  pinMode(LED_BUILTIN, OUTPUT); // Status LED

  display.clearDisplay();
  // display.drawRect(0, 0, 128, 64, WHITE);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(20, 20);
  display.print("Flipper Zero");
  display.setCursor(20, 35);
  display.print("Ultimate");
  display.setCursor(20, 50);
  display.print("All-In-One");
  display.display();

  for (;;)
    ;

  for (int pin = 8; pin < 12; pin++)
  {
    pinMode(pin, OUTPUT);
  }
}

void loop()
{
  display.setTextSize(2);
  display.setTextColor(WHITE);

  for (int num = 0; num < 16; num++)
  {
    display.clearDisplay();
    display.setCursor(0, 20);
    display.println("MUX ch. " + String(num));
    display.println("MOSFET " + String(num + 1));
    display.display();

    bool *bits = Helper::convertToBoolArray(num, nullptr);

    for (int pin = 8; pin < 12; pin++)
      digitalWrite(pin, bits[11 - pin]);

    delay(400);
    delete[] bits;
  }
}