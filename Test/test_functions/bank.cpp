#include "bank.h"


void bank::init(std::string benutzername, std::string pin, int kontostand)
{
  Benutzername = benutzername;
  PIN = pin;
  Kontostand = kontostand;
}

bool bank::zugriff_ueberpruefen(std::string benutzername, std::string pin)
{
  if (Benutzername == benutzername && PIN == pin)
  {
    return true;
  }

  return false;
}

bool bank::geld_abheben(int betrag)
{
  if (Kontostand >= betrag)
  {
    Kontostand -= betrag;
    return true;
  }

  return false;
}
