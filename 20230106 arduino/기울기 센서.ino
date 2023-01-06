// C++ code
//
void setup()
{
  pinMode(3, INPUT);
  pinMode(3, OUTPUT);
}

void loop()
{
  int input = 0;
  
  input = digitalRead(2);
  Serial.println(input);
  if(input == HIGH)
  {
    tone(3,500,1000);
    delay(1000);
  }
  else
  {
    noTone(3);
  }
}