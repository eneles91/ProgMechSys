#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "encoder.h"
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <QObject>
#include <QTimer>
#include <QTime>
#include <QString>

/*!
 * \file dcmotor.h
 * \author closed suse
 * \date 9-Apr -2016
 * \brief Dcmotor class:
 * The class Dcmotor contains the information to run a dc motor including the
 * 3-pin-configuration and initialisation of pulse width modulation.
 * The initialisation takes place in the constructer of the class
*/
class Dcmotor : public QObject
{

    Q_OBJECT

public:

    /*! The constructer of the class "Dcmotor" contains information about the GPIO pins
     * wich are connected to the dc motor to run it
     * \brief Dcmotor::Dcmotor
     * \param [in] pinForward
     * \param [in] pinBackward
     * \param [in] pinSpeed
    */
    Dcmotor(int pinForward, int pinBackward, int pinSpeed, int encoderA, int EncoderB);
    ~Dcmotor();

    /*! Initialization of the pulse width moulation and all pins that are necessary to run the dc motor
     * \brief Dcmotor::initPins
     * \retval bool isPin
    */
    bool initPins();

    /*! Instance to set a new pwm value to control the speed of the dc motor
     * \brief Dcmotor::setPwm
     * \param pwmVal
    */
    void setPwm(int pwmVal);

    /*! Instance to rotate the dc motor counter clockwise
     * \brief Dcmotor::forward
    */
    void forward();

    /*! Instance to rotate the dc motor clockwise
     * \brief Dcmotor::backward
    */
    void backward();

    /*! Instance to stop both dc motors
     * \brief Dcmotor::stop
    */
    void stop();

    void setSpeed(double targetSpeed);

    double m_ftargetSpeed;

    QTimer* p_qt_display;

public slots:

    /*! Slot wrapper for Dcmotor::setPwm()
     * \brief Dcmotor::slot_setPwm
    */
    void slot_setPwm(int pwmVal);

    /*! Slot wrapper for Dcmotor::forward()
     * \brief Dcmotor::slot_forward
    */
    void slot_forward();

    /*! Slot wrapper for Dcmotor::backward()
     * \brief Dcmotor::slot_backward
    */
    void slot_backward();

    /*! Slot wrapper for Dcmotor::stop()
     * \brief Dcmotor::slot_stop
    */
    void slot_stop();

    void slot_pidController();

    void slot_getDisplayInformation();

    void slot_setPGain(double pGain);

    void slot_setIGain(double iGain);

    void slot_setDGain(double dGain);

signals:
    void sgnSpeed(double);
    void sgnErrorSpeed(double);

private:
    int m_ipinForward;
    int m_ipinBackward;
    int m_ipinSpeed;
    int m_ipinEncoderA;
    int m_ipinEncoderB;
    double m_fprevErrorSpeed;
    double m_fprevOutput;
    double m_fprevSpeed;
    double m_dPGain;
    double m_dIGain;
    double m_dDGain;
    double m_fPidIntegral;

    bool m_bIsStop;

    Encoder* m_pEncoder;

    QTimer* p_qtTimerPidController;

};

#endif // DCMOTOR_H
