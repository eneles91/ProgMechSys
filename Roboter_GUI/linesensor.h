#ifndef LINESENSOR_H
#define LINESENSOR_H
#include <wiringPi.h>

/*!
 * \file linesensor.h
 * \author Team: Closed Suse
 * \date 9.05.2016
 * \brief The class Linesensor contains functions to initialize a line sensor. The
 * initialisation of used GPIO pins takes place in the constructor of the class
 *
 * \section Modifications
 * none
*/

class Linesensor
{
public:
    Linesensor(int pinInput);

    /*! Checks weather the pin number is valid for initialization
    * Semantic: Method is needed once before object is initialized
    *
    * \retval bool isPin
    */
    bool initPins();

    /*! Delivers sensor value. Equals true when sensor above light surface and false when sensor above dark surface
    * Semantic: Method is needed frequently to read sensor value --> for example: followingLine method
    *
    * \retval bool checkGround
    *
    */
    bool getStatus();


private:
    bool m_bwhiteGround;
    int m_ipinInput;
};

#endif // LINESENSOR_H
