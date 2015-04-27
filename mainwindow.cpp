#include "mainwindow.h"
#include "ui_commercium.h"

#include "formakalkulacije.h"
#include "formatrebovanje.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->mdiArea = new QMdiArea;
    setCentralWidget(ui->mdiArea);
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


void MainWindow::on_actionKalkulacija_triggered()
{
    FormaKalkulacije *fk = new FormaKalkulacije(ui->mdiArea);
    ui->mdiArea->addSubWindow(fk);
    fk->showMaximized();
}
