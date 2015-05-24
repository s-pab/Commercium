#include "formanaloguplata.h"
#include "ui_formanaloguplata.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QPainter>

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
    /*QString uplatilac=ui->label->text()+" - "+ui->lineEdit->text();
    QString svrha=ui->label_2->text()+" - "+ui->lineEdit_4->text();
    QString primalac=ui->label_3->text()+" - "+ui->lineEdit_7->text();
    QString sifra=ui->label_8->text()+" "+ui->label_14->text()+" "+ui->lineEdit_2->text();
    QString valuta=ui->label_9->text()+" "+ui->lineEdit_3->text();
    QString iznos=ui->label_10->text()+" "+ui->lineEdit_5->text();
    QString racun=ui->label_11->text()+" "+ui->lineEdit_6->text();
    QString poziv=ui->label_12->text()+" "+ui->lineEdit_8->text()+" "+ui->lineEdit_9->text();
    QString filename="uplatnica.doc";
    QFile file(filename);
    QTextStream out(&file);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    out<<"Nalog za uplatu"<<endl;
    out<<uplatilac<<endl;
    out<<svrha<<endl;
    out<<primalac<<endl;
    out<<sifra<<endl;
    out<<valuta<<endl;
    out<<iznos<<endl;
    out<<racun<<endl;
    out<<poziv<<endl;
    file.close();
    QImage uplatnica("qrc:/Images/uplatnica.jpg");
    QPainter upis(&uplatnica);
    upis.setPen(Qt::black);
    upis.setBrush(QBrush(Qt::black));
    upis.setFont(QFont("Arial",12));*/
    ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,270))).save("uplatnica.jpg");
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
