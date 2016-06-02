#include "dcmotor.h"

#define PID_LOOP_RATE 100
//#define PID_LOOP_RATE 500
#define DISPLAY_LOOP_RATE 200

Dcmotor::Dcmotor(int pinForward, int pinBackward, int pinSpeed, int pinEncoderA, int pinEncoderB)
{
    m_bIsStop = false;
    m_ipinBackward = pinBackward;
    m_ipinForward = pinForward;
    m_ipinSpeed = pinSpeed;
    m_ipinEncoderA = pinEncoderA;
    m_ipinEncoderB = pinEncoderB;
    m_fprevErrorSpeed = 0;
    m_fprevSpeed = 0;
    m_fprevOutput = 0;
    m_fPidIntegral = 0;
    m_dPGain = 80;
    m_dIGain = 3;
    m_dDGain = 0;

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
    if(pwmVal>160)
    {
        pwmVal = 160;
    }
    else if(pwmVal < 0)
    {
        pwmVal = 0;
    }
    softPwmWrite(m_ipinSpeed, pwmVal);
}

void Dcmotor::forward()
{
    m_bIsStop = false;
    digitalWrite(m_ipinForward, 1);
    digitalWrite(m_ipinBackward, 0);
}

void Dcmotor::backward()
{
    m_bIsStop = false;
    digitalWrite(m_ipinForward, 0);
    digitalWrite(m_ipinBackward, 1);
}

void Dcmotor::stop()
{
    m_bIsStop = true;
    digitalWrite(m_ipinForward, 0);
    digitalWrite(m_ipinBackward, 0);
    m_fprevErrorSpeed = 0;
    m_fprevSpeed = 0;
    m_fprevOutput = 0;
    m_fPidIntegral = 0;
}

void Dcmotor::slot_setPwm(int pwmVal)
{
    if(pwmVal>255)
    {
        pwmVal = 255;
    }
    else if(pwmVal < 0)
    {
        pwmVal = 0;
    }
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
    if (!m_bIsStop)
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
        m_fPidIntegral = m_fPidIntegral + errorSpeed;

        output = m_fprevOutput + (m_dPGain * errorSpeed);// + m_dIGain * deltaT * m_fPidIntegral + m_dDGain / deltaT * (errorSpeed - m_fprevErrorSpeed));
        output_Pwm = (int)output;
        setPwm(output_Pwm);

        m_fprevErrorSpeed = errorSpeed;
        m_fprevOutput = output;
        m_fprevSpeed = currentSpeed;

        //std::cout << m_dPGain << std::endl;
    }
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
