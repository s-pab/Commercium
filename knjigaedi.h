#ifndef KNJIGAEDI
#define KNJIGAEDI

#include<QDate>
#include<QString>

class KnjigaEDI{
private:
    QDate datumFormiranja;
    unsigned int brojIzvestaja;
    int brojIspravki;
    int brojFiskalnihRacuna;
    int brojRacunaZaBezgotovinsko;
public:
    KnjigaEDI();
    void dodajUnos(QDate datum, int brojIzvestaja,int brojIspravki,int brojFiskalnihRacuna,int brojRacunaZaBezgotovinsko);
    QDate getDatumFormiranja;
    int getBrojIzvestaja;
    int getBrojIspravki;
    int getBrojFiskalnihRacuna;
    int getBrojRacunaZaBezgotovinsko;
};

#endif // KNJIGAEDI

