#include <Servo.h>
Servo myServo;

const int piezo = A0;
const int switchPin = 2;
const int yellow = 3;
const int green = 4;
const int red = 5;

int knockVal;
int switchVal;

const int quietKnock = 10;
const int loudKnock = 100;

boolean locked = false;
int numKnocks = 0;

void setup() {
  //attach servo to pin 9
  myServo.attach(9);
  //set up LED output pins
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  //set up input pin for switch
  pinMode(switchPin, INPUT);
  //start serial window
  Serial.begin(9600);
  //turn on green led
  digitalWrite(green,HIGH);
  //set servo to base position
  myServo.write(0);
  //print message to serial window
  Serial.println("The box is unclocked!");

}

void loop() {
  if (locked == false) {
    switchVal = digitalRead(switchPin);
    if (switchVal == HIGH) {
      locked = true;
      digitalWrite(green,LOW);
      digitalWrite(red,HIGH);
      myServo.write(90);
      Serial.println("The box is locked!");
      delay(1000);
    }
  }
  if (locked == true) {
    knockVal = analogRead(piezo);
    if (numKnocks < 3 && knockVal > 0) {
      if (checkForKnock(knockVal) ==  true) {
        numKnocks ++;
      }
      Serial.print(3 - numKnocks);
      Serial.println(" more knocks to go!");
    }
    if (numKnocks >=3) {
      locked = false;
      myServo.write(0);
      delay(20);
      digitalWrite(green,HIGH);
      digitalWrite(red,LOW);
      Serial.println("The box is unlocked!");
    }
  }
}

boolean checkForKnock(int value) {
  if (value > quietKnock && value < loudKnock){
    digitalWrite(yellow,HIGH);
    Serial.print("Valid knock of value ");
    Serial.println(value);
    return false;
  }
}

