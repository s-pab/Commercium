#ifndef ARTIKLI
#define ARTIKLI

#include<QString>

class Artikli{
private:
    int sifraProizvoda;
    QString nazivProizvoda;
    double prodajnaCena;
    double nabavnaCena;
    double marza;
    double marzaProcenat;
    double rabat;
    double rabatProcenat;
    QString jedinicaMere;
    int kategorijaPDV;
public:
    Artikli();
    Artikli(int sifra,QString naziv,QString jedinica,int kategorija);
    void dodajCenu(double nabavna, double marza, double rabat);
    void dodajCenu(double nabavna, double prodajna);
    void dodajCenuProcenat(double nabavna, double marzaP, double rabatP);
    void setSifraProizvoda(int sifraProizvoda);
    void setNazivProizvoda(QString nazivProizvoda);
    void setProdajnaCena(double prodajnaCena);
    void setNabavnaCena(double nabavnaCena);
    void setMarza(double marza);
    void setMarzaProcenat(double marzaProcenat);
    void setRabat(double rabat);
    void setRabatProcenat(double rabatProcenat);
    void setJedinicaMere(QString jedinicaMere);
    void setKategorijaPDV(int kategorijaPDV);
    int getSifraProizvoda();
    QString getNazivProizvoda();
    double getProdajnaCena();
    double getNabavnaCena();
    double getMarza();
    double getMarzaProcenat();
    double getRabat();
    double getRabatProcenat();
    QString getJedinicaMere();
    int getKategorijaPDV();
};

#endif // ARTIKLI

