#include <AQRITI.h>
ROBOT myrobo;
DISTANCESENSOR myRange;

//#define FORWARD  {m1.FW(); m2.BW();   }myrobo.move_forward();

#define FORWARD  myrobo.move_forward();
#define BACKWARD myrobo.move_reverse();
#define LEFT     myrobo.turn_left(1500);
#define RIGHT    myrobo.turn_right(1500);
#define STOP     myrobo.stop();

#define UTURN    myrobo.sharp_left(1500);

#define DISTANCE myRange.find_distance()

void setup() {
  myrobo.attach(11,10,12,13);
  myRange.attach(7,6);
}

void loop() 
{ 
//-----------------------------------------

   if(DISTANCE < 20){ UTURN    } 
   if(DISTANCE > 20){ FORWARD  }
   
//------------------------------------------
}
