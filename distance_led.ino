```cpp
#include <Wire.h>

#define echoPin 34
#define trigPin 32
const int ledPin = 21;

long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2; 
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);

  if (distance < 120) {
    Serial.println("LED ON"); 
    digitalWrite(ledPin, HIGH);
  } else {
    Serial.println("LED OFF");
    digitalWrite(ledPin, LOW);
  }
}
