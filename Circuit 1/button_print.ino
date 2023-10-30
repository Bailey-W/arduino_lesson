// C++ code
//

#define BUTTON 8
#define LED    2

void setup()
{
  Serial.begin(115200);
  pinMode(BUTTON, INPUT);
}

bool isPressed = false;

void loop() {
  if(digitalRead(BUTTON) && !isPressed) {
   	Serial.println("PRESSED!");
    isPressed = true;
  }else if(!digitalRead(BUTTON) && isPressed) {
   	Serial.println("RELEASED!");
    isPressed = false;
  }
}

/* Bad loop - continuously prints
void loop()
{
  if(digitalRead(BUTTON)) {
   	Serial.println("PRESSED!"); 
  }
  delay(100);
}
*/
