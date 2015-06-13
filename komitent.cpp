#include "komitent.h"

Komitent::Komitent()
{

}
Komitent::Komitent(QString naziv, int sifra, QString ulica, QString mesto, unsigned int pib, QString tekuciRacun)
{
    this->naziv=naziv;
    this->sifra=sifra;
    this->ulica=ulica;
    this->mesto=mesto;
    this->pib=pib;
    this->tekuciRacun=tekuciRacun;
}
