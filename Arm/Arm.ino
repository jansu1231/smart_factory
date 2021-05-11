#include <Servo.h>

Servo myservo1, myservo2, myservo3; //객체 생성

void setup(){
  
  myservo1.attach(7);   //핀 설정
  myservo2.attach(8);
  myservo3.attach(12);

  myservo1.write(90);   //초기값 설정
  myservo2.write(80);  //앞뒤
  myservo3.write(120);

  Serial.begin(9600);
}


void loop(){

  if(Serial.available()){   //시리얼 통신이 들어오면
    
    int state1 = Serial.parseInt(); //시리얼통신으로 입력 받기
    int state2 = Serial.parseInt();
    int state3 = Serial.parseInt();
    Veiw(state1,state2,state3);
    
    if(state1>=10 && state1<=170){
      myservo1.write(state1);
      delay(100);
    }
    if(state2>=20 && state2<=140){
      myservo2.write(state2);
      delay(100);
    }
    if(state3>=100 && state3<=170){
      myservo3.write(state3);
      delay(100);
    }

  }   
    
   
  
}

void Veiw(int i, int j, int k){ // 시리얼값 보기
  Serial.print("좌우 : ");  
   Serial.println(i);
   Serial.print("상하 : ");
   Serial.println(j);
   Serial.print("앞뒤 : ");
   Serial.println(k);
}
  
