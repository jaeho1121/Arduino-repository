#include <IRremote.h>

IRrecv ir_recv(10);
decode_results results;

void setup()
{
  pinMode(2, OUTPUT);
  ir_recv.enableIRIn();
  Serial.begin(9600);
}
void loop()
{
  int cds_sensor_value = 0;
 
  cds_sensor_value = analogRead(A0);
 
  if(ir_recv.decode(&results))
  {
    Serial.println(results.value);
    delay(30);
    ir_recv.resume();
 
  if(results.value == 16593103)
  {
    digitalWrite(2, HIGH);
  }
  if(results.value == 16582903)
  {
    digitalWrite(2, LOW);
  }
}

if(cds_sensor_value<200)
{
  digitalWrite(2, HIGH);
}
   else
   {
     digitalWrite(2, LOW);
   }
}