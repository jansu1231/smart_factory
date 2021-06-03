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
coo act[4][3] = {{{30,170,180},{75,110,180},{30,110,0}},    //Coordinates
                {{120,127,5},{112,110,3},{105,98,2}},
                {{120,128,22},{110,110,22},{105,97,24}},
                {{126,132,37},{113,115,41},{106,104,44}}};   

void setup() {
  Wire.begin(0x9);        //slve with address 9
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
    color = Wire.read(); //받은값 읽기
    Serial.println(color);// 받은 것 확인
  }
}

void Arm(int FR, int TB, int LR) { //Arm Control
  myservo1.write(FR);
  delay (1000); 
  myservo2.write(TB);
  delay (1000);
  myservo3.write(LR);
  delay (1000); 
}
void Magnet(int MG) {   //Magnet Control
  if (MG == 1) {
    digitalWrite(Electromagnet, HIGH);
    delay(150);
  } else {
    digitalWrite(Electromagnet, LOW);
    delay(150);
  }
}

void Arm_init(){
  Arm(act[0][0].FR, act[0][0].TB, act[0][0].LR);
}
void Arm_grab(){
  Arm(act[0][1].FR, act[0][1].TB, act[0][1].LR);
  Magnet(1);
}

void Site(int sort){
  
  if(sort==1){
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
  else if(sort==2){
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
  
  else if(sort==3){
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
