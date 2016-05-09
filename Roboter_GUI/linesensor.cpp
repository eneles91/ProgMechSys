#include "linesensor.h"
#include <iostream>


Linesensor::Linesensor(int pinInput)
{
    m_ipinInput= pinInput;                  /*!<pin number of the sensor input signal */
    initPins();
    pullUpDnControl(m_ipinInput, PUD_DOWN); /*!<Activates the pulldown resistor on the inputpin  */
}


bool Linesensor::initPins()
{
    bool isPin = (m_ipinInput <= 31);       /*!<pin muber gets checked wheather it is in range of wiring pi library */
    if (isPin == true)
    {
        pinMode(m_ipinInput, INPUT);        /*!<pin is defined as input pin */
        return true;
    }
    else
    {
        return false;
    }
}


bool Linesensor::getStatus(){
    bool checkGround=digitalRead(m_ipinInput);

    return checkGround;
}
