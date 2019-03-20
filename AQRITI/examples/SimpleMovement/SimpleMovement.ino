#include <AQRITI.h>
ROBOT myrobo;
void setup() {
  // motor pins
  myrobo.attach(13,12,11,10);
}

void loop() {
  // inputs are in milliseconds
  myrobo.move_forward(2000);
  myrobo.move_reverse(2000);
  myrobo.stop(2000);
}
