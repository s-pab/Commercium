#ifndef FAKTURA_H
#define FAKTURA_H

#include "artikl.h"
#include "komitent.h"
#include <QDate>
#include <QString>

class Faktura{
private:
    int sifra;
    QDate datum;
    QString brOtpremnice;
    int valuta;
    Artikl artikl;
    Komitent komintent;
    int brArtikala;
    double ukupnoNabavnaVrednost;
    double ukupnoBezPVD;
    double ukupnoPDV;
    double ukupnoSaPDV;
public:
    Faktura();
    Faktura(int sifra, Komitent komintent, QDate datum, QString brOtpremnice, int valuta);
    void dodajArtikl(Artikl artikl);
    void obrisiArtikl();
    void izmeniArtikl();
    void obracunaj();
    Artikl getArtikl();
    double getUkupnoNabavnaVrednost();
    double getUkupnoBezPVD();
    double getUkupnoPDV();
    double getUkupnoSaPDV();
};

#endif // FAKTURA_H
