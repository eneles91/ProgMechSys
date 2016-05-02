#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

#include "dcmotor.h"
#include "linesensor.h"
#include <iostream>
#include <QObject>

class MobilePlatform : public QObject
{
    Q_OBJECT

public:
    MobilePlatform();
    ~MobilePlatform();

    Dcmotor *m_pMotorRight;
    Dcmotor *m_pMotorLeft;

    Linesensor *m_pLineSensorRight;
    Linesensor *m_pLineSensorLeft;

    void moveForward();
    void moveBackward();
    void moveRight();
    void moveLeft();
    void motionStop();
    void setSpeed(int pwmSignal);
public slots:
    void slot_moveForward();
    void slot_moveBackward();
    void slot_moveRight();
    void slot_moveLeft();
    void slot_stopMotion();
    void slot_setSpeed(int speed);
signals:
private:
};

#endif // MOBILEPLATFORM_H
