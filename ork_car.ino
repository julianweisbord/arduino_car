
#include <Servo.h> //includes the servo library so that you can easily use its functions
#include "sensor.h"
//Constants; This is where you should define anything you will use that won't change in your code
// const int switchPin = 2;    // switch input
const int motor1Pin = 5;    // H-bridge leg 1 (pin 2, 1A)
const int motor2Pin = 4;    // H-bridge leg 2 (pin 7, 2A)
const int enablePin = 3;    // H-bridge enable pin

const int motor3Pin = 7;    // H-bridge leg 3
const int motor4Pin = 8;    // H-bridge leg 4
const int enable2Pin = 6;
int speed;


Servo sonicServo;  //Create the servo object. This names the servo sonicServo which you will later call in your code.

void setup() { // the word void means that this function won't return anything. The setup function get's called in arduino, at the beginning to define all the pins you will be using.
    // set all the other pins you're using as outputs:
    start();
    pinMode(motor1Pin, OUTPUT);
    pinMode(motor2Pin, OUTPUT);
    pinMode(enablePin, OUTPUT);

    pinMode(motor3Pin, OUTPUT);
    pinMode(motor4Pin, OUTPUT);
    pinMode(enable2Pin, OUTPUT);



    //This is the onboard LED that can be helpful for testing
    pinMode(13, OUTPUT);
    pinMode(13, HIGH);



    // set enablePin high so that motor can turn on:
    analogWrite(enablePin, 255);
    
}

void loop() { // This is the main loop that will get run. This is where you should put all your magical super awesome avoidance algorithms.
  
  speed = ultra_sonic_pulse();
  if(speed !=0){
    driveMotor(1);
  }
  else{
    driveMotor(0);
  }
  delay(500);
}

void driveMotor(int dir){
  //Right Motor is 1, Left Motor is 2
  /* motorDir: forward 1, reverse 0 */
  digitalWrite(motor1Pin, dir);  // set leg 1 of the H-bridge high
  digitalWrite(motor2Pin, 0);   // set leg 2 of the H-bridge low
  analogWrite(enablePin, 195);

  digitalWrite(motor3Pin, dir);  // set leg 1 of the H-bridge high
  digitalWrite(motor4Pin, 0);   // set leg 2 of the H-bridge low
  analogWrite(enable2Pin, 195);
}
