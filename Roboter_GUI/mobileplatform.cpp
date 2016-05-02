#include "mobileplatform.h"
#include <QObject>



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



mobilePlatform::mobilePlatform()
{
    m_pMotorRight = new Dcmotor(MOTOR_RIGHT_FORWARD, MOTOR_RIGHT_BACKWARD, MOTOR_RIGHT_PWM);
    m_pMotorLeft = new Dcmotor(MOTOR_LEFT_FORWARD, MOTOR_LEFT_BACKWARD, MOTOR_LEFT_PWM);

    m_pLineSensorRight = new Linesensor(LINESENSOR_RIGHT);
    m_pLineSensorLeft = new Linesensor(LINESENSOR_LEFT);

}

mobilePlatform::~mobilePlatform()
{
    delete m_pMotorRight;
    delete m_pMotorLeft;
    delete m_pLineSensorRight;
    delete m_pLineSensorLeft;
}

