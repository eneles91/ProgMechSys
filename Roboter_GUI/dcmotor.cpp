#include "dcmotor.h"

/*
 * The constructer of the class "Dcmotor" contains information about the GPIO pins
 * wich are connected to the dc motor to run it
 * @brief Dcmotor::Dcmotor
 * @param pinForward
 * @param pinBackward
 * @param pinSpeed
*/
Dcmotor::Dcmotor(int pinForward, int pinBackward, int pinSpeed)
{
    m_ipinBackward = pinBackward;
    m_ipinForward = pinForward;
    m_ipinSpeed = pinSpeed;
    initPins();
}

/*
 * Initializes the pulse width moulation and all pins that are necessary to run the dc motor
 * @brief Dcmotor::initPins
 * @return bool isPin
*/
bool Dcmotor::initPins()
{
    bool isPin = ((m_ipinBackward <= 31 && m_ipinBackward>=0) || (m_ipinForward <= 31 && m_ipinForward >=0) || (m_ipinSpeed <= 31 && m_ipinSpeed >=0));
    if (isPin == true)
    {

        pinMode(m_ipinBackward, OUTPUT);
        pinMode(m_ipinForward, OUTPUT);
        pinMode(m_ipinSpeed, PWM_OUTPUT);
        softPwmCreate(m_ipinSpeed, 0, 255);
        return true;
    }
    else
        return false;
}

/*
 * Instance to set a new pwm value to control the speed of the dc motor
 * @brief Dcmotor::setPwm
 * @param pwmVal
*/
void Dcmotor::setPwm(int pwmVal)
{
      softPwmWrite(m_ipinSpeed, pwmVal);
}

/*
 * Instance to rotate the dc motor counter clockwise
 * @brief Dcmotor::forward
*/
void Dcmotor::forward()
{
    digitalWrite(m_ipinForward, 1);
    digitalWrite(m_ipinBackward, 0);
}


/*
 * Instance to rotate the dc motor clockwise
 * @brief Dcmotor::backward
*/
void Dcmotor::backward()
{
    digitalWrite(m_ipinForward, 0);
    digitalWrite(m_ipinBackward, 1);
}


/*
 * Instance to stop both dc motors
 * @brief Dcmotor::stop
*/
void Dcmotor::stop()
{
    digitalWrite(m_ipinForward, 0);
    digitalWrite(m_ipinBackward, 0);
}
