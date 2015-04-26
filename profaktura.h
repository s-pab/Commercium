#ifndef PROFAKTURA_H
#define PROFAKTURA_H

#include "artikl.h"
#include "komitent.h"
#include <QDate>
#include <QString>

class Profaktura{
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
    Profaktura();
    Profaktura(int sifra, Komitent komintent, QDate datum, QString brOtpremnice, int valuta);
    void dodajArtikl(Artikl artikl);
    void obrisiArtikl();
    void izmeniArtikl();
    void obracunaj();
    Artikl getArtikl();
    double getUkupnoNabavnaVrednost();
    double getUkupnoBezPVD();
    double getUkupnoPDV();
    double getUkupnoSaPDV();
    int getSifra();
};

#endif // PROFAKTURA_H
