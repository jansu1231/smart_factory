#include <Wire.h>
#include "Adafruit_TCS34725.h"

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); //Adafruit_TCS34725 라이브러리 사용을 위한 객체 생성

int red_led = 9;
int green_led = 10;
int blue_led = 11;

char rgb = 0;

const int dir = 5; //shared direction pin
const int step1 = 6; //step pin motor 1 

const int speed = 2200; //속도 제어

void setup() {
  Wire.begin(0x8);        //slve with address 8

  Wire.onReceive(receiveEvent); //입력받을 경우
  Wire.onRequest(requestEvent);   //요청받은 값 전송
  
    
  pinMode(dir,OUTPUT); 
  pinMode(step1,OUTPUT); //configure pins
  digitalWrite(dir,0);
  
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);   

   if (tcs.begin()) {  //연결 인식
    Serial.println("Found sensor");
  } 
  else{               //연결 인식 못함
    Serial.println("No TCS34725 found");
    while(1);         //중단
    
  }
  Serial.begin(9600);
}

 void requestEvent(){
  Wire.write(rgb);
}
void receiveEvent(int a){
  while(Wire.available()){
    int s = Wire.read();

    Serial.print(s); //받은 것 확인
  
    if (s == 1){
      for (int i = 0; i<300; i++){
        digitalWrite(step1, HIGH);
        delayMicroseconds(speed);
        digitalWrite(step1, LOW);
        delayMicroseconds(speed);
      }
    }

    else if (s == 2){
      for (int i = 0; i < 200; i++){
        digitalWrite(step1, HIGH);
        delayMicroseconds(speed);
        digitalWrite(step1, LOW);
        delayMicroseconds(speed);
      }
    }
  }
}

void loop() {
  
  delay(1000);
  uint16_t clear, red, green, blue; //unit16_t = unsigned short int 타입
  tcs.getRawData(&red, &green, &blue, &clear);  //색상 감지 센서 데이터값 받기
  
  int r = map(red, 0, 21504, 0, 4096);          //센서값 수치
  int g = map(green, 0, 21504, 0, 3500);
  int b = map(blue, 0, 21504, 0, 4096);

 Serial.print("R:\t"); Serial.print(r);      //시리얼 모니터 RGB값 출력
 Serial.print("\tG:\t"); Serial.print(g);
 Serial.print("\tB:"); Serial.println(b);

  if (r>g && r>b)
 {
  analogWrite(red_led,255);
  analogWrite(green_led,0);
  analogWrite(blue_led,0);
  rgb = ('R');

 }
  else if (g>b && g>r)
 {
  analogWrite(red_led,0);
  analogWrite(green_led,255);
  analogWrite(blue_led,0);
  rgb = ('G');
 
 }
  else if (b>r && b>g)
 {
  analogWrite(red_led,0);
  analogWrite(green_led,0);
  analogWrite(blue_led,255);
  rgb = ('B');
 }

}
