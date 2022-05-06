// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN A0     // Digital pin connected to the DHT sensor
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 3 (on the right) of the sensor to GROUND (if your sensor has 3 pins)
// Connect pin 4 (on the right) of the sensor to GROUND and leave the pin 3 EMPTY (if your sensor has 4 pins)
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);



#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
 #include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        A1 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 12 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels





void setup() {
//TEMP SENSOR
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  dht.begin();


//NEOPIXEL
  #if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
  #endif
  // END of Trinket-specific code.

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  
}

void loop() {

  
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));


pixels.clear(); // Set all pixel colors to 'off'

  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  //for(int i=0; i<NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
   // pixels.setPixelColor(i, pixels.Color(0, 150, 0));

    //pixels.show();   // Send the updated pixel colors to the hardware.

    //delay(DELAYVAL); // Pause before next pass through loop
 

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
else if (t >= 26 && t < 79)
{
    pixels.setPixelColor(0, pixels.Color(1, 170, 29));
    pixels.setPixelColor(1, pixels.Color(0, 255, 42));
    pixels.setPixelColor(2, pixels.Color(126, 254, 0));
    pixels.show();
}

//TEMP BETWEEN 80° AND 99°
else if (t >= 80 && t < 99)
{
    pixels.setPixelColor(0, pixels.Color(1, 170, 29));
    pixels.setPixelColor(1, pixels.Color(0, 255, 42));
    pixels.setPixelColor(2, pixels.Color(126, 254, 0));
    pixels.setPixelColor(3, pixels.Color(230, 255, 0));
    pixels.show();
}

//TEMP BETWEEN 100° AND 119°
else if (t >= 100 && t < 119)
{
    pixels.setPixelColor(0, pixels.Color(1, 170, 29));
    pixels.setPixelColor(1, pixels.Color(0, 255, 42));
    pixels.setPixelColor(2, pixels.Color(126, 254, 0));
    pixels.setPixelColor(3, pixels.Color(230, 255, 0));
    pixels.setPixelColor(4, pixels.Color(255,252, 0));
    pixels.show();
}

//TEMP BETWEEN 120° AND 139°
else if (t >= 120 && t < 139)
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
else if (t >= 140 && t < 159)
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
else if (t >= 160 && t < 179)
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
else if (t >= 180 && t < 199)
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
