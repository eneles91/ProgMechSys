#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

#include "dcmotor.h"
#include "linesensor.h"
#include <iostream>
#include <QObject>
#include <QThread>
#include <QMutex>
#include <QCoreApplication>
#include <QTimer>

class MobilePlatform : public QObject
{
    Q_OBJECT

public:
    MobilePlatform();
    ~MobilePlatform();

    bool m_bendReached;

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

    void slot_followLine();
    void slot_endFollowLine();
    void slot_moveForward();
    void slot_moveBackward();
    void slot_moveRight();
    void slot_moveLeft();
    void slot_stopMotion();
    void slot_setSpeed(int speed);
signals:
private:
    QThread m_thread;
    QMutex m_mutex;
};

#endif // MOBILEPLATFORM_H
