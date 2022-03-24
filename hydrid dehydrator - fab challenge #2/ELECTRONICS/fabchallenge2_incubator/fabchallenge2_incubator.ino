/*!
 * @file readDHT11.ino
 * @brief DHT11 is used to read the temperature and humidity of the current environment. 
 *
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [Wuxiao](xiao.wu@dfrobot.com)
 * @version  V1.0
 * @date  2018-09-14
 * @url https://github.com/DFRobot/DFRobot_DHT11
 */

#include <DFRobot_DHT11.h>
DFRobot_DHT11 DHT;
#define DHT11_PIN A10


//INCUBATOR
  
//INCUB VALUES
//temperature
 int maxTemp = 25;

//humidity
 int criticalHum = 50;

void setup(){
  pinMode(13, OUTPUT);
  Serial.begin(115200);

}

void loop(){
  DHT.read(DHT11_PIN);
  Serial.print("temperature:");
  Serial.print(DHT.temperature);
  Serial.print("  humidity:");
  Serial.println(DHT.humidity);
  delay(1000);

if(DHT.temperature > maxTemp && DHT.humidity > criticalHum )
  {
    digitalWrite(13,LOW);
  }
  
else if (DHT.temperature > maxTemp && DHT.humidity < criticalHum )
  {
    digitalWrite(13,HIGH);
  }

else if (DHT.temperature < maxTemp)
  {
    digitalWrite(13,HIGH);
  }
 }
