#include "formaotpremnica.h"
#include "ui_formaotpremnica.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QTextStream>

#include <QDateTime>

FormaOtpremnica::FormaOtpremnica(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaOtpremnica)
{
    ui->setupUi(this);
}

FormaOtpremnica::~FormaOtpremnica()
{
    delete ui;
}

void FormaOtpremnica::osvezi()
{
    QSqlQuery query;
    //query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM FakturePodaci WHERE brFakture = :brf");
    query.prepare("SELECT * FROM OtpremnicaPodaci WHERE brOtpremnice = :bro");
    query.bindValue(":bro",ui->brojOtpremnice->text().toInt());
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikaz->verticalHeader()->hide();
    ui->prikaz->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->prikaz->setModel(model);
    ui->prikaz->resizeColumnsToContents();
    ui->prikaz->resizeRowsToContents();
}
void FormaOtpremnica::pretraga(QString naziv)
{
    QSqlQuery query;
    if(naziv == "")
        query.prepare("SELECT sifraProizvoda,nazivProizvoda,nabavnaCena,kolicina FROM Artikl");
    else
    {
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina FROM Artikl WHERE NazivProizvoda LIKE '%'+?+'%'");
        query.addBindValue(naziv);
    }
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikazArtikla->verticalHeader()->hide();
    ui->prikazArtikla->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->prikazArtikla->setModel(model);
    ui->prikazArtikla->resizeColumnsToContents();
    ui->prikazArtikla->resizeRowsToContents();
}

void FormaOtpremnica::on_pretragaKomitenata_textChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare("SELECT sifra,naziv,ulica,mesto,pib,tekuciRacun FROM Komitenti WHERE naziv LIKE '%'+?+'%'");
    query.addBindValue(arg1);
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikazKomitenta->verticalHeader()->hide();
    ui->prikazKomitenta->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->prikazKomitenta->setModel(model);
    ui->prikazKomitenta->resizeColumnsToContents();
    ui->prikazKomitenta->resizeRowsToContents();
}

void FormaOtpremnica::on_pretragaArtikala_textChanged(const QString &arg1)
{
    pretraga(arg1);
}

void FormaOtpremnica::on_nova_clicked()
{
    if(ui->brojOtpremnice->text()=="")
    {
        QMessageBox msg;
        msg.setText("Unesite broj otpremnice");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        return;
    }
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT sifraOtpremnica FROM OtpremnicaOsnovno");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->brojOtpremnice->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(postoji)
    {
        QMessageBox msg;
        msg.setText("Otpremnica pod tom šifrom već postoji");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
    }
    else
    {
        query.prepare("INSERT INTO OtpremnicaOsnovno (sifraOtpremnica,datum,komitent,ukupnaVrednost) VALUES (:SIFRA,:DATUM,:KOMITENT,:UKUPNAVREDNOST)");
        query.bindValue(":SIFRA",ui->brojOtpremnice->text().toInt());
        QDate Datum = ui->datum->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":KOMITENT",ui->komitent->text().toInt());
        query.bindValue(":UKUPNAVREDNOST",ui->ukupnaVrednost->text().toDouble());
        query.exec();
     /* query.exec("SELECT SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA FROM Artikl");
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM FakturePodaci WHERE brFakture = :brFakture");
        query.bindValue(":brFakture",ui->racunBroj->text().toInt());
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->prikaz->setModel(model);
        ui->prikaz->resizeColumnsToContents();
        ui->prikaz->resizeRowsToContents();*/
    }
}

void FormaOtpremnica::on_ubaciKomitenta_clicked()
{
    QModelIndex index = ui->prikazKomitenta->currentIndex();
    int row = index.row();
    ui->sifra->setText(index.sibling(row,0).data().toString());
}

void FormaOtpremnica::on_ubaciArtikl_clicked()
{
    if(ui->brojOtpremnice->text()=="")
        return;
    QSqlQuery query2;
    QModelIndex index = ui->prikazArtikla->currentIndex();
    int row = index.row();
    /*ui->sifra->setText(index.sibling(row,0).data().toString());
    ui->naziv->setText(index.sibling(row,1).data().toString());
    ui->ulica->setText(index.sibling(row,2).data().toString());
    ui->mesto->setText(index.sibling(row,3).data().toString());
    ui->pib->setText(index.sibling(row,4).data().toString());
    ui->tekuciracun->setText(index.sibling(row,5).data().toString());*/


    query2.prepare("INSERT INTO OtpremnicaPodaci (SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA,KOLICINA,brFakture) VALUES (:SIFRA,:NAZIV,:CENA,:KOLICINA,:brFakture)");
    query2.bindValue(":SIFRA",index.sibling(row,0).data().toInt());
    query2.bindValue(":NAZIV",index.sibling(row,1).data().toString());
    query2.bindValue(":CENA",index.sibling(row,2).data().toInt());
    query2.bindValue(":KOLICINA",index.sibling(row,3).data().toInt());
    query2.bindValue(":brFakture",ui->brojOtpremnice->text().toInt());
    query2.exec();
    osvezi();
}
