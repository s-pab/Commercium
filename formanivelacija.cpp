#include "formanivelacija.h"
#include "ui_formanivelacija.h"

FormaNivelacija::FormaNivelacija(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaNivelacija)
{
    ui->setupUi(this);
}

FormaNivelacija::~FormaNivelacija()
{
    delete ui;
}

void FormaNivelacija::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->listView->clearFocus();
}
