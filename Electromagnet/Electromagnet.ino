

int Electromagnet = 2;



void setup() {
  pinMode(Electromagnet, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  

  if(Serial.available()){
    int input = Serial.parseInt();
    if(input == 1){
      digitalWrite(Electromagnet, HIGH);
      delay(200);
    }
    else{
      digitalWrite(Electromagnet, LOW);
      delay(200);
    }
    Serial.println(input);
  }
}
