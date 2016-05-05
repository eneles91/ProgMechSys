#ifndef LINESENSOR_H
#define LINESENSOR_H
#include <wiringPi.h>

/*
 * The class Linesensor contains functions to initialize a line sensor. The
 * initialisation of used GPIO pins takes place in the constructor of the class
*/
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
