#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <wiringPi.h>
#include <softPwm.h>


class Dcmotor
{
public:
    Dcmotor(int pinMotorForward, int pinMotorDirection, int pinMotorSpeed);
    bool initPins();
    void forward();
    void backward();
    void Speed();
    void stopMotor();
private:
    int m_ipinMotorForward;
    int m_ipinMotorDirection;
    int m_ipinMotorSpeed;
    int m_ipwm;
};

#endif // DCMOTOR_H
