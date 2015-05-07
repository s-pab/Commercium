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
