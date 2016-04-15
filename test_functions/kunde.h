#ifndef KUNDE_H
#define KUNDE_H
#include<string>

class kunde
{
  public:
    void geldkarte_einschieben();
    bool PIN_eingeben();
    bool betrag_waehlen();

  private:
    std::string Benutzername; 
    std::string PIN;
};
#endif // KUNDE_H
