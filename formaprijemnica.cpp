#include "formaprijemnica.h"
#include "ui_formaprijemnica.h"

FormaPrijemnica::FormaPrijemnica(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaPrijemnica)
{
    ui->setupUi(this);
}

FormaPrijemnica::~FormaPrijemnica()
{
    delete ui;
}

void FormaPrijemnica::on_pushButton_3_clicked()
{
    ui->lineEdit->clear();
    ui->listView->clearFocus();
    ui->listView_3->clearFocus();
    ui->listView_4->clearFocus();
}
