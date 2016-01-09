#include <CapacitiveSensor.h>
CapacitiveSensor capSensor = CapacitiveSensor(4,2);

int threshold = 2000;
const int ledPin = 12;



void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  

}

void loop() {
  long sensorValue = capSensor.capacitiveSensor(30);
  Serial.print(sensorValue);
  Serial.print("\n");

  if (sensorValue > threshold) {
    digitalWrite(ledPin,HIGH);
  }
  else {
    digitalWrite(ledPin,LOW);
  }
  delay(1000);

}
