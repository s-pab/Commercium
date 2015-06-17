#include "artikl.h"

Artikl::Artikl()
{

}
Artikl::Artikl(int sifra,QString naziv,QString jedinica,int kategorija)
{
    this->sifraProizvoda=sifra;
    this->nazivProizvoda=naziv;
    this->jedinicaMere=jedinica;
    this->kategorijaPDV=kategorija;
}
void Artikl::dodajCenu(double nabavna, double marza, double rabat)
{
    int pdv = 20; //treba da se promeni da cita iz bazu ali u bazu nemamo to za pdv
    //treba da se promene lokalne promenjljive
    this->prodajnaCena = (nabavna - rabat)*(1+pdv/100)+marza;
    //treba da se promeni u bazu
}
void Artikl::dodajCenu(double nabavna, double prodajna)
{
    int pdv = 20;
    this->marza = prodajna - nabavna*(1+pdv/100);
    //treba da se promene lokalne promeljive i da se sve to doda u bazu
}
void Artikl::dodajCenuProcenat(double nabavna, double marzaP, double rabatP)
{
    int pdv = 20;
    this->prodajnaCena = (nabavna*(1-rabat/100)*(1+pdv/100))*(1+marza/100);
    //treba da se promene lokalne promenljivi i da se upise u bazu
}
void Artikl::setSifraProizvoda(int sifraProizvoda)
{
    this->sifraProizvoda = sifraProizvoda;
}
void Artikl::setNazivProizvoda(QString nazivProizvoda)
{
    this->nazivProizvoda = nazivProizvoda;
}

void Artikl::setProdajnaCena(double prodajnaCena)
{
    this->prodajnaCena = prodajnaCena;
}

void Artikl::setNabavnaCena(double nabavnaCena)
{
    this->nabavnaCena = nabavnaCena;
}

void Artikl::setMarza(double marza)
{
    this->marza = marza;
}

void Artikl::setMarzaProcenat(double marzaProcenat)
{
    this->marzaProcenat = marzaProcenat;
}

void Artikl::setRabat(double rabat)
{
    this->rabat = rabat;
}

void Artikl::setRabatProcenat(double rabatProcenat)
{
    this->rabatProcenat = rabatProcenat;
}

void Artikl::setJedinicaMere(QString jedinicaMere)
{
    this->jedinicaMere = jedinicaMere;
}

void Artikl::setKategorijaPDV(int kategorijaPDV)
{
    this->kategorijaPDV = kategorijaPDV;
}

void Artikl::setKolicina(int kolicina)
{
    this->kolicina = kolicina;
}

int Artikl::getSifraProizvoda()
{
    return sifraProizvoda;
}
QString Artikl::getNazivProizvoda()
{
    return nazivProizvoda;
}
double Artikl::getProdajnaCena()
{
    return prodajnaCena;
}
double Artikl::getNabavnaCena()
{
    return nabavnaCena;
}
double Artikl::getMarza()
{
    return marza;
}

double Artikl::getMarzaProcenat()
{
    return marzaProcenat;
}
double Artikl::getRabat()
{
    return rabat;
}
double Artikl::getRabatProcenat()
{
    return rabatProcenat;
}

QString Artikl::getJedinicaMere()
{
    return jedinicaMere;
}
int Artikl::getKategorijaPDV()
{
    return kategorijaPDV;
}
int Artikl::getKolicina()
{
    return kolicina;
}
