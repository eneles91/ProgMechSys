#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>


class Dcmotor
{
public:
    Dcmotor(int pinForward, int pinBackward, int pinSpeed);

    void setPwm(int pwmVal);
    void moveForward();
    void moveBackward();
    void stopMotor();
    bool initPins();
private:
    int m_ipinForward;
    int m_ipinBackward;
    int m_ipinSpeed;
};

#endif // DCMOTOR_H
