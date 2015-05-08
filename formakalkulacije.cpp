#include "formakalkulacije.h"
#include "ui_formakalkulacije.h"

FormaKalkulacije::FormaKalkulacije(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaKalkulacije)
{
    ui->setupUi(this);
}

FormaKalkulacije::~FormaKalkulacije()
{
    delete ui;
}

void FormaKalkulacije::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    ui->lineEdit_6->clear();
    ui->lineEdit_7->clear();
    ui->lineEdit_8->clear();
    ui->listView->clearFocus();
}
