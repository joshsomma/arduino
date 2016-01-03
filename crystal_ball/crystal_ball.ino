//include lcd lib
#include <LiquidCrystal.h>
// assign ports to lcd
LiquidCrystal lcd(12,11,5,4,3,2);
//set up vars
const int switchPin = 6;
int switchState = 0;
int prevSwitchState = 0;
int reply;

void setup() {
  //start lcd and tell it how big the screen is
  lcd.begin(16,2);
  //init switchpin
  pinMode(switchPin,INPUT);
  //print intro message
  lcd.print("Ask the");
  lcd.setCursor(0,1);
  lcd.print("Crystal Ball");
}

void loop() {
  // check if switchPin has changed; if yes and state == low, get a new reply
  switchState = digitalRead(switchPin);
  if (switchState != prevSwitchState) {
    if (switchState == LOW) {
      reply = random(8);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("The ball says:");
      lcd.setCursor(0,1);
      switch(reply){
        case 0:
        lcd.print("Yes");
        break;
        case 1:
        lcd.print("Most likely");
        break;
        case 2:
        lcd.print("Certainly");
        break;
        case 3:
        lcd.print("Outlook good");
        break;
        case 4:
        lcd.print("Unsure");
        break;
        case 5:
        lcd.print("Ask again");
        break;
        case 6:
        lcd.print("Doubtful");
        break;
        case 7:
        lcd.print("No");
        break;
      }
    }
  }
  prevSwitchState = switchState;
}
  

