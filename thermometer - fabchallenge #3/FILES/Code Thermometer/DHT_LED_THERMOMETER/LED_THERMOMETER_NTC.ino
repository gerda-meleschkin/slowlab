//NTC THERMISTOR
#include "thermistor.h"
#include "HardwareSerial.h"


unsigned long previousMillis = 0; //to replace the delay
unsigned long interval = 1000;
// Analog pin used to read the NTC
#define NTC_PIN               A0

// Thermistor object
THERMISTOR thermistor(NTC_PIN,        // Analog pin
                      10000,          // Nominal resistance at 25 ºC
                      3950,           // thermistor's beta coefficient
                      10000);         // Value of the series resistor

// Global temperature reading
uint16_t t;


//NEOPIXEL
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        A5 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels



//BUTTON
const int buttonPin = A2;     // the number of the pushbutton pin
int buttonState = 0;         // variable for reading the pushbutton status

bool start;

void setup() {
//NTC THERMISTOR
Serial.begin(9600);
pixels.clear(); // Set all pixel colors to 'off'


start=false;



//NEOPIXEL
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

//BUTTON
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);

  
}

void loop() {

unsigned long currentMillis = millis();

if (currentMillis - previousMillis >= interval) {

//TEMP SENSOR
  t = thermistor.read();   // Read temperature

 // Serial.print("Temp in 1/10 ºC : ");
  t = t/10;
  Serial.println(t);
  
  
  
  
  //Serial.print("Start?: ");
  //Serial.println(start);
  previousMillis = currentMillis;
}
   

//BUTTON
buttonState = digitalRead(buttonPin);
//Serial.print("Button pressed: ");
//Serial.println(buttonState);


  if(buttonState==0){
    if (start==false){
    start = true; 
    delay(1000);
     
    }
    else if (start==true){
     start = false;
    delay(1000);
    }
  }

    
//NEOPIXEL
  pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  //for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
   // pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    //pixels.show();   // Send the updated pixel colors to the hardware.

    //delay(DELAYVAL); // Pause before next pass through loop
 if(start==true){
  
    //TEMP UNDER 39°
    if (t<20) {
          pixels.setPixelColor(0, pixels.Color(1, 170, 29));
          pixels.show();
    }
    
    
    //TEMP BETWEEN 40° AND 59)
    else if (t >= 20 && t < 26)
    {
         pixels.setPixelColor(0, pixels.Color(1, 170, 29));
         pixels.setPixelColor(1, pixels.Color(0, 255, 42));
         pixels.show();
    }
    
    //TEMP BETWEEN 60° AND 79)
    else if (t >= 26 && t < 30)
    {
        pixels.setPixelColor(0, pixels.Color(1, 170, 29));
        pixels.setPixelColor(1, pixels.Color(0, 255, 42));
        pixels.setPixelColor(2, pixels.Color(126, 254, 0));
        pixels.show();
    }
    
    //TEMP BETWEEN 80° AND 99°
    else if (t >= 30 && t < 100)
    {
        pixels.setPixelColor(0, pixels.Color(1, 170, 29));
        pixels.setPixelColor(1, pixels.Color(0, 255, 42));
        pixels.setPixelColor(2, pixels.Color(126, 254, 0));
        pixels.setPixelColor(3, pixels.Color(230, 255, 0));
        pixels.show();
    }
    
    //TEMP BETWEEN 100° AND 119°
    else if (t >=100 && t < 120)
    {
        pixels.setPixelColor(0, pixels.Color(1, 170, 29));
        pixels.setPixelColor(1, pixels.Color(0, 255, 42));
        pixels.setPixelColor(2, pixels.Color(126, 254, 0));
        pixels.setPixelColor(3, pixels.Color(230, 255, 0));
        pixels.setPixelColor(4, pixels.Color(255,252, 0));
        pixels.show();
    }
    
    //TEMP BETWEEN 120° AND 139°
    else if (t >= 120 && t < 140)
    {
        pixels.setPixelColor(0, pixels.Color(1, 170, 29));
        pixels.setPixelColor(1, pixels.Color(0, 255, 42));
        pixels.setPixelColor(2, pixels.Color(126, 254, 0));
        pixels.setPixelColor(3, pixels.Color(230, 255, 0));
        pixels.setPixelColor(4, pixels.Color(255,252, 0));
        pixels.setPixelColor(5, pixels.Color(255,206, 2));
        pixels.show();
    }
    
    //TEMP BETWEEN 140° AND 159°
    else if (t >= 140 && t < 160)
    {
        pixels.setPixelColor(0, pixels.Color(1, 170, 29));
        pixels.setPixelColor(1, pixels.Color(0, 255, 42));
        pixels.setPixelColor(2, pixels.Color(126, 254, 0));
        pixels.setPixelColor(3, pixels.Color(230, 255, 0));
        pixels.setPixelColor(4, pixels.Color(255,252, 0));
        pixels.setPixelColor(5, pixels.Color(255,206, 2));
        pixels.setPixelColor(6, pixels.Color(252, 134, 1));
        pixels.show();
    }
    
    //TEMP BETWEEN 160° AND 179°
    else if (t >= 160 && t < 180)
    {
        pixels.setPixelColor(0, pixels.Color(1, 170, 29));
        pixels.setPixelColor(1, pixels.Color(0, 255, 42));
        pixels.setPixelColor(2, pixels.Color(126, 254, 0));
        pixels.setPixelColor(3, pixels.Color(230, 255, 0));
        pixels.setPixelColor(4, pixels.Color(255,252, 0));
        pixels.setPixelColor(5, pixels.Color(255,206, 2));
        pixels.setPixelColor(6, pixels.Color(252, 134, 1));
        pixels.setPixelColor(7, pixels.Color(254, 62, 0));
        pixels.show();
    }
    
    //TEMP BETWEEN 180° AND 199°
    else if (t >= 180 && t < 200)
    {
        pixels.setPixelColor(0, pixels.Color(1, 170, 29));
        pixels.setPixelColor(1, pixels.Color(0, 255, 42));
        pixels.setPixelColor(2, pixels.Color(126, 254, 0));
        pixels.setPixelColor(3, pixels.Color(230, 255, 0));
        pixels.setPixelColor(4, pixels.Color(255,252, 0));
        pixels.setPixelColor(5, pixels.Color(255,206, 2));
        pixels.setPixelColor(6, pixels.Color(252, 134, 1));
        pixels.setPixelColor(7, pixels.Color(254, 62, 0));
        pixels.setPixelColor(8, pixels.Color(252, 0, 4));
        pixels.show();
    }
    
    //TEMP OVER 200°
    else
    {
        pixels.setPixelColor(0, pixels.Color(1, 170, 29));
        pixels.setPixelColor(1, pixels.Color(0, 255, 42));
        pixels.setPixelColor(2, pixels.Color(126, 254, 0));
        pixels.setPixelColor(3, pixels.Color(230, 255, 0));
        pixels.setPixelColor(4, pixels.Color(255,252, 0));
        pixels.setPixelColor(5, pixels.Color(255,206, 2));
        pixels.setPixelColor(6, pixels.Color(252, 134, 1));
        pixels.setPixelColor(7, pixels.Color(254, 62, 0));
        pixels.setPixelColor(8, pixels.Color(252, 0, 4));
        pixels.setPixelColor(9, pixels.Color(135, 8, 1));
        pixels.show();
    }

 }
 else{
  pixels.clear(); // Set all pixel colors to 'off'
  pixels.show();

 }

 





 }
