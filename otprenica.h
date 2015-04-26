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
public:
    Otpremnica();
    Otrpemnica(int sifra,Komitent komitent);
    void dodajArtikl(Artikl artikl);
    void obrisiArtikl();
    void izmeniArtikl();
    void obracunaj();

};

#endif // OTPRENICE

