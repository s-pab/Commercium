#ifndef KOMITENT_H
#define KOMITENT_H

#include <QString>;

class Komitent{
private:
    QString naziv;
    int sifra;
    QString ulica;
    QString mesto;
    unsigned int pib;
    QString tekuciRacun;
public:
    Komitent();
    Komitent(QString naziv, int sifra, QString ulica, QString mesto, unsigned int pib, QString tekuciRacun);
};

#endif // KOMITENT_H
