#ifndef PRIJEMNICA
#define PRIJEMNICA

#include "artikl.h"
#include "komitent.h"

class Prijemnica
{
private:
    int sifra;
    Artikl artikl;
    Komitent komitent;
    double ukupnaVrednost;
public:
    Prijemnica();
    Prijemnica(Artikl artikl,Komitent komitent);
    double obracunaj();
    void dodajArtikl();
    void obrisiArtikl();
    void izmeniArtikl();
    int getSifra();
    /* ne znam sad da li treba da se pravi i za komintenta da se dodaje,
       jer tu je samo jedan na pocetku se popuni i to je to. Nije kao artikl pa da treba da se ubacuje vise njih
 mislim da ne treba, ako treba i to ce ubacimo nikakav problem isto vazi i za otpremnicu ako treba ovde treba i tamo i obrnuto*/
};

#endif // PRIJEMNICE

