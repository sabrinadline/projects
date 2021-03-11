#include "Ultrasonic.h"
Ultrasonic ultrasonic(12, 13);
#define led1 3
#define led2 4
#define led3 5
#define buz A0
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin (9600);
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  pinMode (led3, OUTPUT);
  pinMode (A0, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  distance = ultrasonic.Ranging(CM); //Use 'CM' for centimeters or 'INC' for inches
  if (distance <= 17) //hijau
  {
    digitalWrite(led1, HIGH);
    digitalWrite(A0, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  }
  if  ((distance >= 9) && (distance <= 13)) //kuning
  {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
    delay (1000);
    digitalWrite(led2, LOW);
  }
  if ((distance >= 2) && (distance < 9)) //merah
  {
    digitalWrite(led3, HIGH);
    digitalWrite(A0, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
  }
  delay(500);
}
