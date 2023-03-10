void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, INPUT);
  Serial.begin(9600);
}

void loop()
{
 
  int cds_sensor_value = 0;
  int PIR_sensor_value = 0;
  int temp_sensor_value = 0;
  int gas_sensor_value = 0;
  float temp;
  cds_sensor_value = analogRead(A0);
  temp_sensor_value = analogRead(A1);
  gas_sensor_value = analogRead(A2);
 
  PIR_sensor_value = digitalRead(4);
 
  delay(100);
  temp = temp_sensor_value*5.0/1024.0;
  temp = (temp -0.5) * 100.0;
 
  Serial.println(gas_sensor_value);
 
  if(gas_sensor_value >=180)
  {
    tone(5,600,1000);
    delay(1000);
  }
  else
  {
    noTone(5);
  }
 
  if(PIR_sensor_value == 1)
  {
    digitalWrite(2, HIGH);
  }
  else
  {
    digitalWrite(2, LOW);
  }
  if(temp <=10)
  {
    digitalWrite(3, HIGH);
  }
  else
  {
    digitalWrite(3, LOW);
  }
}