#include "dcmotor.h"
#include "linesensor.h"
#include <iostream>

#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

class mobilePlatform : public QObject
{
    Q_OBJECT

public:
    mobilePlatform();
    ~mobilePlatform();

    Dcmotor *m_pMotorRight;
    Dcmotor *m_pMotorLeft;

    Linesensor *m_pLineSensorRight;
    Linesensor *m_pLineSensorLeft;
private:



};

#endif // MOBILEPLATFORM_H
