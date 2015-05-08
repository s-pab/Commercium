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
