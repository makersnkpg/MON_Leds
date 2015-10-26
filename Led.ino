#include <Adafruit_NeoPixel.h>
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
 #include <avr/power.h>
#endif
 
#define PIN 0
 
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, PIN);
 
uint8_t offset = 0;
uint32_t prevTime;
 
void setup() {
#ifdef __AVR_ATtiny85__ // Trinket, Gemma, etc.
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  pixels.begin();
  pixels.setBrightness(60);
}

uint32_t color(uint8_t r, uint8_t g, uint8_t b)
{
  return r << 16 | g << 8 | b;
}
 
void loop() {

  static uint8_t a = 0;
 
  for (uint8_t i = 0; i < 16; i++) {
    uint8_t c = 255 / ((i+a) % 16);
      pixels.setPixelColor(i, color(0, 0, c));
  }

  a++;

  a = a % 16;
  
  pixels.show();
  delay(75);
}
