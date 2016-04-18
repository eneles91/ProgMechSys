#include "dcmotor.h"

Dcmotor::Dcmotor(int pinMotorForward, int pinMotorDirection, int pinMotorSpeed)
{
    m_ipinMotorDirection = pinMotorDirection;
    m_ipinMotorForward = pinMotorForward;
    m_ipwm = 80;
    if(initPins())
    {

    }
}
bool Dcmotor::initPins()
{
    bool isPin = ((m_ipinMotorDirection <= 29 && m_ipinMotorDirection >=0) || (m_ipinMotorForward <= 29 && m_ipinMotorForward >=0) || (m_ipinMotorSpeed <= 29 && m_ipinMotorSpeed >=0));
    if (isPin == true)
    {
        pinMode(m_ipinMotorDirection, OUTPUT);
        pinMode();
    }
}
