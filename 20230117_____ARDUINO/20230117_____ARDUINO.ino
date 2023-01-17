#define POWER_R_IN1 2

#define POWER_R_IN2 3

#define POWER_R_ENA 5

#define POWER_L_IN1 4

#define POWER_L_IN2 7

#define POWER_L_ENB 6

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



   
