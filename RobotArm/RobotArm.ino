#include <Servo.h>

Servo myservo1, myservo2, myservo3; //객체 생성

int Electromagnet = 2;

void setup(){
  
  myservo1.attach(7);   //핀 설정80
  myservo2.attach(8);
  myservo3.attach(9);

  myservo1.write(80);   // 앞뒤 20~140
  myservo2.write(30);   // 좌우 0~180초기값 설정
  myservo3.write(115);  // 상하 100~170

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
    delay(500);
    myservo2.write(state2);
    delay(500);
    myservo3.write(state3);
    delay(1000);
    
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
  
