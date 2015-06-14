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
#include "formanaloguplata.h"
#include "formapopis.h"
#include "formanalogisplata.h"
#include "formanalogprenos.h"
#include "formaartikl.h"
#include "formakomitent.h"
#include <QLabel>
#include <QString>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>
#include <QPixmap>

#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->mdiArea = new QMdiArea;
    setCentralWidget(ui->mdiArea);
    QTimer::singleShot(0, this, SLOT(connectToDatabase()));
}

void MainWindow::connectToDatabase()
{
    // Konektovanje na bazu
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    QString path = qApp->applicationDirPath();
    QString conn = "DRIVER={Microsoft Access Driver (*.mdb)};DefaultDir=" + path + ";DBQ=Commercium.mdb";
    db.setDatabaseName(conn);
    if(!db.open())
    {
        QString dbFilename = QFileDialog::getOpenFileName(this, "Izbor baze podataka", path, "MS Access Database (*.mdb);;All Files (*.*)");
        db.setDatabaseName("DRIVER={Microsoft Access Driver (*.mdb)};DBQ=" + dbFilename);
        if(!db.open())
        {
            QMessageBox::critical(this, "Commercium", "Greska pri otvaranju baze podataka!", QMessageBox::Abort, QMessageBox::NoButton);
            db.close();
            emit close();
            return;
        }
    }
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


void MainWindow::on_actionO_nama_triggered()
{
    QLabel *image = new QLabel();
       image->setPixmap(QPixmap( ":/Images/SPABTeam.png"));
       image->show();
}

void MainWindow::on_action_ablon_uplatnice_triggered()
{
    FormaNalogUplata *fnl=new FormaNalogUplata(ui->mdiArea);
    ui->mdiArea->addSubWindow(fnl);
    fnl->showMaximized();

}


void MainWindow::on_actionPopis_triggered()
{
    FormaPopis *fp = new FormaPopis(ui->mdiArea);
    ui->mdiArea->addSubWindow(fp);
    fp->showMaximized();
}
void MainWindow::on_actionNalog_za_isplatu_triggered()
{
    FormaNalogIsplata *fni=new FormaNalogIsplata(ui->mdiArea);
    ui->mdiArea->addSubWindow(fni);
    fni->showMaximized();
}

void MainWindow::on_actionNalog_za_prenos_triggered()
{
    FormaNalogPrenos *fnp=new FormaNalogPrenos(ui->mdiArea);
    ui->mdiArea->addSubWindow(fnp);
    fnp->showMaximized();
}

void MainWindow::on_actionZabranjeno_pu_enje_triggered()
{
       QLabel *image = new QLabel();
       image->setPixmap(QPixmap( ":/Images/zabranjeno pusenje.jpg"));
       QString imagePath = QFileDialog::getSaveFileName(this,tr("Sačuvajte nalepnicu zabranjeno pušenje!"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
       QPixmap imageObject = image->grab(QRect(QPoint(5,0),QPoint(365,510)));
       imageObject.save(imagePath);
       image->show();
}

void MainWindow::on_actionUzimite_ra_un_triggered()
{
    QLabel *image = new QLabel();
    image->setPixmap(QPixmap( ":/Images/uzmite-racun.jpg"));
    QString imagePath = QFileDialog::getSaveFileName(this,tr("Sačuvajte nalepnicu uzmite račun!"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
    QPixmap imageObject = image->grab(QRect(QPoint(280,0),QPoint(720,480)));
    imageObject.save(imagePath);
    image->showMaximized();
}

void MainWindow::on_actionZabrana_prodaje_cigareta_osobama_ispod_18_godina_triggered()
{
    QLabel *image = new QLabel();
    image->setPixmap(QPixmap( ":/Images/cigarete ispod 18.jpg"));
    QString imagePath = QFileDialog::getSaveFileName(this,tr("Sačuvajte nalepnicu zabrana prodaje cigareta osobama ispod 18 godina!"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
    QPixmap imageObject = image->grab(QRect(QPoint(0,75),QPoint(230,370)));
    imageObject.save(imagePath);
    image->show();
}

void MainWindow::on_actionZabrana_prodaje_alkohola_osobama_ispod_18_godina_triggered()
{
    QLabel *image = new QLabel();
    image->setPixmap(QPixmap( ":/Images/zabrana alkohola.jpg"));
    QString imagePath = QFileDialog::getSaveFileName(this,tr("Sačuvajte nalepnicu zabrana prodaje alkoholnih pića osobama ispod 18 godina!"),"",tr("JPEG (*.jpg *.jpeg);;PNG (*.png)" ));
    QPixmap imageObject = image->grab(QRect(QPoint(80,0),QPoint(440,510)));
    imageObject.save(imagePath);
    image->show();
}

void MainWindow::on_actionPrikaz_informacija_o_artiklima_triggered()
{
    FormaArtikl *fa=new FormaArtikl(ui->mdiArea);
    ui->mdiArea->addSubWindow(fa);
    fa->showMaximized();
}

void MainWindow::on_actionPrikaz_informacija_o_komitentima_triggered()
{
    FormaKomitent *fkp=new FormaKomitent (ui->mdiArea); //fkp kao forma komitenti prikaz
    ui->mdiArea->addSubWindow(fkp);
    fkp->showMaximized();
}
