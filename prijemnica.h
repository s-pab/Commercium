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
    Prijemnica(int sifra,Komitent komitent);
    double obracunaj();
    void dodajArtikl();
    void obrisiArtikl();
    void izmeniArtikl();
    int getSifra();
};

#endif // PRIJEMNICE

