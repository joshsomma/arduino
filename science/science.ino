`int switchState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  switchState = digitalRead(2);
  
  if (switchState == LOW) { // button is not pressed
    digitalWrite(5, HIGH); //  GREEN
    digitalWrite(4, LOW);  //   RED
    digitalWrite(3, LOW);  //  RED
  } else { // button is pressed
    digitalWrite(5, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    delay(250); // wait 1/4 sec
    // toggle red LEDs
    digitalWrite(4, LOW);
    digitalWrite(3, LOW);
    delay(250); // wait 1/4 sec
  }
}
