#include <Servo.h>
Servo motor;
byte b;
long i = 0;
int a=0;
void setup ()
{ 
  
  motor.attach(3);
  Serial.begin(9600);
  Serial.setTimeout(10);
}
void loop()
{
 if (Serial.available()>0 ) {
    i = Serial.parseInt();
   a = Serial.read();
    Serial.print("i = ");
    Serial.println(i);
   motor.write(i*1.8);
   }

}
