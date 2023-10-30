#include <Adafruit_NeoPixel.h>

// C++ code
//

#define TEMP_SENSOR A1
#define LED          2
void setup()
{
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(TEMP_SENSOR, INPUT);
}

void loop()
{
  int temp = analogRead(TEMP_SENSOR);
  Serial.println(temp);
  delay(100);
}
