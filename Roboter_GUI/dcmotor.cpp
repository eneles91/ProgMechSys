#include "dcmotor.h"

#define PID_LOOP_RATE 1000

#define PID_P_GAIN 1
#define PID_I_GAIN 0
#define PID_D_GAIN 0

Dcmotor::Dcmotor(int pinForward, int pinBackward, int pinSpeed, int pinEncoderA, int pinEncoderB)
{
    m_ipinBackward = pinBackward;
    m_ipinForward = pinForward;
    m_ipinSpeed = pinSpeed;
    m_ipinEncoderA = pinEncoderA;
    m_ipinEncoderB = pinEncoderB;

    initPins();

    m_pEncoder = new Encoder(m_ipinEncoderA, m_ipinEncoderB);
    m_pEncoder->startCount();

    p_qtTimerPidController = new QTimer();
    connect(p_qtTimerPidController, SIGNAL(timeout()), this, SLOT(slot_showSpeed()));
    p_qtTimerPidController->start(PID_LOOP_RATE);
}

Dcmotor::~Dcmotor()
{
    stop();
    delete m_pEncoder;
    delete p_qtTimerPidController;
}

bool Dcmotor::initPins()
{
    bool isPin = ((m_ipinBackward <= 31 && m_ipinBackward>=0) || (m_ipinForward <= 31 && m_ipinForward >=0) || (m_ipinSpeed <= 31 && m_ipinSpeed >=0));
    if (isPin == true)
    {
        pinMode(m_ipinBackward, OUTPUT);
        pinMode(m_ipinForward, OUTPUT);
        pinMode(m_ipinSpeed, PWM_OUTPUT);
        softPwmCreate(m_ipinSpeed, 0, 255);
        return true;
    }
    else
        return false;
}

void Dcmotor::setPwm(int pwmVal)
{
      softPwmWrite(m_ipinSpeed, pwmVal);
}

void Dcmotor::forward()
{
    digitalWrite(m_ipinForward, 1);
    digitalWrite(m_ipinBackward, 0);
}

void Dcmotor::backward()
{
    digitalWrite(m_ipinForward, 0);
    digitalWrite(m_ipinBackward, 1);
}

void Dcmotor::stop()
{
    digitalWrite(m_ipinForward, 0);
    digitalWrite(m_ipinBackward, 0);
}

void Dcmotor::slot_setPwm(int pwmVal)
{
    setPwm(pwmVal);
}

void Dcmotor::slot_forward()
{
    forward();
}

void Dcmotor::slot_backward()
{
    backward();
}

void Dcmotor::slot_stop()
{
    stop();
}

void Dcmotor::slot_pidController()
{

}

void Dcmotor::slot_showSpeed()
{
    //float* p_deltaT;
    std::cout << m_pEncoder->getSpeed() << std::endl;
}
