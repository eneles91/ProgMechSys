#include "encoder.h"

#define PI 3.1416

Encoder::Encoder(int pinEncoderA, int pinEncoderB)
{
    m_iPinA = pinEncoderA;
    m_iPinB = pinEncoderB;

    pinMode(m_iPinA, INPUT);
    pinMode(m_iPinB, INPUT);

    m_iStatusPinA = 0;
    m_iStatusPinB = 0;
    m_iOldStatusPinA = 0;
    m_iOldStatusPinB = 0;
    m_iCurrentTicks = 0;

    moveToThread(&m_encoderThread);
    connect(this, SIGNAL(sgn_StartCounting()), this, SLOT(countTicks()));
    m_encoderThread.start();
}

Encoder::~Encoder()
{
    if(m_encoderThread.isRunning())
    {
        m_encoderThread.terminate();
        m_encoderThread.wait();
    }
}

void Encoder::startCount()
{
    m_mutex.lock();
    m_iCurrentTicks = 0;
    m_qtPreviousTime = QTime::currentTime();
    isStopped = false;
    m_mutex.unlock();
    emit sgn_StartCounting();
}

void Encoder::stopCount()
{
    m_mutex.lock();
    isStopped = true;
    m_mutex.unlock();
}

float Encoder::getSpeed(double* p_deltaT)
{
    m_mutex.lock();
    float deltaT = m_qtPreviousTime.msecsTo(QTime::currentTime());
    int ticks = m_iCurrentTicks;
    m_qtPreviousTime = QTime::currentTime();
    m_iCurrentTicks  = 0;
    m_mutex.unlock();

    *p_deltaT = (float)deltaT/1000;
    //std::cout << "" << std::endl;

    float currentSpeed = (ticks * 0.063 * PI * 1000) / (1440 * deltaT);
    return currentSpeed;
}


void Encoder::countTicks()
{
    while(!isStopped)
    {
        m_iStatusPinA = digitalRead(m_iPinA);
        m_iStatusPinB = digitalRead(m_iPinB);

        if(m_iStatusPinA != m_iOldStatusPinA)
        {
            m_mutex.lock();
            m_iCurrentTicks++;
            m_iOldStatusPinA = m_iStatusPinA;
            m_mutex.unlock();
        }
        if (m_iStatusPinB != m_iOldStatusPinB)
        {
            m_mutex.lock();
            m_iCurrentTicks++;
            m_iOldStatusPinB = m_iStatusPinB;
            m_mutex.unlock();
        }
    }
}
