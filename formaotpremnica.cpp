#include "formaotpremnica.h"
#include "ui_formaotpremnica.h"

FormaOtpremnica::FormaOtpremnica(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaOtpremnica)
{
    ui->setupUi(this);
}

FormaOtpremnica::~FormaOtpremnica()
{
    delete ui;
}

void FormaOtpremnica::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->listView->clearFocus();
    ui->listView_2->clearFocus();
    ui->listView_3->clearFocus();
}
