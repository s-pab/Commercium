#include "formafaktura.h"
#include "ui_formafaktura.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QTextStream>

#include <QDateTime>

FormaFaktura::FormaFaktura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaFaktura)
{
    ui->setupUi(this);
    pretraga("");
}

FormaFaktura::~FormaFaktura()
{
    delete ui;
}


void FormaFaktura::on_obrisi_clicked()
{

}

void FormaFaktura::on_nova_clicked()
{
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT sifraFakture FROM FaktureOsnovno");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->racunBroj->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(!postoji)
    {
        query.prepare("INSERT INTO FaktureOsnovno (sifraFakture,datum,valuta) VALUES (:SIFRA,:DATUM,:VALUTA)");
        query.bindValue(":SIFRA",ui->racunBroj->text().toInt());
        QDate Datum = ui->datumPlacanja->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":VALUTA",ui->valuta->text().toInt());
        query.exec();
        query.exec("SELECT SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA FROM Artikl");
        while (query.next()) {
            query2.prepare("INSERT INTO FakturePodaci (SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA,KOLICINA,brFakture) VALUES (:SIFRA,:NAZIV,:CENA,:KOLICINA,:UKUPNO,:brFakture)");
            query2.bindValue(":SIFRA",query.value(0));
            query2.bindValue(":NAZIV",query.value(1));
            query2.bindValue(":CENA",query.value(2));
            query2.bindValue(":KOLICINA",0);
            query2.bindValue(":brFakture",ui->racunBroj->text().toInt());
            query2.exec();
        }
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM FakturePodaci WHERE brFakture = :brFakture");
        query.bindValue(":brFakture",ui->racunBroj->text().toInt());
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->prikaz->setModel(model);
        ui->prikaz->resizeColumnsToContents();
        ui->prikaz->resizeRowsToContents();
    }
}

void FormaFaktura::pretraga(QString naziv)
{
    QSqlQuery query;
    if(naziv == "")
        query.prepare("SELECT sifraProizvoda,nazivProizvoda,nabavnaCena,kolicina FROM Artikl");
    else
    {
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci WHERE NazivProizvoda LIKE '%'+?+'%'");
        query.addBindValue(naziv);
    }
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->twArtikli->setModel(model);
    ui->twArtikli->resizeColumnsToContents();
    ui->twArtikli->resizeRowsToContents();
}

void FormaFaktura::on_lePretraga_textChanged(const QString &arg1)
{
    pretraga(arg1);
}

void FormaFaktura::on_pbUbaci_clicked()
{
    QSqlQuery query2;
    QModelIndex index = ui->twArtikli->currentIndex();
    int row = index.row();
    /*ui->sifra->setText(index.sibling(row,0).data().toString());
    ui->naziv->setText(index.sibling(row,1).data().toString());
    ui->ulica->setText(index.sibling(row,2).data().toString());
    ui->mesto->setText(index.sibling(row,3).data().toString());
    ui->pib->setText(index.sibling(row,4).data().toString());
    ui->tekuciracun->setText(index.sibling(row,5).data().toString());*/


    query2.prepare("INSERT INTO FakturePodaci (SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA,KOLICINA,brFakture) VALUES (:SIFRA,:NAZIV,:CENA,:KOLICINA,:brFakture)");
    query2.bindValue(":SIFRA",index.sibling(row,0).data().toInt());
    query2.bindValue(":NAZIV",index.sibling(row,1).data().toString());
    query2.bindValue(":CENA",index.sibling(row,2).data().toInt());
    query2.bindValue(":KOLICINA",index.sibling(row,3).data().toInt());
    query2.bindValue(":brFakture",ui->racunBroj->text().toInt());
    query2.exec();
    osvezi();
}

void FormaFaktura::osvezi()
{
    QSqlQuery query;
    //query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM FakturePodaci WHERE brFakture = :brf");
    query.prepare("SELECT * FROM FakturePodaci WHERE brFakture = :brf");
    query.bindValue(":brf",ui->racunBroj->text().toInt());
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikaz->setModel(model);
    ui->prikaz->resizeColumnsToContents();
    ui->prikaz->resizeRowsToContents();
}
