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

int speed_l=100;
int speed_r=100;
int dir_r=1;
int dir_l=1;

NewPing sonar[3] = 
{
  NewPing(SONAR_F_PIN,SONAR_F_PIN,500),
  NewPing(SONAR_R_PIN,SONAR_R_PIN,500),
  NewPing(SONAR_L_PIN,SONAR_L_PIN,500),
 
};


  

void motor_power(int speed_l,int dir_l, int speed_r, int dir_r)
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

} // 설정 함수

void loop(){
  
  F_distance = sonar[0].ping_cm() * 10;
  L_distance = sonar[0].ping_cm() * 10;
  R_distance = sonar[0].ping_cm() * 10;
  motor_power(dir_l, speed_l, dir_r, speed_r);
  Serial.print(F_distance);
  Serial.print(" ");
  Serial.print(R_distance);
  Serial.print(" ");
  Serial.print(L_distance);
  if(F_distance <= 40)
  {
    motor_power(-1, 100, -1, 100);
  }
  else if(R_distance<=40)
  {
    motor_power(-1, 100, 1, 100);
  }
  else if(L_distance<=40)
  {
     motor_power(1, 100, -1, 100);
  }
   
}



   
