//Fun patterns by Ingela Rossing

#include <Adafruit_NeoPixel.h>

#define PIN 0 // assign constant PIN to the pin D0~ on the Gemma

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, PIN);

//**********************************************************************************************
// MODIFIABLE PARAMETERS -- PERSONALIZE YOUR GEMMA NEOPIXELS HERE
//**********************************************************************************************
//
// CHOOSE BLINKING PATTERN
// 
// 0: LIGHT YOUR FIRST PIXEL
// 1: COLOR-WORM
// 2: LIGHT-WORM

uint8_t  myPattern = 1; // ← Change this value to your desired pattern

// CHOOSE COLOR PALETTE HERE
// 
// 0: REDS-ORANGE
// 1: BLUE-LILAC
// 2: GREEN-YELLOW
// 3: PINK-PURPLE
// 4: TURQUOISE
// 5: RAINBOW

uint8_t myColorChart = 5; // ← Change this value to your desired color palette

// CHOOSE A SPEED SETTING HERE
//
// 0: FAST
// 1: MEDIUM
// 2: SLOW 

uint8_t mySpeed = 2; // ← Change this value to your desired speed

//**********************************************************************************************
// FROM HERE THE CODE STARTS
//**********************************************************************************************

// UTILITY VARIABLES
uint32_t prevTime; // Utility variable for timing
uint32_t delayTime; // Utility variable for timing
uint32_t color = 0xffffff; //default white
uint8_t offset = 0; // Current position of moving pattern
uint8_t c_offset = 0; // Current position within colour chart
uint8_t  i, j;
uint8_t red,green,blue,pixel;
uint32_t t;
uint32_t c = 0;

// Colors, hexadecimal code:
uint32_t myColors[][6] = {{0xff0000, 0xff3300, 0xff6600, 0xffcc00, 0xffff00}, // reds-orange
{0x0000ff, 0x3300ff, 0x6600ff, 0x9900ff, 0xcc00ff, 0xff00ff}, // blue-lilac
{0x00ff00, 0x66ff00, 0xccff00, 0xffff00, 0xffee00, 0xffdd00}, // green-yellow
{0x9900ff, 0xcc00ff, 0xff00ff, 0xff00cc, 0xff0099, 0xff0066}, // pink-purple
{0x0066ff, 0x0099ff, 0x00ccff, 0x00ffff, 0x00ffcc, 0x00ff99}, // turqoise
{0x9900ff, 0x0033ff, 0x00ff33, 0xffff00, 0xff9900, 0xff0000} // rainbow(ish)
};


void setup() {// setup() runs once
  pixels.begin();
  pixels.setBrightness(25 ); // 1/3 brightness to save battery
  prevTime = millis();

    switch (mySpeed) { // where the speed timings are set
      case 0: // speed 0
          delayTime = 50;
      break;

      case 1: // speed 1
          delayTime = 150;
      break;

      default: // speed 2 (or any integer other than 0 or 1)
          delayTime = 250;
      break;
  }

}

void loop() {// after setup() runs, loop() will run over and over as long as the GEMMA has power
  uint8_t  i, j;
  uint8_t red,green,blue,pixel;
  uint32_t t;

  switch(myPattern) {
   
     case 0: //LIGHT YOUR FIRST PIXEL, EXAMPLE
     
       //Choose pixel: 0-15
       pixel = 0;
     
       //Choose color values: 0-255
       red = 255;
       green = 200;
       blue = 100;
       
       //This is how we tell the gemma our choices
       pixels.setPixelColor(pixel, red, green, blue);
       
       //You are done! 
       
       pixels.show(); 
       delay(delayTime); 
       break;
     /******************************************************/
     
     case 1: //COLOR-WORM 
       if(offset >= 16)
         offset = 0;
       //make all pixels black
       for( i = 0; i<16; i++){
         pixels.setPixelColor(i,0x000000);
       }
       //set one color at the time
       for(i=0; i<6; i++) {
         uint32_t c = 0;
         j = offset+2*i;
         c = myColors[myColorChart][i];
         
         //set pixels and make sure j is in value 0-15
         pixels.setPixelColor(j%16, c);
         pixels.setPixelColor((j+1)%16, c);
         
       }
       pixels.show();
       offset++;
       delay(delayTime);
       break;
       
       case 2: //LIGHT-WORM
       //color, change it if you like. Value can be 0-15
       red = 15;
       green = 15;
       blue = 15;

       for( i = 0; i<16; i++){
         pixel = (offset+i)%16;
         c = i*16;
         pixels.setPixelColor(pixel, red*i, green*i, blue*i); 
       }
       pixels.show();
       offset++;
       delay(delayTime);
       break;
     

  }

}
