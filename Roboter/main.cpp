#include <iostream>
#include "strings.h"
#include "dcmotor.h"
#include "linesensor.h"
#include <wiringPi.h>

using namespace std;

int main()
{
    wiringPiSetup();

    bool bFinish = false;
    char cInput;
    int pinForward1 = 25;
    int pinBackward1 = 23;
    int pinForward2 = 28;
    int pinBackward2 = 29;
    int pinPwm1 = 24;
    int pinPwm2 = 27;
    Dcmotor motor1(pinForward1, pinBackward1, pinPwm1);
    Dcmotor motor2(pinForward2, pinBackward2, pinPwm2);
    motor1.setPwm(50);
    motor2.setPwm(50);

    Linesensor sensorLeft(21);
    Linesensor sensorRight(22);



    while (!bFinish)
    {
        cout<< "Befehl eingeben: " << endl;
        cin >> cInput;



        if (cInput == 'F' || cInput == 'f')
        {
            motor1.forward();
            motor2.forward();
        }
        else if (cInput == 'B' || cInput == 'b')
        {
            motor1.backward();
            motor2.backward();
        }
        else if (cInput == 'S' || cInput == 's')
        {
            motor1.stopMotor();
            motor2.stopMotor();
            cout << sensorLeft.checkWhiteGround() << endl;
            cout << sensorRight.checkWhiteGround() << endl;
        }
        else if (cInput == 'Q' || cInput == 'q')
        {
            bFinish = true;
        }
        else
            cout << "Ungueltigen Eingabe" << endl;
    }

    return 0;
}

