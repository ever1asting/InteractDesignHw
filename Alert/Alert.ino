#include <Microduino_Key.h>

int state;
int KEY;
bool isAlert;
Key KeyA(4, INPUT_PULLUP);

void setup() {
  pinMode(4, INPUT);
  pinMode(8, INPUT);
  pinMode(6, OUTPUT);
  isAlert = false;
  Serial.begin(9600);
}

void loop() {
  if (KeyA.read() == SHORT_PRESS) {
    isAlert = !isAlert;
  }

  state = digitalRead(8);

  if (isAlert && state == 1) {
    for (int i = 800; i < 2000; i++)
    {
      tone(6, i);
      delay(3);
    }
  }
  Serial.print(state);
  delay(100);
}
