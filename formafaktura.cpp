#include "formafaktura.h"
#include "ui_formafaktura.h"

FormaFaktura::FormaFaktura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaFaktura)
{
    ui->setupUi(this);
}

FormaFaktura::~FormaFaktura()
{
    delete ui;
}
