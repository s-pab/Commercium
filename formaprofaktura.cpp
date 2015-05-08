#include "formaprofaktura.h"
#include "ui_formaprofaktura.h"

FormaProfaktura::FormaProfaktura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaProfaktura)
{
    ui->setupUi(this);
}

FormaProfaktura::~FormaProfaktura()
{
    delete ui;
}

void FormaProfaktura::on_pushButton_6_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_8->clear();
    ui->lineEdit_9->clear();
    ui->listView->clearFocus();
}
