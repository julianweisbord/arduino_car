#include <Arduino.h>
#define trigPin 12
#define echoPin 11
#define backUpLed 10 //reverse led pin
#define led_pin 2 //forward pin

void start(){
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(backUpLed, OUTPUT);
pinMode(led_pin, OUTPUT);
//start console communication
Serial.begin(9600);
}

int ultra_sonic_pulse(){
  // play with delay
  // delay(300);
  long time, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(3);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  time =pulseIn(echoPin, HIGH);
  //.034029 cm/10^-6 s
  //divide by 2 because the signal comes back to the HC-SR04
  distance = (.034029*time)/2;

  if(distance > 100 || distance <= 0){
    Serial.println("Distance is too large or too small.");
  }
  else{
    Serial.println(distance);
    Serial.print(" cm\n");
    //turn red led on
    if (distance < 22){
      digitalWrite(led_pin, LOW);
      digitalWrite(backUpLed, HIGH);
      // Also stop car
      return 0;
    }
    else{
      digitalWrite(backUpLed, LOW);
      digitalWrite(led_pin, HIGH);

    }
  }
  return 1;

}
