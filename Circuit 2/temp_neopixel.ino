#include <Adafruit_NeoPixel.h>

// C++ code
//

#define TEMP_SENSOR A1
#define LED_PIN      2

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 10

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(115200);
  pinMode(TEMP_SENSOR, INPUT);
  
  // Sets up the LED strip and clears any previous colors
  strip.begin();
  strip.show();
}



void loop()
{
  // Reads the temperature
  int temp = analogRead(TEMP_SENSOR);
  
  // Calculate red value (out of 255)
  int r = 255 * ((float)temp / (float)358);
  // Calculate blue value (out of 255)
  int b = 255 - r;
  // Calculate how many LEDs should be on
  int count = 10 * ((float)temp / (float)358);
  
  // Fills the "on" LEDs with the correct color
  uint32_t currentColor = strip.Color(r, 0, b);
  strip.fill(currentColor, 0, count);
  
  // Resets the "off" LEDs to be off
  uint32_t noColor = strip.Color(0,0,0);
  strip.fill(noColor, count, 10 - count);
  
  strip.show();
  delay(100);
}
