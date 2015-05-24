#include "formanalogisplata.h"
#include "ui_formanalogisplata.h"

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

void FormaNalogIsplata::on_pushButton_clicked()
{
    writeisplata();
}

void FormaNalogIsplata::writeisplata()
{
    ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,270))).save("isplata.jpg");
}

void FormaNalogIsplata::on_pushButton_2_clicked()
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
