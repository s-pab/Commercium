#ifndef OTPREMNICA
#define OTPREMNICA

#include "artikl.h"
#include "komitent.h"

class Otpremnica
{
private:
    int sifra;
    Artikl artikl;
    Komitent komitent;
    double ukupnaVrednost;
public:
    Otpremnica();
    Otpremnica(int sifra,Komitent komitent);
    void dodajArtikl();
    void obrisiArtikl();
    void izmeniArtikl();
    void obracunaj();
    int getSifra();

};

#endif // OTPRENICE

