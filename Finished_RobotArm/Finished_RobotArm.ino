#include <Wire.h>
#include <Servo.h>

#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo myservo1, myservo2, myservo3; //객체 생성

int Electromagnet = 2;
int color = 0;

typedef struct{
  int FR;
  int TB;
  int LR;
}coo;


coo act[4][3] = {{{30,170,180},{75,110,180},{30,110,0}},  //초기,집기,이동준비
                {{120,123,5},{112,110,3},{105,98,2}},  //r1,r2,r3
                {{112,110,3},{110,110,22},{113,113,40}}, //g1,g2,g3
                {{105,98,2},{105,97,24},{105,100,44}}};  //b1,b2,b3        

void setup() {
  // put your setup code here, to run once:
  Wire.begin(0x9);        //slve with address 9
  Wire.onReceive(receiveEvent); //입력받을 경우
  myservo1.attach(servoPin1);   //핀 설정
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);
  
  Arm_init();
  
  pinMode(Electromagnet, OUTPUT);
  Serial.begin(9600);
}

void receiveEvent(int color) {
  while (Wire.available()) {
    color = Wire.read(); //받은값 읽기
    Serial.println(color);// 받은 것 확인
  }
}

void Arm(int FR, int TB, int LR) { //로봇팔
  myservo1.write(FR);
  delay (1000); 
  myservo2.write(TB);
  delay (1000);
  myservo3.write(LR);
  delay (1000); 
}



void Magnet(int MG) { //전자석 제어
  if (MG == 1) {
    digitalWrite(Electromagnet, HIGH); //전자석 ON
    delay(150);
  } else {
    digitalWrite(Electromagnet, LOW); //전자석 OFF
    delay(150);
  }
}

void Arm_init(){
  Arm(act[0][0].FR, act[0][0].TB, act[0][0].LR);
}
void Arm_grab(){
  Arm(act[0][1].FR, act[0][1].TB, act[0][1].LR);
}

void Site(int color) {
  
  for (int i = 0; i < 3; i++)
  {
    if (act[color][i].FR != 1)
    {
      Arm(act[0][0].FR, act[color][i].TB, act[color][i].LR);
      Arm(act[color][i].FR, act[color][i].TB, act[color][i].LR);
      Magnet(0);
      Arm_init();
      act[color][i].FR = 1;
      break;
    }
  }
}

void loop() {

  if (color == 1) {
    Arm_init();
    Arm_grab();
    Magnet(1);
    Site(color-1);
    color = 0;
  }
  else if (color == 2) {
    Arm_init();
    Arm_grab();
    Magnet(1);
    Site(color-1);
    color = 0;
  }
  else if (color == 3) {
    Arm_init();
    Arm_grab();
    Magnet(1);
    Site(color-1);
    color = 0;
  }
}
