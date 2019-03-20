#include <AQRITI.h>
LIGHTSENSOR mylight;

void setup() {
  Serial.begin(9600);
  mylight.attach(A5);
  mylight.set_threshold(512);
}

void loop() {
  Serial.println(mylight.is_light_on());
}
