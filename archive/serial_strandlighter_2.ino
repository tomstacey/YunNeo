#include <Adafruit_NeoPixel.h>

//Pins to be used for strips
#define PIN8 8
#define PIN9 9

//Create strip1 and strip2
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(8, PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(8, PIN9, NEO_GRB + NEO_KHZ800);

// written my Mr Shaw !!!!!
 
int inputPercent = 0;
int changed = 0;
int grade = 2;
uint16_t global_delay_count;


void setup() 
{
   // initialize serial:
  Serial.begin(19200);
   // Setup Strips
  strip1.begin();

  strip1.setBrightness(50); //Brightness out of 100
  strip2.setBrightness(50);
}

void loop() 
{
  strip1.show();
  getPercentFromSerial();
  flashGrade();

}

int getPercentFromSerial() 
{
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


void showAmount()
{
int i;  
  if(inputPercent == 0)
  {
      for (i = 0; i <=7; i++)
      {
        strip1.setPixelColor(i, 255, 255, 255);
      }    
  }
  else if(inputPercent == 8)
  {

      for (i = 0; i <=7; i++)
      {
        strip1.setPixelColor(i, 255, 0, 255);
      }    
  }
  else if (inputPercent >= 0 && inputPercent <= 8)
 {
  
      for (i = 0; i <=inputPercent-1; i++)
      {
        strip1.setPixelColor(i, 255, 0, 255);
      }  
      for (i = inputPercent; i <= 7; i++)
      {
        strip1.setPixelColor(i, 255, 255, 255);
      }  

 } 
 
     strip1.show();         
}

void flashGrade()
{
  uint16_t i;
  delay(1);
  global_delay_count++;
  if(global_delay_count==1000)
  {      
       for (i = 0; i <=5; i++)
      {
        strip1.setPixelColor(i, 0, 0, 0);
      }    
     
  }
 if(global_delay_count==1500)
{
  
    showAmount(); 
    global_delay_count=0;  
}

     strip1.show();     

}




/*
gradeflash()
{
 
 if(gradeinput == 2) 
 {
    strip1.show();
   delay(100);
    strip1.showall off 

   
 }
  
  
  
}


*/


   
       

    



