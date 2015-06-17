#include "formanaloguplata.h"
#include "ui_formanaloguplata.h"
#include <QString>
#include <QFileDialog>
#include <QTextStream>


FormaNalogUplata::FormaNalogUplata(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaNalogUplata)
{
    ui->setupUi(this);
}

FormaNalogUplata::~FormaNalogUplata()
{
    delete ui;
}

void FormaNalogUplata::on_snimiUplatnicu_clicked()
{
    writeuplata();
}
void FormaNalogUplata::writeuplata()
{
    QString imagePath = QFileDialog::getSaveFileName(this,tr("Sačuvaj nalog za uplatu!"),"", tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));

       QPixmap imageObject = ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,280)));

       imageObject.save(imagePath);
    //ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,270))).save("uplatnica.jpg");
}

void FormaNalogUplata::on_ocistiUplatnicu_clicked()
{
    ui->uplatilac->clear();
    ui->svrhaUplate->clear();
    ui->primalac->clear();
    ui->sifraPlacanja->clear();
    ui->valuta->clear();
    ui->iznos->clear();
    ui->racunPrimaoca->clear();
    ui->model->clear();
    ui->pozivNabroj->clear();
}
