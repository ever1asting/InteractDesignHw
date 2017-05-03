#include <Adafruit_NeoPixel.h>

int light_state;
int sound_state;
Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800);

void setup()
{
  pinMode(A2, INPUT); 
  pinMode(A4, INPUT); 
  ColorLED.begin();
  Serial.begin(9600); 
}

void loop()
{
  light_state = analogRead(A2); 
  sound_state = analogRead(A4); 
  if (light_state < 200 && sound_state > 600) {
    ColorLED.setPixelColor(0, ColorLED.Color(255, 255, 255));
    ColorLED.show();
    delay(5000);
  }
  else {
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0));
    ColorLED.show();
  }
}
