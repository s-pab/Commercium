#ifndef PRIJEMNICE
#define PRIJEMNICE

class Prijemnice
{
private:
    int sifraArtikla;
    Artikl artikl;
    int kolicina;
    double ukupnaVrednost;
public:
    Prijemnice();
    Prijemnice(int sifraArtikla,Artikl artikl,int kolicina);
    double izracunajUkupnuVrednost();
    void setSifraArtikla();
    void setKolicina();
    int getSifraArtikla();
    int getKolicina();
};

#endif // PRIJEMNICE

