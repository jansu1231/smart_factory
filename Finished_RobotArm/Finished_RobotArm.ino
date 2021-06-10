#include <Wire.h>
#include <Servo.h>

#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo myservo1, myservo2, myservo3;

int Electromagnet = 2;
int color = 0;

typedef struct{
  int FR;
  int TB;
  int LR;
}coo;

int RGB[3]={0,0,0};
coo act[4][3] = {{{30,170,180},{72,128,180},{30,110,0}},    //좌표 값
                {{116,140,4},{107,128,3},{99,116,2}},
                {{117,141,22},{108,129,23},{100,118,24}},
                {{119,143,37},{108,131,41},{100,119,45}}};   

void setup() {
  Wire.begin(0x9);                //slve 주소 9
  Wire.onReceive(receiveEvent);   //i2c
  myservo1.attach(servoPin1);     //Pin Settings
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);
  
  Arm_init();
  
  pinMode(Electromagnet, OUTPUT);
  Serial.begin(9600);
}

void receiveEvent(int co) {    //i2c
  while (Wire.available()) {
    color = Wire.read();      //받은 값 읽기
    Serial.println(color);    //받은 값 확인
  }
}

void Arm(int FR, int TB, int LR) { //팔 컨트롤
  myservo1.write(FR);
  delay (1000); 
  myservo2.write(TB);
  delay (1000);
  myservo3.write(LR);
  delay (1000); 
}
void Magnet(int MG) {  //전자석 컨트롤
  if (MG == 1) {
    digitalWrite(Electromagnet, HIGH);
    delay(150);
  } else {
    digitalWrite(Electromagnet, LOW);
    delay(150);
  }
}

void Arm_init(){      //팔 초기 좌표
  Arm(act[0][0].FR, act[0][0].TB, act[0][0].LR);
}
void Arm_grab(){                  //팔 물건 집음
  Arm(act[0][1].FR, act[0][1].TB, act[0][1].LR);
  Magnet(1);
}

void Site(int sort){  //색상 좌표 분류
  
  if(sort==1){        //빨강 위치
    Serial.println("r");
    Arm(act[0][0].FR, act[sort][RGB[0]].TB, act[sort][RGB[0]].LR);
    delay(500);
    Arm(act[sort][RGB[0]].FR, act[sort][RGB[0]].TB, act[sort][RGB[0]].LR);
    delay(500); 
    RGB[0]++;
    
    if(RGB[0]==2)
    {
      RGB[0]=0;
    }
  }
  else if(sort==2){   //초록 위치
    Serial.println("g");
    Arm(act[0][0].FR, act[sort][RGB[1]].TB, act[sort][RGB[1]].LR);
    delay(500);
    Arm(act[sort][RGB[1]].FR, act[sort][RGB[1]].TB, act[sort][RGB[1]].LR);
    delay(500);
    RGB[1]++;
    if(RGB[1]==2)
    {
      RGB[1]=0;
    }
  }
  
  else if(sort==3){   //파랑 위치
    Serial.println("b");
    Arm(act[0][0].FR, act[sort][RGB[2]].TB, act[sort][RGB[2]].LR);
    delay(500);
    Arm(act[sort][RGB[2]].FR, act[sort][RGB[2]].TB, act[sort][RGB[2]].LR);
    delay(500);
    RGB[2]++;
    if(RGB[2]==2)
    {
      RGB[2]=0;
    }
  }
  Magnet(0);
}

void loop() {
  
  if(color !=0){
    Arm_grab();
    Site(color);
    Arm_init();
    color=0;
  }
}
