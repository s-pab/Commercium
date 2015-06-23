#include "formalogovanja.h"
#include "ui_formalogovanja.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QSqlError>

FormaLogovanja::FormaLogovanja(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormaLogovanja)
{
    ui->setupUi(this);
    connect();
    setLayout(ui->verticalLayout_2);
}

FormaLogovanja::~FormaLogovanja()
{
    delete ui;
}

void FormaLogovanja::connect()
{
    db = QSqlDatabase::addDatabase("QODBC");
    QString path = qApp->applicationDirPath();
    QString conn = "DRIVER={Microsoft Access Driver (*.mdb)};DefaultDir=" + path + ";DBQ=korisnici.mdb";
    //db.setDatabaseName ("DRIVER = {Microsoft Access Driver (*. mdb)}; FIL = {MS Access}; DBQ = korisnici.mdb");
    db.setDatabaseName(conn);
    //db.setPassword("commercium.trgovina");
    if(!db.open())
    {
        qDebug()<<db.lastError();
         QMessageBox::critical(this, "Commercium", "Greska pri otvaranju baze podataka!", QMessageBox::Abort, QMessageBox::NoButton);
         emit close();
         return;
    }
}

void FormaLogovanja::on_bPrijava_clicked()
{

    QString username=ui->leKorisnicko->text();
    QString password=ui->leLozinka->text();
    QSqlQuery qry;
    qry.prepare("SELECT * from Korisnici WHERE korisnickoIme=:USR AND lozinka=:PSW");
   // qry.prepare("SELECT Users.korisnickoIme, Users.lozinka FROM Users WHERE Users.korisnickoIme=:USR AND Users.lozinka=:PSW");
    qry.bindValue(":USR",username);
    qry.bindValue(":PSW",password);
    qry.exec();
    if(qry.next())
        emit accept();
    else
    {
        QMessageBox msg;
        msg.setText("Pogresno korisnicko ime ili lozinka");
        msg.setWindowTitle("Greska");
        msg.addButton(QMessageBox::Ok);
        msg.setButtonText(QMessageBox::Ok,"Probaj ponovo");
        msg.exec();
        ui->leKorisnicko->clear();
        ui->leLozinka->clear();
    }
    db.close();
}
