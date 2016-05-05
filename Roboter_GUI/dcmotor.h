#ifndef DCMOTOR_H
#define DCMOTOR_H

#include <wiringPi.h>
#include <softPwm.h>
#include <QObject>


/*
 * The class Dcmotor contains the information to run a dc motor including the
 * 3-pin-configuration and initialisation of pulse width modulation.
 * The initialisation takes place in the constructer of the class
 * @brief Dcmotor class
*/
class Dcmotor : public QObject
{

    Q_OBJECT

public:
    Dcmotor(int pinForward, int pinBackward, int pinSpeed);    
    bool initPins();
public slots:
    void setPwm(int pwmVal);
    void forward();
    void backward();
    void stop();
signals:
private:
    int m_ipinForward;
    int m_ipinBackward;
    int m_ipinSpeed;
};

#endif // DCMOTOR_H
