#include <Servo.h>

Servo servo;

void setup()
{
  servo.attach(2);
  Serial.begin(9600);
  servo.write(90);
  delay(1000);
}

void loop()
{
  int ad_in = 0;
  ad_in = analogRead(A0);
  
  Serial.println(ad_in);
  
 
}