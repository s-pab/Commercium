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

void FormaOtpremnica::on_obrisi_clicked()
{

}
