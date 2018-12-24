/*
 Kodun python dan gelen byte ın uzunluğuna kadar 0 ve 180 derece
 arasında döndüğünü ve byte ın uzunluğu tamamlandığında ise doğru değeri gösterdikten sonra
 loop a tekrar döndüğünü gördük.
 */

#include <Servo.h>

int pos[20];
int revpos=0;
int pose=0;
int index=0;

Servo omegaLul;

void setup() {


Serial.begin(9600);

omegaLul.attach(12);

}

void loop() {
  index=0;
  while(Serial.available())
  {
    pos[index] = Serial.read();
    index++;
  }
  index=0;
  while(index<sizeof(pos))
  {
    pose = pose + (pos[index]*10*(index+1));
    index++;
  }
revpos=180-pose;
omegaLul.write(revpos);
delay(500);
}
