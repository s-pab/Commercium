#include "formalogovanja.h"
#include "ui_formalogovanja.h"

FormaLogovanja::FormaLogovanja(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaLogovanja)
{
    ui->setupUi(this);
}

FormaLogovanja::~FormaLogovanja()
{
    delete ui;
}

void FormaLogovanja::on_Otkazi_clicked()
{
    emit close();
}
