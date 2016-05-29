#ifndef ENCODER_H
#define ENCODER_H

#include<QObject>
#include<QTime>
#include<QMutex>
#include<QThread>
#include<QCoreApplication>
#include<wiringPi.h>
#include<string>
#include<iostream>


class Encoder : public QObject
{
    Q_OBJECT
public:
    Encoder(int pinEncoderA, int pinEncoderB);
    ~Encoder();

    float getSpeed();

    void startCount();
    void stopCount();
signals:
    void sgn_StartCounting();
public slots:
    void countTicks();
private:
    int m_iPinA;
    int m_iPinB;
    int m_iStatusPinA;
    int m_iStatusPinB;
    int m_iOldStatusPinA;
    int m_iOldStatusPinB;
    int m_iCurrentTicks;
    bool isStopped;

    QThread m_encoderThread;
    QMutex m_mutex;
    QTime m_qtPreviousTime;
};

#endif // ENCODER_H
