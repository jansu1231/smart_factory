#include <Servo.h>

Servo myservo1, myservo2, myservo3; //객체 생성

int Electromagnet = 2;

void setup(){
  
  myservo1.attach(7);   //핀 설정
  myservo2.attach(8);
  myservo3.attach(9);

  myservo1.write(80);   // 앞뒤 20~140
  myservo2.write(30);   // 좌우 0~180초기값 설정
  myservo3.write(115);  // 상하 100~170

  pinMode(Electromagnet, OUTPUT);

  Serial.begin(9600);
}

void Arm(int FR, int LR, int TB, int MG){  //로봇팔, 전자석
  myservo1.write(FR);
  delay (150);
  myservo2.write(LR);
  delay (150);
  myservo3.write(TB);
  delay (1000);

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
  Arm(80,30,115,1);
}

void Grap(){
  Arm(80,30,108,1);
}

void RedSite(){
  Arm(
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


  if(Serial.available()){
    int i = Serial.parseInt();
  
  if(i == 1){
    Start();
  }else if(i == 0){    
    Grap();
  }
  }
    
    
   
}
