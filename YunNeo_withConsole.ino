#include <Adafruit_NeoPixel.h>
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

//THIS VERSION IS: for Yun

//Pins to be used for strips
#define PIN8 8
#define PIN9 9

//Create strip1 and strip2
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(8, PIN8, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip2 = Adafruit_NeoPixel(8, PIN9, NEO_GRB + NEO_KHZ800);

// set some variables to deal with incoming percentage from GUI and a Grade value to be overlaid by flashing the LEDS

int webInputValue1 = 0;
int webInputValue2 = 0;
int changed = 0;
int grade = 0;
int global_delay_count;
YunServer server;


void setup() 
{
   // initialize bridge
  Bridge.begin();
   // Setup Strips
  strip1.begin();

  strip1.setBrightness(1); //Brightness out of 100
  strip2.setBrightness(50);
  
  server.listenOnLocalhost();
  server.begin();
}


void loop() 
{
  // Get clients coming from server
  YunClient client = server.accept();

  // There is a new client?
  if (client) {
    // Process request
    process(client);

    // Close connection and free resources.
    client.stop();
  }

  delay(50); // Poll every 50ms
}

void process(YunClient client) {
  // read the command
  String command = client.readStringUntil('/');

  // Check for set
  if (command == "set") {
    set(client);
  }
}

void set(YunClient client) {
 int stripid;
  // Read pin number
  stripid = client.parseInt();

  // If the next character is a '/' it means we have an URL
  // with a value like: "/digital/13/1"
  if (client.read() == '/') {
    webInputValue1 = client.parseInt();
    showAmountStrip1();
  }
  // Send feedback to client
  client.print(F("Strip "));
  client.print(stripid);
  client.print(F(" set to "));
  client.println(webInputValue1);
}

void showAmountStrip1()
{
int i;  
  if(webInputValue1 == 0)
  {
      for (i = 0; i <=7; i++)
      {
        strip1.setPixelColor(i, 255, 255, 255);
      }    
  }
  else if(webInputValue1 == 8)
  {

      for (i = 0; i <=7; i++)
      {
        strip1.setPixelColor(i, 255, 0, 255);
      }    
  }
  else if (webInputValue1 >= 0 && webInputValue1 <= 8)
 {

      for (i = 0; i <= webInputValue1 -1; i++)
      {
        strip1.setPixelColor(i, 255, 0, 255);
        delay(50);
        strip1.show();
      }  
      for (i = webInputValue1; i <= 7; i++)
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