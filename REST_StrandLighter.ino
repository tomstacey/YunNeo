#include <Adafruit_NeoPixel.h>

#define PIN8 8
#define PIN9 9

Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(8, PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(8, PIN9, NEO_GRB + NEO_KHZ800);

//Do REST schizz below
//To follow

void setup() {
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'
  strip2.begin();
  strip2.show(); 
  strip1.setBrightness(60);
  strip2.setBrightness(50);
 
}

void loop() {
 halfAndShow();
 halfAndShow2();
  //strip1.setPixelColor(1, 255, 0, 255);
  //strip1.setPixelColor(2, 255, 0, 255);
 strip1.show();
 strip2.show();
  
}

//this function looks for incoming a serial byte value and divides by 2 and sets it to numOfPixels
void halfAndShow() {
    int incomingByte = 45;
   int numOfPixels = incomingByte / 12.5;
    //if (incomingByte > 0) {
      for (int i = 0; i < numOfPixels; i++){
        for (int j = 0; j <= numOfPixels; j++) {
         strip1.setPixelColor(i, 255, 0, 255);
      }
    }     
  }
  
  void halfAndShow2() {
    int incomingByte = 80;
   int numOfPixels = incomingByte / 12.5;
    //if (incomingByte > 0) {
      for (int i = 0; i < numOfPixels; i++){
        for (int j = 0; j <= numOfPixels; j++) {
         strip2.setPixelColor(i, 255, 0, 255);
      }
    }     
  }
  

