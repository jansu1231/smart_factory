#include <Servo.h>

#define servoPin1 9
#define servoPin2 10
#define servoPin3 11

Servo myservo1, myservo2, myservo3; //객체 생성

int Electromagnet = 2;

void setup(){

  
  myservo1.attach(servoPin1);   //핀 설정80
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);

     // 앞뒤 20~140
     // 좌우 0~180
    // 상하 100~170

  pinMode(Electromagnet, OUTPUT);

  Serial.begin(19200);
}

void Veiw(int FR, int LR, int TB, int MG){ // 시리얼값 보기
  Serial.print("앞뒤 : ");  
  Serial.print(FR);
  Serial.print("\t좌우 : ");
  Serial.print(LR);
  Serial.print("\t상하 : ");
  Serial.print(TB);
 
  Serial.print("\t자석 : ");
  Serial.println(MG);
}
  

void loop(){

  while(Serial.available()){   //시리얼 통신이 들어오면
  
    
    int state1 = Serial.parseInt();//시리얼통신으로 입력 받기
    int state2 = Serial.parseInt();
    int state3 = Serial.parseInt();
    int input = Serial.parseInt();
    
    Veiw(state1,state2,state3,input);
    
    myservo1.write(state1);
    delay(500);
    myservo2.write(state2);
    delay(500);
    myservo3.write(state3);
    delay(500);
    
    
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
