const int sensorPin = A0;
const float baselineTemp = 16.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //open a serial port
  for (int pinNumber = 2; pinNumber < 5; pinNumber++) {
      pinMode(pinNumber, OUTPUT);
      digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal = analogRead(sensorPin); //set the sensor value
  Serial.print("Sensor value: "); //print the sensor value label
  Serial.print(sensorVal); //print the sensor value
  
  float voltage = (sensorVal/1024.0) * 5.0; // convert sensor value to voltage
  Serial.print(", Volts: "); //print the voltage label
  Serial.print(voltage); // print the voltage value
  
  Serial.print(", degrees C: ");
  //convert voltage to temperature in C
  float temp = (voltage - .5) * 100.0;
  Serial.println(temp);
  
  if (temp < baselineTemp) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp >= baselineTemp + 2 && temp < baselineTemp + 4) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temp >= baselineTemp + 4 && temp < baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temp >= baselineTemp + 6) {
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  }
  delay(1000);
}
