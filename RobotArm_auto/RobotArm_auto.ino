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

coo act[4][3] = {{{30,170,180},{75,110,180},{30,110,0}},    //Coordinates
                {{120,127,5},{112,110,3},{105,98,2}},
                {{120,128,22},{110,110,22},{105,97,24}},
                {{126,126,37},{113,115,41},{106,104,44}}};
                   
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
  delay (500);
  myservo2.write(TB);
  delay (500);//
  myservo3.write(LR);
  delay (500);
}
void Magnet(int MG){
  if (MG==1){
    digitalWrite(Electromagnet, HIGH);
    delay(150);
  }else{
    digitalWrite(Electromagnet, LOW);
    delay(150);
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
      delay(500);
      Arm(act[0][0].FR, act[i][j].TB, act[i][j].LR);
      delay(500);
      Arm(act[i][j].FR, act[i][j].TB, act[i][j].LR);
      delay(500);
      Magnet(0);    
      Arm_init();
      delay(1000);
      }
    }
  }
}
  
void loop(){
  Site();
}
