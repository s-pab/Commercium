#ifndef OTPRENICA
#define OTPRENICA

#include "artikl.h"
#include "komitent.h"

class Otpremnica
{
private:
    int sifra;
    Artikl artikl;
    Komitent komitent;
    double ukupnaVrednost;
    //dodaj ovde sve vrednosti koje treba za vrednosti ako imas samo ukupnu vrednost onda ok
    //ako jos nesto ukupno racunas tip pdv ili tako nesto dodaj i to vidi kako sam ja u kalk
    // ovde je samo treba ukupna vrednost da se sracuna, ima i vrednost ali to je ustvari cena artika
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

