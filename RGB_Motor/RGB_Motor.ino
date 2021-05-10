#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); //Adafruit_TCS34725 라이브러리 사용을 위한 객체 생성



char rgb = 0;

const int dir = 5; //shared direction pin
const int step1 = 6; //step pin motor 1 

const int speed = 2200; //속도 제어

void setup() {

  pinMode(dir,OUTPUT); 
  pinMode(step1,OUTPUT); //configure pins
  digitalWrite(dir,0);
  
  Serial.begin(9600);
}

void rgbsensor(){
  
  delay (1000);
  uint16_t clear, red, green, blue; //unit16_t = unsigned short int 타입
  tcs.getRawData(&red, &green, &blue, &clear);  //색상 감지 센서 데이터값 받기
  
  int r = map(red, 0, 21504, 0, 4096);          //센서값 수치
  int g = map(green, 0, 21504, 0, 3500);
  int b = map(blue, 0, 21504, 0, 4096);

 Serial.print("R:\t"); Serial.print(r);      //시리얼 모니터 RGB값 출력
 Serial.print("\tG:\t"); Serial.print(g);
 Serial.print("\tB:"); Serial.println(b);
 
}

void motor(){
  
    digitalWrite(step1, HIGH);
    delayMicroseconds(speed);
    digitalWrite(step1, LOW);
    delayMicroseconds(speed);
    
}
  

void loop() {

  //rgbsensor();
  motor();
  
  

}
