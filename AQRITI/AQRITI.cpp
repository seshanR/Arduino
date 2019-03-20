#include <Arduino.h>
#include <AQRITI.h>

ROBOT::ROBOT()
{
    this->motor_1_pin_1 = 11;
    this->motor_1_pin_2 = 12;
    this->motor_2_pin_1 = 10;
    this->motor_2_pin_2 = 13;
    pinMode(this->motor_1_pin_1, OUTPUT);
    pinMode(this->motor_1_pin_2, OUTPUT);
    pinMode(this->motor_2_pin_1, OUTPUT);
    pinMode(this->motor_2_pin_2, OUTPUT);
}

void ROBOT::attach(int m1p1, int m1p2, int m2p1, int m2p2)
{
    this->motor_1_pin_1 = m1p1;
    this->motor_1_pin_2 = m1p2;
    this->motor_2_pin_1 = m2p1;
    this->motor_2_pin_2 = m2p2;
    pinMode(this->motor_1_pin_1, OUTPUT);
    pinMode(this->motor_1_pin_2, OUTPUT);
    pinMode(this->motor_2_pin_1, OUTPUT);
    pinMode(this->motor_2_pin_2, OUTPUT);
}

void ROBOT::move_forward(int ms)
{
    digitalWrite(this->motor_1_pin_1, HIGH);
    digitalWrite(this->motor_1_pin_2, LOW);
    digitalWrite(this->motor_2_pin_1, HIGH);
    digitalWrite(this->motor_2_pin_2, LOW);
    delay(ms);
    if(ms)
    {
        this->stop(0);
    }
}

void ROBOT::move_reverse(int ms)
{
    digitalWrite(this->motor_1_pin_1, LOW);
    digitalWrite(this->motor_1_pin_2, HIGH);
    digitalWrite(this->motor_2_pin_1, LOW);
    digitalWrite(this->motor_2_pin_2, HIGH);
    delay(ms);
    if(ms)
    {
        this->stop(0);
    }
}

void ROBOT::turn_left(int ms)
{
    digitalWrite(this->motor_1_pin_1, HIGH);
    digitalWrite(this->motor_1_pin_2, LOW);
    digitalWrite(this->motor_2_pin_1, LOW);
    digitalWrite(this->motor_2_pin_2, LOW);
    delay(ms);
    if(ms)
    {
        this->stop(0);
    }
}

void ROBOT::sharp_left(int ms)
{
    digitalWrite(this->motor_1_pin_1, HIGH);
    digitalWrite(this->motor_1_pin_2, LOW);
    digitalWrite(this->motor_2_pin_1, LOW);
    digitalWrite(this->motor_2_pin_2, HIGH);
    delay(ms);
    if(ms)
    {
        this->stop(0);
    }
}

void ROBOT::turn_right(int ms)
{
    digitalWrite(this->motor_1_pin_1, LOW);
    digitalWrite(this->motor_1_pin_2, LOW);
    digitalWrite(this->motor_2_pin_1, HIGH);
    digitalWrite(this->motor_2_pin_2, LOW);
    delay(ms);
    if(ms)
    {
        this->stop(0);
    }
}

void ROBOT::sharp_right(int ms)
{
    digitalWrite(this->motor_1_pin_1, LOW);
    digitalWrite(this->motor_1_pin_2, HIGH);
    digitalWrite(this->motor_2_pin_1, HIGH);
    digitalWrite(this->motor_2_pin_2, LOW);
    delay(ms);
    if(ms)
    {
        this->stop(0);
    }
}

void ROBOT::stop(int ms)
{
    digitalWrite(this->motor_1_pin_1, LOW);
    digitalWrite(this->motor_1_pin_2, LOW);
    digitalWrite(this->motor_2_pin_1, LOW);
    digitalWrite(this->motor_2_pin_2, LOW);
    delay(ms);
}

ROBOT::~ROBOT()
{
}

LIGHTSENSOR::LIGHTSENSOR()
{
    this->light_threshold = 512;
}

LIGHTSENSOR::~LIGHTSENSOR()
{
}

void LIGHTSENSOR::attach(int lpin)
{
    this->light_pin = lpin;
}

void LIGHTSENSOR::set_threshold(int threshold)
{
    this->light_threshold = threshold;
}

bool LIGHTSENSOR::is_light_on()
{
    return (analogRead(this->light_pin) > this->light_threshold);
}

LED::LED()
{
}

LED::~LED()
{
}

void LED::attach(int lpin)
{
    this->led_pin = lpin;
    pinMode(this->led_pin, OUTPUT);
}

void LED::off()
{
    digitalWrite(this->led_pin, LOW);
}

void LED::on()
{
    digitalWrite(this->led_pin, HIGH);
}

void LED::blink(int ms)
{
    digitalWrite(this->led_pin, HIGH);
    delay(ms);
    digitalWrite(this->led_pin, LOW);
    delay(ms);
}

DISTANCESENSOR::DISTANCESENSOR()
{
}

DISTANCESENSOR::~DISTANCESENSOR()
{
}

void DISTANCESENSOR::attach(int tpin, int epin)
{
    this->trigger_pin = tpin;
    this->echo_pin = epin;
    pinMode(this->trigger_pin, OUTPUT);
    pinMode(this->echo_pin, INPUT);
}

int DISTANCESENSOR::find_distance()
{
  digitalWrite(this->trigger_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(this->trigger_pin, HIGH);
  delayMicroseconds(5);
  digitalWrite(this->trigger_pin, LOW);

  long microseconds = pulseIn(this->echo_pin, HIGH);
  // Distance in centimeters
  return microseconds / 29 / 2;
}
