#ifndef LINESENSOR_H
#define LINESENSOR_H
#include <wiringPi.h>

class Linesensor
{
public:
    Linesensor(int pinInput);
    bool initPins();
    int getStatus();


private:
    bool m_bwhiteGround;
    int m_ipinInput;
};

#endif // LINESENSOR_H
