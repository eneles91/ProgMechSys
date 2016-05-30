#include "dcmotor.h"

#define PID_LOOP_RATE 10
#define DISPLAY_LOOP_RATE 200

Dcmotor::Dcmotor(int pinForward, int pinBackward, int pinSpeed, int pinEncoderA, int pinEncoderB)
{
    m_ipinBackward = pinBackward;
    m_ipinForward = pinForward;
    m_ipinSpeed = pinSpeed;
    m_ipinEncoderA = pinEncoderA;
    m_ipinEncoderB = pinEncoderB;
    m_fprevErrorSpeed = 0;

    initPins();

    m_pEncoder = new Encoder(m_ipinEncoderA, m_ipinEncoderB);
    m_pEncoder->startCount();

    p_qt_display = new QTimer();
    connect(p_qt_display, SIGNAL(timeout()), this, SLOT(slot_getDisplayInformation()));
    p_qt_display->start(DISPLAY_LOOP_RATE);

    p_qtTimerPidController = new QTimer();
    connect(p_qtTimerPidController, SIGNAL(timeout()), this, SLOT(slot_pidController()));
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
    int output_Pwm;
    double currentSpeed;
    double targetSpeed;
    double errorSpeed;
    double output;
    double deltaT;
    currentSpeed = m_pEncoder->getSpeed(&deltaT);
    targetSpeed = m_ftargetSpeed;
    errorSpeed = targetSpeed - currentSpeed;

    output = m_dPGain * errorSpeed + m_dIGain * deltaT * (errorSpeed) + m_dDGain / deltaT * (errorSpeed - m_fprevErrorSpeed);
    m_fprevErrorSpeed = errorSpeed;
    m_fprevSpeed = currentSpeed;
    output_Pwm = (int)output;
    setPwm(output_Pwm);

   // std::cout << currentSpeed << std::endl;
}

void Dcmotor::slot_showSpeed()
{
   double* p_deltaT;
   std::cout << m_pEncoder->getSpeed(p_deltaT) << std::endl;
}

void Dcmotor::setSpeed(double targetSpeed)
{
    m_ftargetSpeed = targetSpeed;
}

void Dcmotor::slot_getDisplayInformation()
{
    emit sgnSpeed(m_fprevSpeed);
    emit sgnErrorSpeed(m_fprevErrorSpeed);
}

void Dcmotor::slot_setPGain(double pGain)
{
    m_dPGain = pGain;
}

void Dcmotor::slot_setIGain(double iGain)
{
    m_dIGain = iGain;
}

void Dcmotor::slot_setDGain(double dGain)
{
    m_dDGain = dGain;
}
