#ifndef MOBILEPLATFORM_H
#define MOBILEPLATFORM_H

#include <iostream>
#include <QObject>
#include <QThread>
#include <QTime>
#include <QTimer>
#include <QMutex>
#include <QCoreApplication>
#include "dcmotor.h"
#include "linesensor.h"

/*
 * The class MobilePlatform contains all functions and variables to connect
 * sensors and actuators of the platform
 * @brief MobilePlatform class
*/
class MobilePlatform : public QObject
{
    Q_OBJECT

public:
    MobilePlatform();
    ~MobilePlatform();

    bool m_bendReached;
    double m_iCircleRadius;
    double m_dCircleSpeed;

    Dcmotor *m_pMotorRight;
    Dcmotor *m_pMotorLeft;
    Linesensor *m_pLineSensorRight;
    Linesensor *m_pLineSensorLeft;

    void moveForward();
    void moveBackward();
    void moveRight();
    void moveLeft();
    void motionStop();
    void setSpeed(double speedSignal);
    void followLine();
    void endFollowLine();
    void drawCircle();

public slots:

    void slot_followLine();
    void slot_endFollowLine();
    void slot_moveForward();
    void slot_moveBackward();
    void slot_moveRight();
    void slot_moveLeft();
    void slot_stopMotion();
    void slot_setSpeed(double speed);
    void slot_setCircleSpeed(double circleSpeed);
    void slot_setCircleRadius(double circleRadius);
    void slot_drawCircle();

signals:
private:

    QTime m_qtPreviousTime;
    QThread m_thread;
    QMutex m_mutex;
};

#endif // MOBILEPLATFORM_H
