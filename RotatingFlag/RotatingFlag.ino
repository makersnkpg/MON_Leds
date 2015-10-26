#include <Adafruit_NeoPixel.h>

#define PIN 0
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, PIN);
 
void setup()
{
  pixels.begin();
  pixels.setBrightness(60);
}

uint32_t leds[16];

uint32_t color(uint8_t r, uint8_t g, uint8_t b)
{
  return ((uint32_t)r << 16) | ((uint32_t)g <<  8) | b; 
}

int8_t o = 0;

void loop()
{
  for (uint8_t i = 0; i < 16; ++i) {
    leds[i] = color(0, 0, 255);
  }

  leds[(2+o)%16] = color(255, 255, 0);
  leds[(3+o)%16] = color(255, 255, 0);

  leds[(6+o)%16] = color(255, 255, 0);
  leds[(7+o)%16] = color(255, 255, 0);

  leds[(10+o)%16] = color(255, 255, 0);
  leds[(11+o)%16] = color(255, 255, 0);

  leds[(14+o)%16] = color(255, 255, 0);
  leds[(15+o)%16] = color(255, 255, 0);
 
  for (uint8_t i = 0; i < 16; i++) {
    pixels.setPixelColor(i, leds[i]);
  }

  o = (o + 1) % 16;
  
  pixels.show();
  delay(75);
}
