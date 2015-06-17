#include "formatrebovanje.h"
#include "ui_formatrebovanje.h"

FormaTrebovanje::FormaTrebovanje(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaTrebovanje)
{
    ui->setupUi(this);
}

FormaTrebovanje::~FormaTrebovanje()
{
    delete ui;
}

void FormaTrebovanje::on_obrisi_clicked()
{
    ui->brojTrebvanja->clear();
    ui->tabelaTrebovanja->clearFocus();
}
