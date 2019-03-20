// AUTHOR : SESHAN RAJENDRAN

#ifndef AQRITI_H
#define AQRITI_H

#include <Arduino.h>

class ROBOT
{
private:
    int motor_1_pin_1;
    int motor_1_pin_2;
    int motor_2_pin_1;
    int motor_2_pin_2;

public:
    ROBOT();
    ~ROBOT();
    void attach(int m1p1, int m1p2, int m2p1, int m2p2);
    void move_forward(int ms = 0);
    void move_reverse(int ms = 0);
    void turn_left(int ms = 0);
    void turn_right(int ms = 0);
    void sharp_left(int ms = 0);
    void sharp_right(int ms = 0);
    void stop(int ms = 0);
};

class LIGHTSENSOR
{
private:
    int light_pin;
    int light_threshold;

public:
    LIGHTSENSOR();
    ~LIGHTSENSOR();
    void attach(int lpin);
    void set_threshold(int threshold);
    bool is_light_on();
};

class LED
{
private:
    int led_pin;
public:
    LED();
    ~LED();
    void attach(int lpin);
    void on();
    void off();
    void blink(int ms);
};

class DISTANCESENSOR
{
private:
    int trigger_pin;
    int echo_pin;
public:
    DISTANCESENSOR();
    ~DISTANCESENSOR();
    void attach(int tpin, int epin);
    int find_distance();
};

#endif // AQRITI_H
