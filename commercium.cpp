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
#include "formanalogisplata.h"
#include "formanalogprenos.h"
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



void MainWindow::on_actionUvezi_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, QString(), QString(), "Comma separated value (*.csv);;All Files (*.*)");
    if(!filePath.isEmpty())
    {
        QFile file(filePath);
        QRegExp sep("[;]");
        if(file.open(QIODevice::ReadOnly))
        {
            QTextStream in(&file);
            QSqlQuery query;
            QString red = in.readLine();
            QStringList lista = red.split(sep);
            while(!in.atEnd())
            {
                red = in.readLine();
                lista = red.split(sep);
                query.prepare("INSERT INTO Artikl (sifraProizvoda,nazivProizvoda,jedinicaMere,nabavnaCena,kategorijaPDV,marza,rabat,prodajnaCena,kolicina) VALUES (:SIFRA,:NAZIV,:JEDMER,:NABAVNA,:KATEGORIJA,'0,00','0,00','0,00','0,00')");
                query.bindValue(":SIFRA",lista[0].toInt());
                query.bindValue(":NAZIV",lista[1]);
                query.bindValue(":JEDMER","kom");
                query.bindValue(":NABAVNA",lista[4].toDouble());
                query.bindValue(":KATEGORIJA",lista[2].toInt());

                query.exec();
           }
        }
        file.close();
    }
}

void MainWindow::on_actionO_nama_triggered()
{
    //ui->setupUi(this);
    QLabel *image = new QLabel();
       image->setPixmap( QPixmap( ":/Images/SPABTeam.png" ) );
       image->showMaximized();
      // show();
}

void MainWindow::on_action_ablon_uplatnice_triggered()
{
    FormaNalogUplata *fnl=new FormaNalogUplata(ui->mdiArea);
    ui->mdiArea->addSubWindow(fnl);
    fnl->showMaximized();

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
