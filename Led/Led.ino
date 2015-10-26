#include <Adafruit_NeoPixel.h>
 
#define PIN 0
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, PIN);
 
void setup() {
  pixels.begin();
  pixels.setBrightness(60);
}
 
void loop() {

  static uint8_t a = 0;
 
  for (uint8_t i = 0; i < 16; i++) {
    uint8_t c = 255 / ((i+a) % 16);
    pixels.setPixelColor(i, 0, 0, c);
  }

  a++;

  a = a % 16;
  
  pixels.show();
  delay(75);
}
