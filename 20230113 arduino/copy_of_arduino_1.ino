#define IN1 2
#define IN2 4
#define ENL 3

#define IN3 7
#define IN4 6
#define ENR 5

#define F_Sonar 8
#define L_Sonar 9
#define R_Sonar  10

void setup()
{
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENL, OUTPUT);
 
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENR, OUTPUT);
  
  pinMode(F_Sonar, OUTPUT);
  pinMode(L_Sonar, OUTPUT);
  pinMode(R_Sonar, OUTPUT);
  
  Serial.begin(9600);
  }


void motor_control(int dir_1, int speed_1, int dir_r, int speed_r)
{
 
  if(dir_r == 1)
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENL,speed_1);
   }
  else if(dir_1 == 0)
  {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENR, speed_1);
  }
  else
  {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENR, speed_1);
  }
    if(dir_r == 1)
  {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENR,speed_1);
   }
  else if(dir_1 == -1)
  {
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENR, speed_1);
  }
  else
  {
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENR, 0);
  }
}

float F_sonar_sensor();
{
  float duration = 0.0;
  float distance = 0.0;
  
  digitalWrite(F_Sonar, LOW);
  digitalWrite(F_Sonar, HIGH);
  delay(10);
  digitalWrite(F_Sonar, LOW);
  pinMode(F_Sonar, INPUT);
  duration = pulseIn(F_Sonar, HIGH);
  
  distance = (duration * 340.0)/2.0/10000.0;
  
  return distance;
}

float L_Sonar_sensor ()
{
  float duration = 0.0;
  float distance = 0.0;
  pinMode(L_Sonar, OUTPUT);
  digitalWrite(L_Sonar, LOW);
  digitalWrite(L_Sonar, HIGH);
  delay(10);
  digitalWrite(L_Sonar, LOW);
  
  pinMode(L_Sonar, INPUT);
  duration = pulseIn(L_Sonar, HIGH);
  
  distance = (duration * 340.0)/2.0/10000.0;
  
  return distance; 
}
void loop ()
{
  float f_sonar_distance = 0.0;
  float l_sonar_distance = 0.0;
  f_sonar_distance = F_sonar_distance();
  l_sonar_distance =L_sonar_distance();
  r_sonar_distance =R_sonar_distance();
  Serial.print(l_sonar_distance);
  Serial.print("  ");
  Serial.println(f_sonar_distance);
  Serial.print("  ");
  Serial.println(r_sonar_distance);
  
  if( l_sonar_distance > obstacle)
    &&( f_sonar_distance<=obstacle)
    &&( r_sonar_distance>obstacle)  //왼쪽 회전
  {
    motor_control(-1,50,1,50);
    delay(1000);
    motor_control(-1,100,1,100);
    
  }
  
  else if( l_sonar_distance<=obstacle)
    &&( f_sonar_distance<=obstacle)
    &&( r_sonar_distance>obstacle)   //오른쪽 회전
  {
    motor_control(-1,50,1,50);
    delay(1000);
    motor_control(-1,100,1,100);
    
  }
  
  else if( l_sonar_distance > obstacle)
    &&( f_sonar_distance<=obstacle)
    &&( r_sonar_distance<=obstacle) // 왼쪽 회전
  {
    motor_control(-1,50,1,50);
    delay(1000);
    motor_control(-1,100,1,100);
    
  }
  
   else if( l_sonar_distance > obstacle)
    &&( f_sonar_distance<=obstacle)
    &&( r_sonar_distance<=obstacle) // 왼쪽 회전
  {
    motor_control(-1,50,-1,50);
    delay(1000);
    motor_control(-1,50,1,50);
    delay(1000);
    motor_control(1,100,1,100);
    delay(1000);
  }
  else
  {
    motor_control(1,100,1,100);
  }
  
}


