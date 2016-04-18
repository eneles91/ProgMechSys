#include <iostream>
#include "strings.h"
#include "dcmotor.h"

using namespace std;

int main()
{
    bool bFinish = false;
    char cInput;
    int pinForward = 25;
    int pinBackward = 23;
    int pinPwm = 24;
    Dcmotor motor1(pinForward, pinBackward, pinPwm);

    motor1.setPwm(50);

    while (!bFinish)
    {
        cout<< "Befehl eingeben: " << endl;
        cin >> cInput;
        if (cInput == 'F' || cInput == 'f')
        {
            motor1.forward();
        }
        else if (cInput == 'B' || cInput == 'b')
        {
            motor1.backward();
        }
        else if (cInput == 'S' || cInput == 's')
        {
            motor1.stopMotor();
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

