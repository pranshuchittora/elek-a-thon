#include <Servo.h>
Servo myservo;
float temp;
float mv;
float cel;
int pos = 0;
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distance;
//
void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  myservo.attach(7);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
}
void loop()
{
  temp = analogRead(A0);
  mv = ( temp / 1024.0) * 5000.0;
  cel = mv / 10;
  //  Serial.println(cel);
//  sv();
  ultra();
  if (cel >= 25){
    digitalWrite(9,HIGH);
    }
//  else if(cel <=25 || distance>=25)
//  digitalWrite(8,LOW);
Serial.println(cel);
}
void sv() {
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 0; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}
//
void ultra() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
//  Serial.print("Distance: ");
//  Serial.println(distance);
}
