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


