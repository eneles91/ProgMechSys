#include <iostream>
#include "strings.h"
#include "kunde.h"
#include "bank.h"

using namespace std;

bank b;

void kunde::geldkarte_einschieben()
{
    cout << "Schieben Sie bitte ihre Karte ein: " << flush;
    cin >> Benutzername;
}

bool kunde::PIN_eingeben()
{
    cout << "Geben Sie ihren Pin ein: " << flush;
    cin >> PIN;
    return b.zugriff_ueberpruefen(Benutzername, PIN);
}

bool kunde::betrag_waehlen()
{
    int Betrag;
    cout << "Geben Sie dein Betrag ein: " << flush;
    cin >> Betrag;
    return b.geld_abheben(Betrag);
}
