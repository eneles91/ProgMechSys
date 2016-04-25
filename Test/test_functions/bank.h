#ifndef BANK_H
#define BANK_H

#include <string>

class bank
{
    public:
        void init(std::string Benutzername, std::string PIN, int Kontostand);
        bool zugriff_ueberpruefen(std::string benutzername, std::string pin);
        bool geld_abheben(int betrag);
        int Kontostand;

    private:
        std::string Benutzername;
        std::string PIN;

};
#endif // BANK_H
