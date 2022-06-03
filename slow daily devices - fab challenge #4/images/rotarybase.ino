#include <Servo.h>

static const int servoPin = A0;

Servo servo1;

int angle = 0;

//This variable tells us the difference between photoresistors.

int difference;

//This is the amount of difference it has to have so it changes position.

int dif = 10;

//defining each photoresistor pin.

int pinphot1 = A2;
int pinphot2 = A1;

//writing temperature of each photoresistor.

int phot1;
int phot2;

//defining each photoresistor angle 0-180.

int phot1pos = 135;
int phot2pos = 45;

void setup() {
  Serial.begin(115200);
  servo1.attach(servoPin);
  
 //defining in which angle the motor will start. 
 
  servo1.write(90);
  delay(1000);
  
}


void diff (int num1, int num2) {
  if (num1 > num2) {
    difference = num1 - num2;
  } else {
    difference = num2 - num1;
  }
}

void loop() {

  phot1 = analogRead(pinphot1);
  phot2 = analogRead(pinphot2);
  
  int perphot1 = map(phot1, 0, 4096, 0, 100);
  int perphot2 = map(phot2, 0, 4096, 0, 100);
  
  Serial.print(perphot1);
  Serial.print(",");
  Serial.println(perphot2);

  diff(perphot1, perphot2);
  
  if ((perphot1 > perphot2)  && (difference > dif)){
    
    servo1.write(phot1pos);
    delay(1000);
  }
  else if ((perphot1 < perphot2) && (difference > dif)){
     servo1.write(phot2pos);
     delay(1000);
  }



 //servo1.write(90);
  //delay(1000);
//  servo1.write(180);
//  delay(1000);
//  servo1.write(90);
//  delay(1000);
 //servo1.write(0);
 //delay(1000);

//if(phot1 <= phot2) {
//
//  for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
//          servo1.write(posDegrees);
//          //Serial.println(posDegrees);
//          delay(20);
//      }
//}
//else if (phot1 > phot2){
//
//   for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
//        servo1.write(posDegrees);
//        //Serial.println(posDegrees);
//        delay(20);
//    }
//}


  
  
}
