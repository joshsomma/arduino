//call servo include
#include <Servo.h>;
//instantiate servo object
Servo myServo;
//set up vars
int const potPin = A0;
int potVal;
int angle;


void setup() {
  //attach servo motor to pin 9
  myServo.attach(9);
  //invoke serial window
  Serial.begin(9600);
  

}

void loop() {
  // set potentiometer value
  potVal = analogRead(potPin);
  Serial.print("potVal: ");
  Serial.print(potVal);
  //set and convert the angle
  angle = map(potVal,0,1023,0,179);
  Serial.print(", angle: ");
  Serial.print(angle);
  Serial.print("\n");
  //move the servo
  myServo.write(angle);
  delay(15);
}
