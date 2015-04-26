#ifndef TREBOVANJE_H
#define TREBOVANJE_H

class Treebovanje
{
private:
    int nomenBroj; //ne znam sta je tako sam video na formularu
    int kolicina;
    Artikl artikl;
    double iznos;
public:
    void setNomenBroj();
    void setKolicina();
    double racunajIznos(Artikl artikl);
    int getNomenBroj();
    int getKolicina();
};

#endif // TREBOVANJE_H

