#include <Servo.h>

Servo myservo1, myservo2, myservo3; //객체 생성

int Electromagnet = 2;

void setup(){
  
  myservo1.attach(7);   //핀 설정
  myservo2.attach(8);
  myservo3.attach(12);

  myservo1.write(90);   //초기값 설정
  myservo2.write(80);  //앞뒤 20~140
  myservo3.write(120);  // 위아래 100~170

  pinMode(Electromagnet, OUTPUT);

  Serial.begin(9600);
}


void loop(){

  if(Serial.available()){   //시리얼 통신이 들어오면
    
    int state1 = Serial.parseInt(); //시리얼통신으로 입력 받기
    int state2 = Serial.parseInt();
    int state3 = Serial.parseInt();
    int input = Serial.parseInt();
    
    Veiw(state1,state2,state3,input);
    
      
      myservo1.write(state1);
   
      myservo2.write(state2);
    
      myservo3.write(state3);
    
    if(input == 1){   //마그넷
      digitalWrite(Electromagnet, HIGH);
      delay(150);
    }
    else{
      digitalWrite(Electromagnet, LOW);
      delay(150);
    }

  }   
   
}

void Veiw(int LR, int TB, int FR, int MG){ // 시리얼값 보기
  Serial.print("좌우 : ");  
  Serial.println(LR);
  Serial.print("앞뒤 : ");
  Serial.println(FR);
  Serial.print("상하 : ");
  Serial.println(TB);
 
  Serial.print("자석 : ");
  Serial.println(MG);
}
  
