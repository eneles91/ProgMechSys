#include "ultrasonic.h"
#include <iostream>

Ultrasonic::Ultrasonic(int ioPin)
{
    moveToThread(&m_ultrasonicThread);
    m_ultrasonicThread.start();
}

Ultrasonic::~Ultrasonic()
{
    if(m_ultrasonicThread.isRunning())
    {
        m_ultrasonicThread.terminate();
        m_ultrasonicThread.wait();
    }
}

