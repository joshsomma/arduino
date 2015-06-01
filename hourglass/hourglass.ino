//set up vars
const int switchPin = 8;
unsigned long previousTime = 0;
int switchState = 0;
int prevSwitchState = 0; 
int led = 2; //first led output pin
long interval = 10000; //interval of the light switch

void setup() {
  //  set up output pins and input for the switch
  for (int x = 2; x < 8; x++) {
    pinMode(x, OUTPUT);
  }
  pinMode(switchPin, INPUT);
}
void loop() {
  // create var and set current time
  unsigned long currentTime = millis();
  if (currentTime - previousTime > interval) {
    previousTime = currentTime;
    digitalWrite(led,HIGH); // turn on the counter light
    led++; //increment to the next light
}
    if (led > 7) {
    for (y = 0; y < 5; y++) {
		for (int x = 2; x < 8; x++) {
			digitalWrite(x,HIGH);
			delay(100);
			digitalWrite(x,LOW);
		}
		for (int x = 7; x > 1; x--) {
			digitalWrite(x,HIGH);
			delay(100);
			digitalWrite(x,LOW);
		}
    }  	
  }
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
      for (int x = 2;x < 8; x++) {
        digitalWrite(x, LOW);
      }
     led = 2;
     previousTime = currentTime;
    }
  prevSwitchState = switchState;
}

