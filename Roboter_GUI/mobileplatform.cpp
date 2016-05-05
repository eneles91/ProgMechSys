#include "mobileplatform.h"

//Pinbelegungen
#define MOTOR_RIGHT_FORWARD     28
#define MOTOR_RIGHT_BACKWARD    29
#define MOTOR_RIGHT_PWM          27

#define MOTOR_LEFT_FORWARD      25
#define MOTOR_LEFT_BACKWARD     23
#define MOTOR_LEFT_PWM          24

#define LINESENSOR_RIGHT        22
#define LINESENSOR_LEFT         21

/*
 * Constructor of the class MobilePlatform
 * @brief MobilePlatform::MobilePlatform
*/
MobilePlatform::MobilePlatform()
{
    //Initialize and start thread for the class MobilePlatform
    moveToThread(&m_thread);
    m_thread.start();

    //Create two objects of the type Dcmotor
    m_pMotorRight = new Dcmotor(MOTOR_RIGHT_FORWARD, MOTOR_RIGHT_BACKWARD, MOTOR_RIGHT_PWM);
    m_pMotorLeft = new Dcmotor(MOTOR_LEFT_FORWARD, MOTOR_LEFT_BACKWARD, MOTOR_LEFT_PWM);

    //Create two objects of the type Linesensor
    m_pLineSensorRight = new Linesensor(LINESENSOR_RIGHT);
    m_pLineSensorLeft = new Linesensor(LINESENSOR_LEFT);

    //Stop both dc motors
    motionStop();
}

/*
 * Destructor of the class MobilePlatform
 * @brief MobilePlatform::~MobilePlatform
*/
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

/*
 * Function to make the platform drive forward
 * @brief MobilePlatform::moveForward()
*/
void MobilePlatform::moveForward()
{
    m_pMotorRight->forward();
    m_pMotorLeft->forward();
}

/*
 * Function to make the platform drive backward
 * @brief MobilePlatform::moveBackward()
*/
void MobilePlatform::moveBackward()
{
    m_pMotorRight->backward();
    m_pMotorLeft->backward();
}

/*
 * Function to make the platform move right
 * @brief MobilePlatform::moveRight()
*/
void MobilePlatform::moveRight()
{
    m_pMotorLeft->forward();
    m_pMotorRight->stop();
}

/*
 * Function to make the platform move left
 * @brief MobilePlatform::moveLeft()
*/
void MobilePlatform::moveLeft()
{
    m_pMotorRight->forward();
    m_pMotorLeft->stop();
}

/*
 * Function to make the platform stop
 * @brief MobilePlatform::motionStop()
*/
void MobilePlatform::motionStop()
{
    m_pMotorRight->stop();
    m_pMotorLeft->stop();
}

/*
 * Function to set the platforms speed to a pwm value to 0 - 255
 * @brief MobilePlatform::setSpeed()
*/
void MobilePlatform::setSpeed(int pwmSignal)
{
    if (pwmSignal>=0 && pwmSignal <= 255)
    {
        m_pMotorRight->setPwm(pwmSignal);
        m_pMotorLeft->setPwm(pwmSignal);
    }
}

/*
 * Function to let the platform follow a white line on the Ground
 * @brief MobilePlatform::followLine()
*/
void MobilePlatform::followLine()
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

/*
 * Function to let the platform stop follow a white line on the Ground
 * @brief MobilePlatform::endFollowLine()
*/
void MobilePlatform::endFollowLine()
{
    m_mutex.lock();
    m_bendReached = false;
    m_mutex.unlock();
}

/*
 * Slot wrapper for MobilePlatform::moveForward()
 * @brief MobilePlatform::slot_moveForward()
*/
void MobilePlatform::slot_moveForward()
{
    moveForward();
}

/*
 * Slot wrapper for MobilePlatform::moveBackward()
 * @brief MobilePlatform::slot_moveBackward()
*/
void MobilePlatform::slot_moveBackward()
{
    moveBackward();
}

/*
 * Slot wrapper for MobilePlatform::moveRight()
 * @brief MobilePlatform::slot_moveRight()
*/
void MobilePlatform::slot_moveRight()
{
    moveRight();
}

/*
 * Slot wrapper for MobilePlatform::moveLeft()
 * @brief MobilePlatform::slot_moveLeft()
*/
void MobilePlatform::slot_moveLeft()
{
    moveLeft();
}

/*
 * Slot wrapper for MobilePlatform::motionStop()
 * @brief MobilePlatform::slot_stopMotion()
*/
void MobilePlatform::slot_stopMotion()
{
    motionStop();
}

/*
 * Slot wrapper for MobilePlatform::setSpeed()
 * @brief MobilePlatform::slot_setSpeed()
*/
void MobilePlatform::slot_setSpeed(int speed)
{
    setSpeed(speed);
}

/*
 * Slot wrapper for MobilePlatform::followLine()
 * @brief MobilePlatform::slot_followLine()
*/
void MobilePlatform :: slot_followLine()
{
    followLine();
}

/*
 * Slot wrapper for MobilePlatform::endFollowLine()
 * @brief MobilePlatform::slot_endFollowLine()
*/
void MobilePlatform::slot_endFollowLine()
{
    endFollowLine();
}

