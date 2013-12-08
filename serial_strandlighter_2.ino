#include <Adafruit_NeoPixel.h>

//Pins to be used for strips
#define PIN8 8
#define PIN9 9

//Create strip1 and strip2
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(8, PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(8, PIN9, NEO_GRB + NEO_KHZ800);
 
int inputPercent = 0;
 int changed = 0;

void setup() {
   // initialize serial:
  Serial.begin(9600);
   // Setup Strips
  strip1.begin();

  strip1.setBrightness(40); //Brightness out of 100
  strip2.setBrightness(50);
}

void loop() {
 strip1.show();
 getPercentFromSerial();
 halfAndShow();

 
 //Serial.print(inputPercent);
}

 int getPercentFromSerial() {
  
    //serial stuff
  if ( Serial.available()) // Check to see if at least one character is available
  {
    char ch = Serial.read();
    if( isDigit(ch) ) // is this an ascii digit between 0 and 9?
    {
       inputPercent = (ch - '0');      // ASCII value converted to numeric value 
     }
    }
    return inputPercent;
  }


void halfAndShow() {
 
 
      if (inputPercent > 0 && inputPercent >= changed){
      
      for (int i = 0; i < inputPercent; i++){
       //for (int j = 0; j <= inputPercent; j++) {
         strip1.setPixelColor(i, 255, 0, 255);
         strip1.show();       
     // }
      }
       changed = inputPercent;
      
      }
      
    else if (inputPercent < changed){
      
      int m = strip1.numPixels() - inputPercent;
        for (int n = 0; n < m; n++){
         strip1.setPixelColor(n, 0, 0, 0);
         strip1.show();
        }
      
    for (int k = 0; k < inputPercent; k++){
    // for (int l = 0; l <= inputPercent; l++) {
         
        strip1.setPixelColor(k, 0, 255, 0);
        strip1.show();
        //Serial.print(k);
        

   // }
    }
    }
    
    

    }



       
       

    



