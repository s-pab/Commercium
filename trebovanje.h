#ifndef TREBOVANJE_H
#define TREBOVANJE_H

#include"artikl.h"


class Trebovanje
{
private:
    int nomenBroj; //ne znam sta je tako sam video na formularu
    Artikl artikl;
    double iznos;
public:
    Trebovanje();
    Artikl napraviArtikl();
    void setNomenBroj();
    double racunajIznos(Artikl artikl);
    int getNomenBroj();
};

#endif // TREBOVANJE_H

