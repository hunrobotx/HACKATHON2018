#include <Servo.h>
int servoPin = 6;
int led = 3;
Servo Servo1;

void setup(){
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);
  Servo1.attach(servoPin);
}

void loop(){
  if(Serial.available() > 0){
    int serialData = Serial.read();
    Serial.print(serialData);

    Servo1.write(serialData);
    
  }
}

