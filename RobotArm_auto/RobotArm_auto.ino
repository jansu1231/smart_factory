#include <Servo.h>

#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo myservo1, myservo2, myservo3; //객체 생성

int Electromagnet = 2;

void setup(){
  
  myservo1.attach(servoPin1);   //핀 설정
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);

  pinMode(Electromagnet, OUTPUT);

  Serial.begin(9600);
}

void Arm(int FR, int LR, int TB, int MG){  //로봇팔, 전자석
  myservo1.write(FR);
  delay (500);
  myservo2.write(LR);
  delay (500);
  myservo3.write(TB);
  delay (500);

  if(MG == 1){   //마그넷
      digitalWrite(Electromagnet, HIGH);
      delay(150);
    }else{
      digitalWrite(Electromagnet, LOW);
      delay(150);

    }
}

void Start()
{
  Arm(70,170,120,1);
}

void Grap(){
  Arm(55,30,108,1);
}

void RedSite(){
  Arm(110,30,100,0);
}



void Veiw(int FR, int LR, int TB, int MG){ // 시리얼값 보기
  Serial.print("앞뒤 : ");  
  Serial.println(FR);
  Serial.print("좌우 : ");
  Serial.println(LR);
  Serial.print("상하 : ");
  Serial.println(TB);
  Serial.print("자석 : ");
  Serial.println(MG);
}
  
  
void loop(){

  Start();
  delay(100);
  Grap();
  RedSite();
  
  
  if(Serial.available()){
    int i = Serial.parseInt();
    if(i == 1){
    Start();
  }else if(i == 0){    
    Grap();
    }
  }
  

}
