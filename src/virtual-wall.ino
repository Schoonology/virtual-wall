#include "Quantum.h"

bool enabled_pins[] = {0, 0};
int pins[] = {D0, D1};
Quantum wall(perform);

void perform(uint8_t command) {
  uint8_t front = (command & 0xf0) >> 4;
  uint8_t back = command & 0x0f;

  enabled_pins[0] = (front != 0);
  enabled_pins[1] = (back != 0);
  EEPROM.put(0, enabled_pins);
}

void setup() {
  pinMode(D0, OUTPUT);
  analogWriteResolution(D0, 8);
  pinMode(D1, OUTPUT);
  analogWriteResolution(D1, 8);

  EEPROM.get(0, enabled_pins);
  wall.begin();
}

void loop() {
  burst();
  burst();
  burst();
  delay(132);
}

void burst() {
  on();
  delayMicroseconds(500);
  off();
  delayMicroseconds(7500);
}

void on() {
  for (int idx = 0; idx < 4; ++idx) {
    if (enabled_pins[idx]) {
      analogWrite(pins[idx], 128, 38000);
    }
  }
}

void off() {
  for (int idx = 0; idx < 4; ++idx) {
    digitalWrite(pins[idx], LOW);
  }
}
