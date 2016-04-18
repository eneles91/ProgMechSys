#include "dcmotor.h"

Dcmotor::Dcmotor(int pinForward, int pinBackward, int pinSpeed)
{
    m_ipinBackward = pinMotorDirection;
    m_ipinBackward = pinMotorForward;
    m_ipinSpeed = pinSpeed;
    if(initPins())
    {

    }
}
bool Dcmotor::initPins()
{
    bool isPin = ((m_ipinMotorDirection <= 29 && m_ipinMotorDirection >=0) || (m_ipinMotorForward <= 29 && m_ipinMotorForward >=0) || (m_ipinMotorSpeed <= 29 && m_ipinMotorSpeed >=0));
    if (isPin == true)
    {
        pinMode(m_ipinBackward, OUTPUT);
        pinMode(m_ipinForward, OUTPUT);
        softPwmCreate(m_ipwm, 0, 255);
        return true;
    }
    else
        return false;
}
