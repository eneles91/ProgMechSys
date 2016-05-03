#include "linesensor.h"
#include <iostream>



Linesensor::Linesensor(int pinInput)
{
    m_ipinInput= pinInput;
    initPins();
    pullUpDnControl(m_ipinInput, PUD_DOWN);
}

bool Linesensor::initPins()
{
    bool isPin = (m_ipinInput <= 31);
    if (isPin == true)
    {
        pinMode(m_ipinInput, INPUT);
        return true;
    }
    else
    {
        return false;
    }
}

int Linesensor::getStatus(){
    int checkGround=digitalRead(m_ipinInput);

    return checkGround;
}
