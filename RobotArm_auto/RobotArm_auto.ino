#include <Servo.h>

#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo myservo1, myservo2, myservo3; //객체 생성
int Electromagnet = 2;

typedef struct {
  int FR;
  int TB;
  int LR;
}coo;

coo act[4][3] = {{{30,170,180},{75,110,180},{30,110,0}},
                {{120,123,5},{112,110,3},{105,98,2}},
                {{112,110,3},{110,110,22},{113,113,40}},
                {{105,98,2},{105,97,24},{105,100,44}}};
                   
void setup(){
  myservo1.attach(servoPin1);   //핀 설정
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);
  pinMode(Electromagnet, OUTPUT);


  

  Serial.begin(9600);
}



void Arm(int FR, int TB, int LR){  //로봇팔, 전자석
  myservo1.write(FR);
  delay (500);
  myservo2.write(TB);
  delay (500);//
  myservo3.write(LR);
  delay (500);
}

void Start()
{
  Arm(30,170,180);
}
void Grap(){
  Arm(75,110,180);
}

void Veiw(int FR, int TB, int LR){ // 시리얼값 보기
  Serial.print("앞뒤 : ");  
  Serial.println(FR);
  Serial.print("좌우 : ");
  Serial.println(TB);
  Serial.print("상하 : ");
  Serial.println(LR);
}
  
  
void loop(){

  Arm(act[0][0].FR,act[0][0].TB,act[0][0].LR);
  delay(1000);
  Arm(act[0][1].FR,act[0][1].TB,act[0][1].LR);
  delay(1000);
  Arm(act[0][0].FR,act[3][2].TB,act[3][2].LR);
  delay(1000);
  Arm(act[3][2].FR,act[3][2].TB,act[3][2].LR);
  delay(1000);
}
