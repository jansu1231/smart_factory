#include <Servo.h>

#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo myservo1, myservo2, myservo3; //객체 생성

int Electromagnet = 2;

void setup() {

  myservo1.attach(servoPin1);   //앞,뒤 20~140
  myservo2.attach(servoPin2);   //상,하 100~170
  myservo3.attach(servoPin3);   //좌,우 0~180

  myservo1.write(30);
  myservo2.write(170);
  myservo3.write(180);
  pinMode(Electromagnet, OUTPUT);

  Serial.begin(9600);
}

void Veiw(int FR, int TB, int LR, int MG) { // 시리얼값 보기
  Serial.print("앞뒤 : ");
  Serial.print(FR);
  Serial.print("\t상하 : ");
  Serial.print(TB);
  Serial.print("\t좌우 : ");
  Serial.print(LR);

  Serial.print("\t자석 : ");
  Serial.println(MG);
}

void Arm(int FR, int TB, int LR, int MG){  //Arm Control
  myservo1.write(FR);
  delay (500);
  myservo2.write(TB);
  delay (500);//
  myservo3.write(LR);
  delay (500);
  
   if (MG==1){
    digitalWrite(Electromagnet, HIGH);
    delay(150);
  }else{
    digitalWrite(Electromagnet, LOW);
    delay(150);
  }
}



void loop() {

  while (Serial.available()) { 
    int state1 = Serial.parseInt();//시리얼통신으로 입력 받기
    int state2 = Serial.parseInt();
    int state3 = Serial.parseInt();
    int input = Serial.parseInt();
    Veiw(state1, state2, state3, input);
    
    Arm(state1,state2,state3,input);
  }
}
