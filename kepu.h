#ifndef KEPU
#define KEPU

#include<QString>

class KEPU{
private:
    QString datumKnjizenja;
    QString opisKnjizenja;
    double zaduzenje;
    double razduzenje;
    double upataNaRacun;
public:
    KEPU(QString datum, QString opis, double zaduzenje, double razduzenje, double uplata);

};

#endif // KEPU

