#ifndef OTPRENICA
#define OTPRENICA

class Otpremnica
{
private:
    int sifraArtikla;
    Artikl artikl;
    int kolicina;
    double ukupnaVrednost;
public:
    Otpremnica();
    Otrpemnica(int sifraArtikla,Artikl artikl,int kolicina);
    double izracunajUkupnuVrednost();
    void setSifraArtikla();
    void setKolicina();
    void dodajArtikl(Artikl artikl);
    int getSifraArtikla();
    int getKolicina();
};

#endif // OTPRENICE

