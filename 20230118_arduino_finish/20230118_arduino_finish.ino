#include <NewPing.h>
#define POWER_R_IN1 2
#define POWER_R_IN2 3
#define POWER_R_ENA 5

#define POWER_L_IN1 4
#define POWER_L_IN2 7
#define POWER_L_ENB 6

#define SONAR_F_PIN 8
#define SONAR_R_PIN 10
#define SONAR_L_PIN 11

double F_distance = 0;
double L_distance = 0;
double R_distance = 0;

int line_sensor[5] = {0,0,0,0,0};
int sensor =1;
int sum = 1;

NewPing sonar[3] = 
{
  NewPing(SONAR_F_PIN,SONAR_F_PIN,500),
  NewPing(SONAR_R_PIN,SONAR_R_PIN,500),
  NewPing(SONAR_L_PIN,SONAR_L_PIN,500),
 
};

int read_line_sensor()
{
  int i;
  sum = 0;
  for(i = 0; i < 5; i++)
  {
    line_sensor[i] = analogRead(A0 + i);
   if(i==0) if(  line_sensor[i] > 550) sum = sum - 3;       // 900을 넣었지만 색이 옅은 노란색부분에서는 작동 되지 않아서 여유로운 550으로 바꿔줌
   if(i==1) if(  line_sensor[i] > 550) sum = sum - 1;
   if(i==2) if(  line_sensor[i] > 550) sum = sum ;
   if(i==3) if(  line_sensor[i] > 550) sum = sum + 1; 
   if(i==4) if(  line_sensor[i] > 550) sum = sum + 3;
    
   
    
  }
  Serial.println(" ");
  return sum;           //sum으로 반환
}


void motor_power(int speed_l,int dir_l, int speed_r, int dir_r)   // motor_control을 나만의 이름으로 motor_power로 바꿔줌
{
  if(dir_l ==1) // 전진

   {

     digitalWrite(POWER_L_IN1, HIGH);

     digitalWrite(POWER_L_IN2, LOW);

     analogWrite(POWER_L_ENB, speed_l);  

   }
   
   else if( dir_l == -1)//후진

   {  

     digitalWrite(POWER_L_IN1, LOW);

     digitalWrite(POWER_L_IN2, HIGH);

     analogWrite(POWER_L_ENB, speed_l); 

   }

   else

   {

     digitalWrite(POWER_L_IN1, LOW);

     digitalWrite(POWER_L_IN2, LOW);

     analogWrite(POWER_L_ENB, 0);

   }  

   if(dir_r ==1) // 전진

   {

     digitalWrite(POWER_R_IN1, HIGH);

     digitalWrite(POWER_R_IN2, LOW);

     analogWrite(POWER_R_ENA, speed_r);  

   }
   
   else if( dir_r == -1)//후진

   {  

     digitalWrite(POWER_R_IN1, LOW);

     digitalWrite(POWER_R_IN2, HIGH);

     analogWrite(POWER_R_ENA, speed_r); 

   }

   else

   {

     digitalWrite(POWER_R_IN1, LOW);

     digitalWrite(POWER_R_IN2, LOW);

     analogWrite(POWER_R_ENA, 0);

   }  


}
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600); //9600 속도로 통신을 시작 한다.

  pinMode(POWER_R_IN1, OUTPUT);

  pinMode(POWER_R_IN2,OUTPUT);

  pinMode(POWER_R_ENA, OUTPUT);

 

  pinMode(POWER_L_IN1, OUTPUT);

  pinMode(POWER_L_IN2, OUTPUT);

  pinMode(POWER_L_ENB, OUTPUT);  

}

void loop() {
  // put your main code here, to run repeatedly:
 
  line_sensor[5];
  read_line_sensor(); // (int speed_l,int dir_l, int speed_r, int dir_r) ==> 순서

  sensor = read_line_sensor();
  if(sensor < 0){
    motor_power(-sum * 100,-1,0,0); //1을 넣었지만 후진을 해서 -로 바꿔줌
  }

  else if(sensor > 0){
    motor_power(0,0,sum * 100,-1);
  }

  else{
     motor_power(100,-1,100,-1);
  }

 
}
