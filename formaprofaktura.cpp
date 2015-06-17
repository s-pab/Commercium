#include "formaprofaktura.h"
#include "ui_formaprofaktura.h"

FormaProfaktura::FormaProfaktura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaProfaktura)
{
    ui->setupUi(this);
}

FormaProfaktura::~FormaProfaktura()
{
    delete ui;
}

void FormaProfaktura::on_obrisi_clicked()
{
    ui->sifraKupca->clear();
    ui->PIB->clear();
    ui->datumPredracuna->clear();
    ui->kupac->clear();
    ui->brojPredracuna->clear();
    ui->mesto->clear();
    ui->mestoIzdavanja->clear();
    ui->valuta->clear();
    ui->tabelaPredracuna->clearFocus();
}
