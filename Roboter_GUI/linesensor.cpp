#include "linesensor.h"
#include <iostream>


/*
 * The constructer of the class "LineSensor" contains information about the GPIO pin
 * wich is connected to the Sensor to run it
 * @brief Linesensor::Linesensor
 * @param pinInput
*/
Linesensor::Linesensor(int pinInput)
{
    m_ipinInput= pinInput;
    initPins();
    pullUpDnControl(m_ipinInput, PUD_DOWN);
}

/*
 * Initializes the pin that is necessary to run the line sensor
 * @brief Dcmotor::initPins
 * @return bool isPin
*/
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

/*
 * This function returns the status of the GPIO pin weather the platform
 * is located on light or dark ground
 * @brief Linesensor::getStatus
 * @return int checkGround
*/
int Linesensor::getStatus(){
    int checkGround=digitalRead(m_ipinInput);

    return checkGround;
}
