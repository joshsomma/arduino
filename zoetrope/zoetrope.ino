// set up vars
const int controlPin1 = 2;
const int controlPin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5;
const int potPin = A0;

int onOffSwitchState = 0;
int previousOnOFfSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  //changes motor direction, pin 4
  pinMode(directionSwitchPin, INPUT);
  //turns motor on and off; pin 5
  pinMode(onOffSwitchStateSwitchPin, INPUT);
  //pins 2 & 3 talk to the H-Bridge and tells it which way to spin the motor
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  //pin 9 enables the H-Bridge
  pinMode(enablePin, OUTPUT);
  //turns off the H-Bridge at start of program
  digitalWrite(enablePin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin);
  delay(1);
  directionSwitchState = digitalRead(directionSwitchPin);
  motorSpeed = analogRead(potPin)/4;

  if (onOffSwitchState != previousOnOFfSwitchState) {
    if (onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }
  if(directionSwitchState != previousDirectionSwitchState) {
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    };
  }
  if (motorDirection == 1) {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
  }
  else {
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
  }
  if (motorEnabled == 1) {
    analogWrite(enablePin, motorSpeed);
  }
  else {
    analogWrite(enablePin, 0);
  }
  previousDirectionSwitchState = directionSwitchState;
  previousOnOFfSwitchState = onOffSwitchState;
}
