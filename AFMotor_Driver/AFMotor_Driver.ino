#include <AFMotor.h>    //To inlcude the library of the motor
const int trigPin = A4;  // this constant won't change. It's the pin number of the sensor's output:
const int echoPin = A5; 
 // establish variables for duration of the ping, and the distance result
  // in inches and centimeters:
long duration; 
int distance;  
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ); 
AF_DCMotor motor3(3, MOTOR12_1KHZ); 
AF_DCMotor motor4(4, MOTOR12_1KHZ); 
void setup() { 
  pinMode(trigPin, OUTPUT); //Declare the recieving pin as INPUT
  pinMode(echoPin, INPUT);  //Declare the sending pin as OUTPUT
  Serial.begin(9600);  //Initialize Serial Communication
  motor1.setSpeed(255); //Setting the motor speed
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255); 
  }
  void loop() { 
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    digitalWrite(trigPin, LOW);  
    delayMicroseconds(2); 
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigPin, LOW); 
  // The Echopin is used to read the signal from the Trig: a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
    duration = pulseIn(echoPin, HIGH); 
  // convert the time into a distance and print it
    distance= duration*0.034/2;
    Serial.print("Distance: "); 
    Serial.println(distance); 
  // a condition to check whether the distance is below a certain range
  //The robot will keep turning left while the condition is true (ie. there is an obstacle)
  //Whereas, the robot will go straight when the condition is false (ie. there are no obstacles)
  //We have used Functions for the basic movements
    if(distance < 15) { 
      turn();
      }
    else {
      forward(); 
        } 
} 
//Function for moving the robot forwards
void forward() { 
       motor1.run(BACKWARD);  // Aap ke dilon ki Team ie. Team B Aitchison would like to cordially inform you that hamari tarhan hamara robot bhi ulta chaltha hai ie. FORWARDS aur BACKWARDS ulta hai. THANK YOU
       motor2.run(BACKWARD);
       motor3.run(BACKWARD);
       motor4.run(BACKWARD);
       motor1.setSpeed(255);
       motor2.setSpeed(255);
       motor3.setSpeed(255);
       motor4.setSpeed(255);
            } 
//Function for turning the robot
void turn() {
       motor1.run(BACKWARD); 
       motor2.run(BACKWARD); 
       motor3.run(FORWARD);
       motor4.run(FORWARD);
       motor1.setSpeed(255);
       motor2.setSpeed(255);
       motor3.setSpeed(255);
       motor4.setSpeed(255);
       delay(1000);
                }
