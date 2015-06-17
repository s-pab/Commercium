#include "formanalogisplata.h"
#include "ui_formanalogisplata.h"
#include <QString>
#include <QFileDialog>

FormaNalogIsplata::FormaNalogIsplata(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaNalogIsplata)
{
    ui->setupUi(this);
}

FormaNalogIsplata::~FormaNalogIsplata()
{
    delete ui;
}

void FormaNalogIsplata::on_snimiIsplatnicu_clicked()
{
    writeisplata();
}

void FormaNalogIsplata::writeisplata()
{
    QString imagePath = QFileDialog::getSaveFileName(this,tr("Sačuvaj nalog za isplatu!"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));

       QPixmap imageObject = ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,280)));

       imageObject.save(imagePath);

    //ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,270))).save("isplata.jpg");
}

void FormaNalogIsplata::on_ocistiIsplatnicu_clicked()
{
    ui->isplatilac->clear();
    ui->svrhaIsplate->clear();
    ui->primalac->clear();
    ui->sifraPlacanja->clear();
    ui->iznos->clear();
    ui->valuta->clear();
    ui->racunisplatioca->clear();
    ui->model->clear();
    ui->pozivNabroj->clear();
}
