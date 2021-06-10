#include <Wire.h>
#include "Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); //Adafruit_TCS34725 라이브러리 사용을 위한 객체 생성

const int dir = 5;        //shared direction pin
const int step1 = 6;      //step pin motor 1
int roller_diameter = 32; //roller diameter
float roller_circ = roller_diameter * 3.1415; //circumference of roller
int s = 0;
int color = 0;

void setup() {
  pinMode(dir, OUTPUT);
  pinMode(step1, OUTPUT);
  Wire.begin(0x8);        //slve 주소 8
  Wire.onReceive(receiveEvent);   //입력 받을 경우
  Wire.onRequest(requestEvent);   //요청 받은 값 전송
  Serial.begin(9600);

  if (tcs.begin()) {  //연결 인식
    Serial.println("Found sensor");
  }
  else {              //연결 인식 못함
    Serial.println("No TCS34725 found");
    while (1);        //중단
  }
}
void receiveEvent(int sc) {
  while (Wire.available()) {
    s = Wire.read();
    Serial.print(s);  // 받은 것 확인
  }
}
void requestEvent() {
  Wire.write(color);
}
void MoveBelt(int distance, int direction) { //벨트 움직임
  digitalWrite(dir, direction);                                  //Set the direction of the stepper motors
  for (int p = 0; p <= (200 / roller_circ) * distance ; p += 1) { //200step per rotation divide circumference of roller
    digitalWrite(step1, HIGH);        //pulse stepper motor
    delay(1);                                                    //wait 1ms
    digitalWrite(step1, LOW);          //pulse stepper
    delay(1);                                                    //wait 1ms
  }
}
void RGB_Sensor()
{
  uint16_t clear, red, green, blue; //unit16_t = unsigned short int 타입
  tcs.getRawData(&red, &green, &blue, &clear);  //색상 감지 센서 데이터값 받기

  int r = map(red, 0, 21504, 0, 3900);    //센서값 수치, 최대값 4096
  int g = map(green, 0, 21504, 0, 3100);
  int b = map(blue, 0, 21504, 0, 3600);

  Serial.print("R:\t"); Serial.print(r);      //시리얼 모니터 RGB값 출력
  Serial.print("\tG:\t"); Serial.print(g);
  Serial.print("\tB:"); Serial.println(b);


  if (r > g + 3 && r > b + 3) {
    Serial.println("RED");
    color = 1;
  } else if (g > r + 3 && g > b + 3) {
    Serial.println("GREEN");
    color = 2;
  } else if (b > r + 3 && b > g + 3) {
    Serial.println("BLUE");
    color = 3;
  } else {
    Serial.println("Noting");
    color = 0;
  }
}
void loop() {
  if (s == 1)
  {
    MoveBelt(175, 1); //벨트 움직임
    RGB_Sensor();
    //delay(2000);
    MoveBelt(160, 1);
    s = 0;
  }
}
