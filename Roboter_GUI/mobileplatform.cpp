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

MobilePlatform::MobilePlatform()
{
    m_pMotorRight = new Dcmotor(MOTOR_RIGHT_FORWARD, MOTOR_RIGHT_BACKWARD, MOTOR_RIGHT_PWM);
    m_pMotorLeft = new Dcmotor(MOTOR_LEFT_FORWARD, MOTOR_LEFT_BACKWARD, MOTOR_LEFT_PWM);

    m_pLineSensorRight = new Linesensor(LINESENSOR_RIGHT);
    m_pLineSensorLeft = new Linesensor(LINESENSOR_LEFT);
}

MobilePlatform::~MobilePlatform()
{
    delete m_pMotorRight;
    delete m_pMotorLeft;
    delete m_pLineSensorRight;
    delete m_pLineSensorLeft;
}

void MobilePlatform::moveForward()
{
    std::cout << "Move Forward" << std::endl;
    m_pMotorRight->forward();
    m_pMotorLeft->forward();
}

void MobilePlatform::moveBackward()
{
    std::cout << "Move Backward" << std::endl;
    m_pMotorRight->backward();
    m_pMotorLeft->backward();
}

void MobilePlatform::moveRight()
{
    std::cout << "Move Right" << std::endl;
    m_pMotorLeft->forward();
    m_pMotorRight->stop();
}

void MobilePlatform::moveLeft()
{
    std::cout << "Move Left" << std::endl;
    m_pMotorRight->forward();
    m_pMotorLeft->stop();
}

void MobilePlatform::motionStop()
{
    std::cout << "Stop Motion" << std::endl;
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
