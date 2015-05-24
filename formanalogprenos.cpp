#include "formanalogprenos.h"
#include "ui_formanalogprenos.h"

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

void FormaNalogPrenos::on_pushButton_clicked()
{
    writeprenos();
}
void FormaNalogPrenos::writeprenos()
{
    ui->centralwidget->grab(QRect(QPoint(0,0),QPoint(640,275))).save("prenos.jpg");
}

void FormaNalogPrenos::on_pushButton_2_clicked()
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
    ui->lineEdit_10->clear();
    ui->lineEdit_11->clear();
    ui->lineEdit_12->clear();
    ui->lineEdit_13->clear();
}
