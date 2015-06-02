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

void FormaNalogUplata::on_pushButton_clicked()
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

void FormaNalogUplata::on_pushButton_2_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
}
