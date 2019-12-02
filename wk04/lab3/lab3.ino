const int switchPin1 = 7;  // accelerates
const int switchPin2 = 8;  // decelerates
int motorspeed = 9;  // motor pin
int a = 0; // the speed

void setup(){
  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(motorspeed, OUTPUT);
}

void loop(){
  if (digitalRead(switchPin1) == LOW){
    a = a+10;
    analogWrite(motorspeed, a);
    delay(1000)
  }

  if (digitalRead(switchPin2) == LOW){
    a = a-10;
    analogWrite(motorspeed, a);
    delay(1000)
  }
}