#include "formatrebovanje.h"
#include "ui_formatrebovanje.h"

FormaTrebovanje::FormaTrebovanje(QWidget *parent) :
    QMainWindow(parent),
    uii(new Uii::FormaTrebovanje)
{
    uii->setupUi(this);
}

FormaTrebovanje::~FormaTrebovanje()
{
    delete uii;
}
