#include "kakulacija.h"

Kalkulacija::Kalkulacija()
{

}

Kalkulacija::Kalkulacija(int sifra, Komitent komintent, QDate datum, QString brOtpremnice, int valuta)
{
    this->sifra = sifra;
    this->komintent = komintent;
    this->datum = datum;
    this->brOtpremnice = brOtpremnice;
    this->valuta = valuta;
    //ovde sad teba konekcija sa bazom da se ova kalkulacija poze sa tavkom u bazu a ako
    //takva ne postoji onda da se napravi u bazi.
}

void Kalkulacija::dodajArtikl(Artikl artikl)
{
    //ovde treba da se nadje pomocu arikl.getSifru() i da se nadje iz baze ucita ako nema da prijavi gresku
    //ako ima da se ucita i da se nakon obrade koja ce se vrsiti preko dodatne forma ubaci u bazu kao podatak za ovu kalkulaciju
}

void Kalkulacija::obrisiArtikl()
{
    //msm da ova funkcija preko forme moze da dobija koji da obrise, ali moze i da se napravi funkija koja ce kao
    //paarametar da dobije Artikl i da na osnovu toga obrise red u bazi u tabeli kalkulacijaPodaci
}

void Kalkulacija::izmeniArtikl()
{
    //isto kao i za dodavanje i bristanje
}

void Kalkulacija::obracunaj()
{
    //ovde ce da se obracunavaju sledece vrednosti:
    /*double ukupnoNabavnaVrednost;
    double ukupnoPrenetiPDV;
    double ukupnoIznosRUC;
    double ukupnoSaPDV;
    double ukupnoBezPVD;
    double ukupnoPDV;*/
}
//Artikl Kalkulacija::getArtikl()
//{
    //ova funkcija nam samo omogucava da imamo vezu sa trenutnim artiklom koga obradjujemo
//}

//ove funkcije nam trebaju da kad funkcija obracunaj odradi svoje da se posle sa ovim funkcijama
//vrednosti ovih promenljivh upisu u polja koja njima odgovaraju. predlazem da napravimo jednu funkciju ozvezi
//tamo u formi koja ce da zavrsi sve to
double Kalkulacija::getUkupnoNabavnaVrednost()
{
    return this->ukupnoNabavnaVrednost;
}

double Kalkulacija::getUkupnoPrenetiPDV()
{
    return this->ukupnoPrenetiPDV;
}

double Kalkulacija::getUkupnoIznosRUC()
{
    return this->ukupnoIznosRUC;
}

double Kalkulacija::getUkupnoPDV()
{
    return this->ukupnoPDV;
}

double Kalkulacija::getUkupnoBezPVD()
{
    return this->ukupnoBezPVD;
}

double Kalkulacija::getUkupnoSaPDV()
{
    return this->ukupnoSaPDV;
}
//trebace nam za konekciju sa bazom u formu da vi znali sa kojom se tacno kalkulacijom igramo
//mada moze i tamo iz forme da se procita.. mora se vodi racuna da je tamo sifra ista kao i ova ovde
int Kalkulacija::getSifru()
{
    return this->sifra;
}
