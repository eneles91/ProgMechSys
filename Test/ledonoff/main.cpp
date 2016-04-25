#include <iostream>
#include <wiringPi.h>

using namespace std;


bool on;
bool cancel = false;
int led=8;
char cInput;
void ledStatus(char status);

int main()
{
    wiringPiSetup();
    pinMode(led, OUTPUT);

    while (!cancel)
    {
        cout << "Eingabe: " << endl;
        cin >>  cInput;
        if (cInput== 'Q' || cInput == 'q')
        {
            cancel=true;
        }
        ledStatus(cInput);
    }
    return 0;
}

void ledStatus(char status)
{
    if(status == 'o' || status == 'O')
    {
        digitalWrite(led, true);
    }
    else if((status == 's' || status == 'S'))
    {
        digitalWrite(led, false);
    }
}

