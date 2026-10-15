/*

   Controls robot arm with 9 states using mouse control on wekinator

   To be used with the Processing sketch
   processing_osc_to_arduino.pde

   Written by Zhuohan, Hani, Ferdia  2026
*/


#include <Servo.h> // include the Servo library so we can control servo motors

Servo servo1;  // create a servo object for servo 1
Servo servo2;  // create a servo object for servo 2
Servo servo3;  // create a servo object for servo 3
Servo servo4;  // create a servo object for servo 4

// variable used to store the latest message from Processing (named blinkCode from the original LED example)
int robotCode = -1;

void setup() {  // runs once when the Arduino starts or resets 
  Serial.begin(9600);  // initialise the serial communication
servo1.attach(9); // tell the servo1 object it is wired to pin 9
servo2.attach(7); // tell the servo2 object it is wired to pin 7
servo3.attach(5); // tell the servo3 object it is wired to pin 5
servo4.attach(3); // tell the servo4 object it is wired to pin 3
  servo1.write(90); // move servo 1 to its 90 degree starting position
  servo2.write(90); // move servo 2 to its 90 degree starting position
  servo3.write(90); // move servo 3 to its 90 degree starting position
  servo4.write(90); // move servo 4 to its 90 degree starting position

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {  // runs over and over forever 
  // wait for a message to arrive
  if (Serial.available()) {
    // save the message when it arrives
    robotCode = Serial.read();  // read one byte (the state number 1-9) and store it
  }

  switch (robotCode) {  // choose what to do based on the last message received
    case 1: // when Classifier recieved from wekinator is 1 run below code
      // Servo 1 Open 
      servo1.write(30);  // turn servo 1 to 30 degrees (open)  
      break;
    case 2: // when Classifier recieved from wekinator is 2  run below code
      // Servo 1 Closed
     servo1.write(180);   // turn servo 1 to 180 degrees (closed)  
     case 3: // when Classifier recieved from wekinator is 3 run below code
      // Servo 2 Open 
      servo2.write(30);   // turn servo 2 to 30 degrees (open)
      break;
    case 4: // when Classifier recieved from wekinator is 4 run below code
      // Servo 2 Closed
     servo2.write(180);   // turn servo 2 to 180 degrees (closed) 
     case 5: // when Classifier recieved from wekinator is 5 run below code
      // Servo 3 Open 
      servo3.write(30);   // turn servo 3 to 30 degrees (open) 
      break;
    case 6: // when Classifier recieved from wekinator is 6 run below code
      // Servo 3 Closed
     servo3.write(180);   // turn servo 3 to 180 degrees (closed) 
     case 7: // when Classifier recieved from wekinator is 7 run below code
      // Servo 4 Open 
      servo4.write(1);   // turn servo 4 to 1 degrees (open) 
      break;
    case 8: // when Classifier recieved from wekinator is 8 run below code
      // Servo 4 Closed  // turn servo 4 to 180 degrees (closed) 
     servo4.write(90);   
      break;
    case 9: 
       //Do nothing
      break;
  
  
  }

}