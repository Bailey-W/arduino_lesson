// C++ code
//

#define BUTTON 8
#define LED    2

void setup()
{
  pinMode(BUTTON, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  digitalWrite(LED, digitalRead(BUTTON));
  delay(100);
}
