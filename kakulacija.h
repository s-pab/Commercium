#ifndef KAKULACIJA_H
#define KAKULACIJA_H

#include "artikl.h"
#include "komitent.h"

class Kalkulacija{
private:
    int sifra;
    Artikl artikli;
    Komitent komintent;
    int brArtikala;
    double ukupnoNabavnaVrednost;
    double ukupnoSaPDV;
    double ukupnoBezPVD;
    double ukupnoPDV;
public:
    Kalkulacija();
    Kalkulacija(int sifra, Komitent komintent);
    void dodajArtikl(Artikl artikl);
    Artikl napraviArtikl();
    void obrisiArtikl();
    void izmeniArtikl();
    void obracunaj();
};

#endif // KAKULACIJA_H
