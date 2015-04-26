#include "mainwindow.h"
#include "ui_commercium.h"

#include "formakalkulacije.h"
#include "formatrebovanje.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_actionZatvori_triggered()
{
    emit close();
}

void MainWindow::on_actionNova_triggered()
{
}

void MainWindow::on_actionNova_2_triggered()
{
    FormaKalkulacije *fk = new FormaKalkulacije(this);
    fk->show();
}

void MainWindow::on_actionNova_8_triggered()
{
    FormaTrebovanje *ft = new FormaTrebovanje(this);
    ft->show();
}
