#include "formafaktura.h"
#include "ui_formafaktura.h"

FormaFaktura::FormaFaktura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaFaktura)
{
    ui->setupUi(this);
}

FormaFaktura::~FormaFaktura()
{
    delete ui;
}

void FormaFaktura::on_pushButton_3_clicked()
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
    ui->listView->clearFocus();
}
