#include <Servo.h>

#define servoPin1 8
#define servoPin2 9
#define servoPin3 10

Servo myservo1, myservo2, myservo3; //객체 생성

int Electromagnet = 2;

void setup(){

  
  myservo1.attach(servoPin1);   //핀 설정80
  myservo2.attach(servoPin2);
  myservo3.attach(servoPin3);

  pinMode(servoPin1, OUTPUT);
  pinMode(servoPin2, OUTPUT);
  pinMode(servoPin3, OUTPUT);
     // 앞뒤 20~140
     // 좌우 0~180초기값 설정
    // 상하 100~170

  pinMode(Electromagnet, OUTPUT);

  Serial.begin(9600);
}


void loop(){

 
  if(Serial.available()){   //시리얼 통신이 들어오면
    
  int state1 = Serial.parseInt();//시리얼통신으로 입력 받기
  int state2 = Serial.parseInt();
  int state3 = Serial.parseInt();
  int input = Serial.parseInt();
  
  int servo1 = map(state1,0,1023,20,140);
  int servo2 = map(state2,0,1023,0,180);
  int servo3 = map(state3,0,1023,100,170);
  
  myservo1.write(servo1);
  delay(1000);
  myservo2.write(servo2);
  delay(1000);
  myservo3.write(servo3);
  delay(1000);
  
  Veiw(servo1,servo2,servo3,input);
  
    if(input == 1){   //마그넷
      digitalWrite(Electromagnet, HIGH);
      delay(150);
    }
    else{
      digitalWrite(Electromagnet, LOW);
      delay(150);
    }
  
    
//    myservo2.write(state2);
//    delay(1000);
//    myservo2.detach();
//    

//    myservo3.write(state3);
//    delay(1000);
//    myservo3.detach();
//    

//    
   

  }   
   
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
  
