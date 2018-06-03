/*
 * Project virtual-wall
 * Description:
 * Author:
 * Date:
 */
bool enabled_pins[] = {0, 0, 0, 0};
int pins[] = {D0, D1, D2, D3};

int enable(String args) {
  int pin = args.toInt();

  if (pin < 0 || pin > 3) {
    return -1;
  }

  enabled_pins[pin] = true;
  EEPROM.put(0, enabled_pins);
  return 0;
}

int disable(String args) {
  int pin = args.toInt();

  if (pin < 0 || pin > 3) {
    return -1;
  }

  enabled_pins[pin] = false;
  EEPROM.put(0, enabled_pins);
  return 0;
}

void setup() {
  pinMode(D0, OUTPUT);
  analogWriteResolution(D0, 8);
  pinMode(D1, OUTPUT);
  analogWriteResolution(D1, 8);

  Particle.function("enable", enable);
  Particle.function("disable", disable);
  EEPROM.get(0, enabled_pins);
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
