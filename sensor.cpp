#include <Arduino.h>
#define trigPin 12
#define echoPin 11
#define ledPin 10

void start(){
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(ledPin, OUTPUT);
//start console communication
Serial.begin(9600);
}
