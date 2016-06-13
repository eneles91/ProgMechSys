#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include<QObject>
#include<QTime>
#include<QMutex>
#include<QThread>
#include<QCoreApplication>
#include<wiringPi.h>


class Ultrasonic  : public QObject
{
    Q_OBJECT
public:
    Ultrasonic(int ioPin);
    ~Ultrasonic();
private:
    QThread  m_ultrasonicThread;
};

#endif // ULTRASONIC_H
