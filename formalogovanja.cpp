#include "formalogovanja.h"
#include "ui_formalogovanja.h"

FormaLogovanja::FormaLogovanja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormaLogovanja)
{
    ui->setupUi(this);
}

FormaLogovanja::~FormaLogovanja()
{
    delete ui;
}
