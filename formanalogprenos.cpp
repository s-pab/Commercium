#include "formanalogprenos.h"
#include "ui_formanalogprenos.h"
#include <QString>
#include <QFileDialog>

FormaNalogPrenos::FormaNalogPrenos(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaNalogPrenos)
{
    ui->setupUi(this);
}

FormaNalogPrenos::~FormaNalogPrenos()
{
    delete ui;
}

void FormaNalogPrenos::on_snimiPrenos_clicked()
{
    writeprenos();
}
void FormaNalogPrenos::writeprenos()
{
    QString imagePath = QFileDialog::getSaveFileName(this,tr("Sačuvaj nalog za prenos!"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));

       QPixmap imageObject = ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,280)));

       imageObject.save(imagePath);
    //ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,275))).save("prenos.jpg");
}

void FormaNalogPrenos::on_ocistiPrenos_clicked()
{
    ui->duznik->clear();
    ui->svrhaIsplate->clear();
    ui->poverilac->clear();
    ui->sifraPlacanja->clear();
    ui->valuta->clear();
    ui->iznos->clear();
    ui->racunDuznika->clear();
    ui->modelZaduzenje->clear();
    ui->pozivNabrojzaduzenje->clear();
    ui->racunPoverioca->clear();
    ui->modelOdobrenje->clear();
    ui->pozivNabrojodobrenje->clear();
    ui->hitno->clear();
}
