#include <Adafruit_NeoPixel.h>
#include <Console.h>


//THIS VERSION IS: for Yun

//Pins to be used for strips
#define PIN8 8
#define PIN9 9

//Create strip1 and strip2
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(8, PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(8, PIN9, NEO_GRB + NEO_KHZ800);

// set some variables to deal with incoming percentage from GUI and a Grade value to be overlaid by flashing the LEDS
 
int inputPercent = 0;
int changed = 0;
int grade = 0;
int global_delay_count;


void setup() 
{
   // initialize serial
  Bridge.begin();
  Console.begin();
   // Setup Strips
  strip1.begin();

  strip1.setBrightness(10); //Brightness out of 100
  strip2.setBrightness(50);
  
    while (!Console){
    ; // wait for Console port to connect.
  }
  Console.println("You're connected to the Console!!!!");
  
}
  

void loop() 
{
  strip1.show();
  getPercentFromSerial();
  showAmountStrip1();
 // flashGrade();

}

int getPercentFromSerial() 
{
  //serial stuff gets input from Console
  if ( Console.available()) // Check to see if at least one character is available
  {
    char ch = Console.read();
    if( isDigit(ch) ) // is this an ascii digit between 0 and 9?
    {
       inputPercent = (ch - '0');      // ASCII value converted to numeric value 
    }
   }
    return inputPercent;
 }


void showAmountStrip1()
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
  int i;
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
  
    //showAmount(); //this function no longer exists as we have showAmountStrip1 and 2
    global_delay_count=0;  
}

     strip1.show();     

}





   
       

    



