#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <wiringPi.h>
#include <softPwm.h>


class Dcmotor
{
public:
    Dcmotor(int pinForward, int pinBackward, int pinSpeed);

    void setPwm(int pwmVal);
    bool initPins();
    void forward();
    void backward();
    void Speed();
    void stopMotor();
private:
    int m_ipinForward;
    int m_ipinBackward;
    int m_ipinSpeed;
};

#endif // DCMOTOR_H
