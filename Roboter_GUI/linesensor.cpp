#include "linesensor.h"
#include <iostream>



Linesensor::Linesensor(int pinInput)
{
    m_ipinInput= pinInput;
    initPins();
    //std::cout << initPins() << std::endl;
}

bool Linesensor::initPins()
{
    bool isPin = (m_ipinInput <= 31);
    if (isPin == true)
    {
    std::cout << "klappt" << std::endl;
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
