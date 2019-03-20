#include <AQRITI.h>
LIGHTSENSOR mylight;
LED myled;

void setup() {
  mylight.attach(A5);
  myled.attach(3);
  mylight.set_threshold(512);
}

void loop() {
  if(mylight.is_light_on())
  {
    myled.off();
  }
  else
  {
    myled.on();
  }
}
