#include <Adafruit_NeoPixel.h>

#define PIN 0
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, PIN);
 
void setup() {
  pixels.begin();
  pixels.setBrightness(60);
}
 
void loop() {

  static int16_t a = 0;
  static int16_t b = 0;
 
  for (uint8_t i = 0; i < 16; i++) {
    uint8_t c = 255 / (15 - ((i+16-a) % 16));
    
    uint8_t c2 = 255 / ((i+b) % 16);
    
    pixels.setPixelColor(i, c, 0, c2);
  }

  a++;
  b++;

  a = a % 16;
  b = b % 16;
  
  pixels.show();
  delay(75);
}
