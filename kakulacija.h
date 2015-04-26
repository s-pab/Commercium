#ifndef KAKULACIJA_H
#define KAKULACIJA_H

#include "artikl.h"
#include "komitent.h"
#include <QDate>
#include <QString>

class Kalkulacija{
private:
    int sifra;
    QDate datum;
    QString brOtpremnice;
    int valuta;
    Artikl artikl;
    Komitent komintent;
    int brArtikala;
    double ukupnoNabavnaVrednost;
    double ukupnoPrenetiPDV;
    double ukupnoIznosRUC;
    double ukupnoSaPDV;
    double ukupnoBezPVD;
    double ukupnoPDV;
public:
    Kalkulacija();
    Kalkulacija(int sifra, Komitent komintent, QDate datum, QString brOtpremnice, int valuta);
    void dodajArtikl(Artikl artikl);
    void obrisiArtikl();
    void izmeniArtikl();
    void obracunaj();
    Artikl getArtikl();
    double getUkupnoNabavnaVrednost();
    double getUkupnoPrenetiPDV();
    double getUkupnoIznosRUC();
    double getUkupnoPDV();
    double getUkupnoBezPVD();
    double getUkupnoSaPDV();
    int getSifru();
};

#endif // KAKULACIJA_H
