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
coo act[4][3] = {{{90,170,180},{107,130,180},{90,110,0}},    //좌표값
                {{148,144,5},{138,133,5},{131,120,4}},
                {{149,145,22},{138,131,23},{131,120,24}},
                {{150,147,37},{141,135,41},{133,123,43}}};

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
    delay(2000);
  } else {
    digitalWrite(Electromagnet, LOW);
    delay(2000);
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
    delay(1000);
    Arm(act[sort][RGB[0]].FR, act[sort][RGB[0]].TB, act[sort][RGB[0]].LR);
    delay(1000); 
    RGB[0]++;
    
    if(RGB[0]==3)
    {
      RGB[0]=0;
    }
  }
  else if(sort==2){   //초록 위치
    Serial.println("g");
    Arm(act[0][0].FR, act[sort][RGB[1]].TB, act[sort][RGB[1]].LR);
    delay(1000);
    Arm(act[sort][RGB[1]].FR, act[sort][RGB[1]].TB, act[sort][RGB[1]].LR);
    delay(1000);
    RGB[1]++;
    if(RGB[1]==3)
    {
      RGB[1]=0;
    }
  }
  
  else if(sort==3){   //파랑 위치
    Serial.println("b");
    Arm(act[0][0].FR, act[sort][RGB[2]].TB, act[sort][RGB[2]].LR);
    delay(1000);
    Arm(act[sort][RGB[2]].FR, act[sort][RGB[2]].TB, act[sort][RGB[2]].LR);
    delay(1000);
    RGB[2]++;
    if(RGB[2]==3)
    {
      RGB[2]=0;
    }
  }
  Magnet(0);
}

void loop() {
  
  if(color !=0 && color != 4){
    Arm_grab();
    Site(color);
    Arm_init();
    color=0;
  }
  if(color == 4){
    for(int i=0;i<4;i++){
      RGB[i]=0;
    }
  }
}
