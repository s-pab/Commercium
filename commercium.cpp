#include "commercium.h"
#include "ui_commercium.h"

#include "formakalkulacije.h"
#include "formatrebovanje.h"
#include "formaotpremnica.h"
#include "formaprijemnica.h"
#include "formaprofaktura.h"
#include "formalogovanja.h"
#include "formanivelacija.h"
#include "formafaktura.h"
#include <QString>

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
    FormaLogovanja *fl=new FormaLogovanja(ui->mdiArea);
    fl->show();

}


void MainWindow::on_actionKalkulacija_triggered()
{
    FormaKalkulacije *fk = new FormaKalkulacije(ui->mdiArea);
    ui->mdiArea->addSubWindow(fk);
    fk->showMaximized();
}

void MainWindow::on_actionTrebovanje_triggered()
{
    FormaTrebovanje *ft=new FormaTrebovanje(ui->mdiArea);
    ui->mdiArea->addSubWindow(ft);
    ft->showMaximized();
}


void MainWindow::on_actionPrijemnice_triggered()
{
    FormaPrijemnica *fp=new FormaPrijemnica(ui->mdiArea);
    ui->mdiArea->addSubWindow(fp);
    fp->showMaximized();
}

void MainWindow::on_actionOtpremnice_triggered()
{
    FormaOtpremnica *fo=new FormaOtpremnica(ui->mdiArea);
    ui->mdiArea->addSubWindow(fo);
    fo->showMaximized();
}

void MainWindow::on_actionFaktura_triggered()
{
    FormaFaktura *ffa=new FormaFaktura(ui->mdiArea);
    ui->mdiArea->addSubWindow(ffa);
    ffa->showMaximized();
}

void MainWindow::on_actionProfaktura_triggered()
{
    FormaProfaktura *fpf=new FormaProfaktura(ui->mdiArea);
    ui->mdiArea->addSubWindow(fpf);
    fpf->showMaximized();
}

void MainWindow::on_actionNivelacije_triggered()
{
    FormaNivelacija *fn=new FormaNivelacija(ui->mdiArea);
    ui->mdiArea->addSubWindow(fn);
    fn->showMaximized();
}


