#include "formanivelacija.h"
#include "ui_formanivelacija.h"

FormaNivelacija::FormaNivelacija(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaNivelacija)
{
    ui->setupUi(this);
}

FormaNivelacija::~FormaNivelacija()
{
    delete ui;
}

void FormaNivelacija::on_obrisi_clicked()
{
    ui->brojNivelacije->clear();
    ui->datumNivelacije->clear();
    ui->tabelaNivelacije->clearFocus();
}
