#ifndef KEPU
#define KEPU

#include<QDate>
#include<QString>

class KnjigaKEPU{
private:
    QDate datumKnjizenja;
    QString opisKnjizenja;
    double zaduzenje;
    double razduzenje;
    double upataNaRacun;
public:
    KnjigaKEPU();
    void dodajUnos(QString datum, QString opis, double zaduzenje, double razduzenje, double uplata);
    QDate getDatumKnjizenja();
    QString getOpisKnjizenja();
    double getZaduzenje();
    double getRazduzenje();
    double uplataNaRacun();
};

#endif // KEPU

