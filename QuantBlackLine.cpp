#include "QuantBlackLine.h"

void QuantBlackLine::begin(int level) {
  this->level = level;
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
  digitalWrite(S2, LOW);
}

uint8_t QuantBlackLine::readLineSensor(uint8_t channel) {
  if (channel >= 0 && channel <= 7) {
    digitalWrite(S0, 1 && (channel & B00000001));
    digitalWrite(S1, 1 && (channel & B00000010));
    digitalWrite(S2, 1 && (channel & B00000100));
    return analogRead(A0);
  }
  return 0;
}

bool QuantBlackLine::readLineSensorBool(uint8_t channel) {
  if (channel >= 0 && channel <= 7) {
    if (readLineSensor(channel) > level)
      return true;
    else
      return false;
  }
  return false;
}
