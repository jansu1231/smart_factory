#include <Servo.h>

Servo myservo1, myservo2, myservo3; //객체 생성


void setup(){
  
  myservo1.attach(9);   //핀 설정
  myservo2.attach(10);
  myservo3.attach(11);

  myservo1.write(90);   //초기값 설정
  myservo2.write(90);
  myservo3.write(90);

  Serial.begin(9600);
}

void loop(){
    
  if(Serial.available()){   //시리얼 통신이 들어오면
   
   int state1 = Serial.parseInt(); //시리얼통신으로 입력 받기
   int state2 = Serial.parseInt();
   int state3 = Serial.parseInt();
  
   myservo1.write(state1);        //받은 값 만큼 서보모터 이동 
   myservo2.write(state2);
   myservo3.write(state3);
 
   Serial.print("좌우");  
   Serial.println(state1);
   Serial.print("상하");
   Serial.println(state2);
   Serial.print("앞뒤");
   Serial.println(state3);
  }
}
  
