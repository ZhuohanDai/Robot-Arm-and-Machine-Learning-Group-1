/*

   Controls robot are with 4 potentiometer

   To be used to debug and to rule out servos / wiring issues if a problem arises
   processing_osc_to_arduino.pde

   Written by Zhuohan, Hani, Ferdia  2026
*/


#include <Servo.h> // library for controlling servo motors

Servo servo1; // servo object for servo 1
Servo servo2; // servo object for servo 2
Servo servo3; // servo object for servo 3
Servo servo4; // servo object for servo 4

// Potentiometer pins
const int pot1 = A0; // potentiometer 1 is connected to analog pin A0 
const int pot2 = A1; // potentiometer 2 is connected to analog pin A1 
const int pot3 = A2; // potentiometer 3 is connected to analog pin A2 
const int pot4 = A3; // potentiometer 4 is connected to analog pin A3 

// Servo signal pins
const int servoPin1 = 9; // servo 1 signal wire is on pin 9
const int servoPin2 = 7; // servo 2 signal wire is on pin 7
const int servoPin3 = 5; // servo 3 signal wire is on pin 5
const int servoPin4 = 3; // servo 4 signal wire is on pin 3

void setup() {  // runs once when the Arduino starts or resets 
  servo1.attach(servoPin1); // link servo 1 object to its pin
  servo2.attach(servoPin2); // link servo 2 object to its pin
  servo3.attach(servoPin3); // link servo 3 object to its pin
  servo4.attach(servoPin4); // link servo 4 object to its pin

  servo1.write(90); // start servo 1 at the middle position (90 degrees)
  servo2.write(90); // start servo 2 at the middle position (90 degrees)
  servo3.write(90); // start servo 3 at the middle position (90 degrees)
  servo4.write(90); // start servo 4 at the middle position (90 degrees)
}

void loop() { // runs over and over forever
  int val1 = analogRead(pot1); // read potentiometer 1 (a number from 0 to 1023)
  int val2 = analogRead(pot2); // read potentiometer 2 (a number from 0 to 1023)
  int val3 = analogRead(pot3); // read potentiometer 3 (a number from 0 to 1023)
  int val4 = analogRead(pot4); // read potentiometer 4 (a number from 0 to 1023)

  int angle1 = map(val1, 0, 1023, 0, 180);  // convert the 0-1023 reading into a 0-180 degree angle 
  int angle2 = map(val2, 0, 1023, 0, 180); // same conversion for servo 2 
  int angle3 = map(val3, 0, 1023, 0, 180); // same conversion for servo 3 
  int angle4 = map(val4, 0, 1023, 0, 180); // same conversion for servo 4


  servo1.write(angle1); // move servo 1 to the angle set by potentiometer 1
  servo2.write(angle2); // move servo 2 to the angle set by potentiometer 2
  servo3.write(angle3); // move servo 3 to the angle set by potentiometer 3
  servo4.write(angle4); // move servo 4 to the angle set by potentiometer 4

  delay(15); // short pause so the servos have time to reach their positions
}