

const int dir = 5; //shared direction pin
const int step1 = 6; //step pin motor 1 

const int speed = 2200; //속도 제어

void setup() {
  pinMode(dir,OUTPUT); 
  pinMode(step1,OUTPUT); //configure pins
  digitalWrite(dir,1);
  Serial.begin(9600);      
}

void loop() {
  
    digitalWrite(step1,HIGH);
    delayMicroseconds(speed);
    digitalWrite(step1,LOW);
    delayMicroseconds(speed);
  
 
} 
