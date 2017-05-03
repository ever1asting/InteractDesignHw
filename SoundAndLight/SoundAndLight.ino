#include <Adafruit_NeoPixel.h>

int light_state;
int sound_state;
Adafruit_NeoPixel ColorLED = Adafruit_NeoPixel(1, 6, NEO_GRB + NEO_KHZ800);

void setup()
{
  pinMode(A0, INPUT);
  pinMode(A2, INPUT);
  ColorLED.begin();
  Serial.begin(9600);
}

void loop()
{
  light_state = analogRead(A0);
  sound_state = analogRead(A2);
  if (light_state < 170 && sound_state > 600) {
    ColorLED.setPixelColor(0, ColorLED.Color(55, 55, 55));
    ColorLED.show();
    delay(5000);
  }
  else {
    ColorLED.setPixelColor(0, ColorLED.Color(0, 0, 0));
    ColorLED.show();
  }
  Serial.print("light_state:");
  Serial.print(light_state);
  Serial.print(".....sound_state:");
  Serial.println(sound_state);
  delay(1000); 
}
