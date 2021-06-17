#include <Servo.h>

#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo myservo1, myservo2, myservo3;
int Electromagnet = 2;

typedef struct {
  int FR;
  int TB;
  int LR;
}coo;

coo act[4][3] = {{{90,170,180},{107,130,180},{90,110,0}},    //좌표값
                {{148,144,5},{138,133,5},{131,120,4}},
                {{149,145,22},{138,131,23},{131,120,24}},
                {{150,147,37},{141,135,41},{133,123,43}}};
                   
void setup(){
  myservo1.attach(servoPin1);   //Pin Settings
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);
  pinMode(Electromagnet, OUTPUT);
  Arm_init();
  
  Serial.begin(9600);
}

void Arm(int FR, int TB, int LR){  //Arm Control
  myservo1.write(FR);
  delay (1000);
  myservo2.write(TB);
  delay (1000);//
  myservo3.write(LR);
  delay (1000);
}
void Magnet(int MG){
  if (MG==1){
    digitalWrite(Electromagnet, HIGH);
    delay(3000);
  }else{
    digitalWrite(Electromagnet, LOW);
    delay(3000);
  }
}

void Arm_init(){
  Arm(act[0][0].FR, act[0][0].TB, act[0][0].LR);
}
void Arm_grab(){
  Arm(act[0][1].FR, act[0][1].TB, act[0][1].LR);
}

void Site(){
  for (int i=1; i<4;i++){
    for(int j=0; j<3;j++){
      if (act[i][j].FR != 0){
      Arm_grab();
      Magnet(1);
      Arm(act[0][0].FR, act[i][j].TB, act[i][j].LR);
      delay(1000);
      Arm(act[i][j].FR, act[i][j].TB, act[i][j].LR);
      delay(1000);
      Magnet(0);
        
      Arm_init();
      
      }
    }
  }
}
  
void loop(){
  Site();
}
