#include "mobileplatform.h"

//Konstanten
#define PI 3.1416
//Pinbelegungen
#define MOTOR_RIGHT_FORWARD     28
#define MOTOR_RIGHT_BACKWARD    29
#define MOTOR_RIGHT_PWM          27

#define ENCODER_RIGHT_A         16
#define ENCODER_RIGHT_B         15

#define MOTOR_LEFT_FORWARD      25
#define MOTOR_LEFT_BACKWARD     23
#define MOTOR_LEFT_PWM          24

#define ENCODER_LEFT_A          5
#define ENCODER_LEFT_B          4

#define LINESENSOR_RIGHT        22
#define LINESENSOR_LEFT         21

/*
 * Constructor of the class MobilePlatform
 * @brief MobilePlatform::MobilePlatform
*/
MobilePlatform::MobilePlatform()
{
    m_iCircleRadius = 17;
    m_dCircleSpeed = 0.3;

    //Initialize and start thread for the class MobilePlatform
    moveToThread(&m_thread);
    m_thread.start();

    //Create two objects of the type Dcmotor
    m_pMotorLeft = new Dcmotor(MOTOR_LEFT_FORWARD, MOTOR_LEFT_BACKWARD, MOTOR_LEFT_PWM, ENCODER_LEFT_A, ENCODER_LEFT_B);
    m_pMotorRight = new Dcmotor(MOTOR_RIGHT_FORWARD, MOTOR_RIGHT_BACKWARD, MOTOR_RIGHT_PWM, ENCODER_RIGHT_A, ENCODER_RIGHT_B);


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
void MobilePlatform::setSpeed(double speedSignal)
{
        m_pMotorRight->setSpeed(speedSignal);
        m_pMotorLeft->setSpeed(speedSignal);
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

 * Function to let the platform draw a circle clockwise with a set speed and radius
 * The distance from one wheel center to the other measures 11cm
 * @brief MobilePlatform::endFollowLine()
*/
void MobilePlatform::drawCircle()
{   

    double speedLeftEngine;
    double speedRightEngine;

    //Stop both Motors
    m_pMotorLeft->stop();
    m_pMotorRight->stop();

    //Get current time
    m_qtPreviousTime = QTime::currentTime();

    m_iCircleRadius = sqrt(pow(m_iCircleRadius, 2)- pow(12, 2));

    speedLeftEngine=m_dCircleSpeed*((m_iCircleRadius+5.5)/m_iCircleRadius);
    speedRightEngine=m_dCircleSpeed*((m_iCircleRadius-5.5)/m_iCircleRadius);

    std::cout << "==============================" << std::endl;
    std::cout << "Speed left: " << speedLeftEngine << std::endl;
    std::cout << "Speed right: " << speedRightEngine << std::endl;
    std::cout << "==============================" << std::endl;

    m_pMotorLeft->setSpeed(speedLeftEngine);
    m_pMotorRight->setSpeed(speedRightEngine);
    m_pMotorLeft->forward();
    m_pMotorRight->forward();

    m_bendReached = true;
    //m_qtPreviousTime.msecsTo(QTime::currentTime())) < (2*PI*m_iCircleRadius/m_dCircleSpeed*10) &&
    while(m_bendReached)
    {
        //Wait until circle is finished
        QCoreApplication::processEvents();
    }
    m_pMotorLeft->stop();
    m_pMotorRight->stop();
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
    m_mutex.lock();
	m_iCircleRadius = 0;	
    m_bendReached = false;
    motionStop();
    m_mutex.unlock();
}

/*
 * Slot wrapper for MobilePlatform::setSpeed()
 * @brief MobilePlatform::slot_setSpeed()
*/
void MobilePlatform::slot_setSpeed(double speed)
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

void MobilePlatform::slot_setCircleSpeed(double circleSpeed)
{
    m_dCircleSpeed = circleSpeed;
}

void MobilePlatform::slot_setCircleRadius(double circleRadius)
{
    m_iCircleRadius = circleRadius;
}

void MobilePlatform::slot_drawCircle()
{
    drawCircle();
}
