#include "dcmotor.h"
#include "linesensor.h"
#include <iostream>

#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

class mobilePlatform
{
public:
    mobilePlatform();
    ~mobilePlatform();
private:
    Dcmotor *m_pMotorRight;
    Dcmotor *m_pMotorLeft;

    Linesensor *m_pLineSensorRight;
    Linesensor *m_pLineSensorLeft;


};

#endif // MOBILEPLATFORM_H
