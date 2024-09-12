#ifndef QUANT_BLACK_LINE_H
#define QUANT_BLACK_LINE_H

#include <Arduino.h>

class QuantBlackLine {
  public:
    void begin(int level);
    uint8_t readLineSensor(uint8_t channel);
    bool readLineSensorBool(uint8_t channel);

  private:
    const int S0 = 7;
    const int S1 = 8;
    const int S2 = A1;
    uint8_t level;
};

#endif
