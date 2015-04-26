#ifndef PRIJEMNICA
#define PRIJEMNICA

class Prijemnica
{
private:
    int sifraArtikla;
    Artikl artikl;
    int kolicina;
    double ukupnaVrednost;
public:
    Prijemnica();
    Prijemnica(int sifraArtikla,Artikl artikl,int kolicina);
    double izracunajUkupnuVrednost();
    void setSifraArtikla();
    void setKolicina();
    void dodajArtikl(Artikl artikl);
    int getSifraArtikla();
    int getKolicina();
};

#endif // PRIJEMNICE

