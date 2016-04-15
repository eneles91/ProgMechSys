#include <iostream>
#include "strings.h"
#include "kunde.h"
#include "bank.h"

using namespace std;

extern bank b;


int main()
{
    kunde k;

    b.init("nils", "1991", 3000);

    for (;;)
    {
        k.geldkarte_einschieben();

        if (k.PIN_eingeben() == true)
        {
            if (k.betrag_waehlen() == true)
            {
                cout << "Der gewuenschte Betrag wurde abgehoben." << endl;
                cout << "Der neue Betrag ist: " << b.Kontostand << endl;
            }
        }
        else
        {
            cout << "Der PIN ist falsch!" << endl;
        }
    }

    return 0;
}

