#include <QuantBlackLine.h>

QuantBlackLine lineSensor;

void setup() {
  Serial.begin(9600);
  lineSensor.begin(500);  // Set threshold level to 500
}

void loop() {
  bool lineDetected = lineSensor.readLineSensorBool(0);
  Serial.println(lineDetected);
  delay(1000);
}
