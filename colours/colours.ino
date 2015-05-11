  
  // declare led pin vars
  const int greenLEDPin = 9;
  const int redLEDPin = 11;
  const int blueLEDPin = 10;
  // declare sensor pin vars
  const int redSensorPin = A0;
  const int greenSensorPin = A1;
  const int blueSensorPin = A2;
  //declare colour value vars
  int redValue = 0;
  int greenValue = 0;
  int blueValue = 0;
  //declare mapped value vars
  int redSensorValue = 0;
  int greenSensorValue = 0;
  int blueSensorValue = 0;
void setup() {
  //open serial connection
  Serial.begin(9600);
  // set up output pins
  pinMode(greenLEDPin,OUTPUT);
  pinMode(redLEDPin,OUTPUT);
  pinMode(blueLEDPin,OUTPUT);
}
void loop() {
  // set sensor values
  redSensorValue = analogRead(redSensorPin);
  delay(50);
  greenSensorValue = analogRead(greenSensorPin);
  delay(50);
  blueSensorValue - analogRead(blueSensorPin);
  //print out values to serial
  Serial.print("Raw sensor values \t Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t Blue: ");
  Serial.print(blueSensorValue);
  //convert sensor values to 0-255
  redValue = redSensorValue/4;
  greenValue = greenSensorValue/4;
  blueValue = blueSensorValue/4;
  //print converted values to serial
  Serial.print(" Mapped sensor values \t Red: ");
  Serial.print(redValue);
  Serial.print("\t Green: ");
  Serial.print(greenValue);
  Serial.print("\t Blue: ");
  Serial.print(blueValue);
  Serial.print("\n");
  //set the light levels
  analogWrite(redLEDPin,redValue);
  analogWrite(greenLEDPin,greenValue);
  analogWrite(blueLEDPin,blueValue);
}
