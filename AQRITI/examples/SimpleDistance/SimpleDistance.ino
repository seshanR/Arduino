#include <AQRITI.h>
DISTANCESENSOR myRange;;

void setup() {
  // attach format trigger_pin, echo_pin
  Serial.begin(9600);
  myRange.attach(7,6);
}

void loop() {
  // Distance in centimetres
  Serial.println(myRange.find_distance());
}
