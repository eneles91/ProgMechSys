#include "mobileplatform.h"

//Constants motor right side
#define MOTOR_RIGHT_FORWARD     28
#define MOTOR_RIGHT_BACKWARD    29
#define MOTOR_RIGHT_PWM          27
//Constants motor left side
#define MOTOR_LEFT_FORWARD      25
#define MOTOR_LEFT_BACKWARD     23
#define MOTOR_LEFT_PWM          24
//Constants linesensor right side
#define LINESENSOR_RIGHT        22
//Constants linesensor left side
#define LINESENSOR_LEFT         21

//Konstruktor
MobilePlatform::MobilePlatform()
{
    moveToThread(&m_thread);
    m_thread.start();

    m_pMotorRight = new Dcmotor(MOTOR_RIGHT_FORWARD, MOTOR_RIGHT_BACKWARD, MOTOR_RIGHT_PWM);
    m_pMotorLeft = new Dcmotor(MOTOR_LEFT_FORWARD, MOTOR_LEFT_BACKWARD, MOTOR_LEFT_PWM);

    m_pLineSensorRight = new Linesensor(LINESENSOR_RIGHT);
    m_pLineSensorLeft = new Linesensor(LINESENSOR_LEFT);

    motionStop();
}

//Destruktor
MobilePlatform::~MobilePlatform()
{
    if(m_thread.isRunning()){
        m_thread.terminate();
        m_thread.wait();
    }

    delete m_pMotorRight;
    delete m_pMotorLeft;
    delete m_pLineSensorRight;
    delete m_pLineSensorLeft;
}

void MobilePlatform::moveForward()
{
    m_pMotorRight->forward();
    m_pMotorLeft->forward();
}

void MobilePlatform::moveBackward()
{
    m_pMotorRight->backward();
    m_pMotorLeft->backward();
}

void MobilePlatform::moveRight()
{
    m_pMotorLeft->forward();
    m_pMotorRight->stop();
}

void MobilePlatform::moveLeft()
{
    m_pMotorRight->forward();
    m_pMotorLeft->stop();
}

void MobilePlatform::motionStop()
{
    m_pMotorRight->stop();
    m_pMotorLeft->stop();
}

void MobilePlatform::setSpeed(int pwmSignal)
{
    m_pMotorRight->setPwm(pwmSignal);
    m_pMotorLeft->setPwm(pwmSignal);
}

void MobilePlatform::slot_moveForward()
{
    moveForward();
}

void MobilePlatform::slot_moveBackward()
{
    moveBackward();
}

void MobilePlatform::slot_moveRight()
{
    moveRight();
}

void MobilePlatform::slot_moveLeft()
{
    moveLeft();
}

void MobilePlatform::slot_stopMotion()
{
    motionStop();
}

void MobilePlatform::slot_setSpeed(int speed)
{
    if (speed>=0 && speed <= 255)
    {
        m_pMotorRight->setPwm(speed);
        m_pMotorLeft->setPwm(speed);
    }
}

void MobilePlatform :: slot_followLine()
{
    m_bendReached = true;

    while(m_bendReached)
    {
        //Forward motion
        if((m_pLineSensorLeft->getStatus())&&(m_pLineSensorRight->getStatus()))
        {
            moveForward();
        }
        //Left Motion:
        if((!m_pLineSensorLeft->getStatus())&&(m_pLineSensorRight->getStatus()))
        {
            moveLeft();
        }
        //Right motion:
        if((m_pLineSensorLeft->getStatus())&&(!m_pLineSensorRight->getStatus()))
        {
            moveRight();
        }


        QCoreApplication::processEvents();
     }
}

void MobilePlatform::slot_endFollowLine()
{
    m_mutex.lock();
    m_bendReached = false;
    m_mutex.unlock();
}

