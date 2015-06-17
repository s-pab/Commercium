#include "formaprijemnica.h"
#include "ui_formaprijemnica.h"

FormaPrijemnica::FormaPrijemnica(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaPrijemnica)
{
    ui->setupUi(this);
}

FormaPrijemnica::~FormaPrijemnica()
{
    delete ui;
}

void FormaPrijemnica::on_obrisi_clicked()
{
    ui->brojPrijemnice->clear();
    ui->tabelaPosiljalac->clearFocus();
    ui->tabelaPrijemnica->clearFocus();
    ui->tabelaPrimalac->clearFocus();
}
