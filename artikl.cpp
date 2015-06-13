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

}
void Artikl::dodajCenu(double nabavna, double prodajna)
{

}
void Artikl::dodajCenuProcenat(double nabavna, double marzaP, double rabatP)
{

}
void Artikl::setSifraProizvoda(int sifraProizvoda)
{

}
void Artikl::setNazivProizvoda(QString nazivProizvoda)
{

}

void Artikl::setProdajnaCena(double prodajnaCena)
{

}

void Artikl::setNabavnaCena(double nabavnaCena)
{

}

void Artikl::setMarza(double marza)
{

}

void Artikl::setMarzaProcenat(double marzaProcenat)
{

}

void Artikl::setRabat(double rabat)
{

}

void Artikl::setRabatProcenat(double rabatProcenat)
{

}

void Artikl::setJedinicaMere(QString jedinicaMere)
{

}

void Artikl::setKategorijaPDV(int kategorijaPDV)
{

}

void Artikl::setKolicina(int kolicina)
{

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
