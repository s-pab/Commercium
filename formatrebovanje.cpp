#include "formatrebovanje.h"
#include "ui_formatrebovanje.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QTextStream>

#include <QDateTime>

FormaTrebovanje::FormaTrebovanje(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaTrebovanje)
{
    ui->setupUi(this);
}

FormaTrebovanje::~FormaTrebovanje()
{
    delete ui;
}

void FormaTrebovanje::on_pretragaKomitenata_textChanged(const QString &arg1)
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

void FormaTrebovanje::on_pretragaArtikala_textChanged(const QString &arg1)
{
    pretraga(arg1);
}

void FormaTrebovanje::on_nova_clicked()
{
    if(ui->brojTrebovanja->text()=="")
    {
        QMessageBox msg;
        msg.setText("Unesite broj trebovanja");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        return;
    }
    QSqlQuery query;
    bool postoji = false;
    query.exec("SELECT sifraTrebovanja FROM TrebovanjeOsnovno");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->brojTrebovanja->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(postoji)
    {
        query.prepare("UPDATE TrebovanjeOsnovno (sifraTrebovanja,datum,komitent,ukupnavrednost) VALUES (:SIFRA,:DATUM,:KOMITENT,:UKUPNAVREDNOST)");
        query.bindValue(":SIFRA",ui->brojTrebovanja->text().toInt());
        QDate Datum = ui->datum->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":KOMITENT",ui->komitent->text().toInt());
        query.bindValue(":UKUPNAVREDNOST",ui->ukupnaVrednost->text().toDouble());
        query.exec();
    }
    else
    {
        query.prepare("INSERT INTO TrebovanjeOsnovno (sifraTrebovanja,datum,komitent,ukupnavrednost) VALUES (:SIFRA,:DATUM,:KOMITENT,:UKUPNAVREDNOST)");
        query.bindValue(":SIFRA",ui->brojTrebovanja->text().toInt());
        QDate Datum = ui->datum->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":KOMITENT",ui->komitent->text().toInt());
        query.bindValue("UKUPNAVREDNOST",ui->ukupnaVrednost->text().toDouble());
        query.exec();
        osvezi();
    }

}

void FormaTrebovanje::on_izmeni_clicked()
{

}

void FormaTrebovanje::on_obrisi_clicked()
{

}
void FormaTrebovanje::pretraga(QString naziv)
{
    QSqlQuery query;
    if(naziv == "")
        query.prepare("SELECT sifraProizvoda,nazivProizvoda,nabavnaCena,jedinicaMere,kolicina FROM Artikl");
    else
    {
        query.prepare("SELECT sifraProizvoda,nazivProizvoda,jedinicaMere,kolicina FROM Artikl WHERE nazivProizvoda LIKE '%'+?+'%'");
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
void FormaTrebovanje::osvezi()
{
    QSqlQuery query;
    //query.prepare("SELECT SifraProizvoda,NazivProizvoda,Kolicina,JedinicaMere,brTrebovanja FROM TrebovanjePodaci WHERE brTrebovanja = :brt");
    query.prepare("SELECT * FROM TrebovanjePodaci WHERE brTrebovanja = :bro");
    query.bindValue(":bro",ui->brojTrebovanja->text().toInt());
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikaz->verticalHeader()->hide();
    ui->prikaz->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->prikaz->setModel(model);
    ui->prikaz->resizeColumnsToContents();
    ui->prikaz->resizeRowsToContents();
}

void FormaTrebovanje::on_ubaciKomitenta_clicked()
{
    QModelIndex index = ui->prikazKomitenta->currentIndex();
    int row = index.row();
    ui->komitent->setText(index.sibling(row,0).data().toString());
}

void FormaTrebovanje::on_ubaciArtikl_clicked()
{
    if(ui->brojTrebovanja->text()=="")
        return;
    QSqlQuery query2;
    QModelIndex index = ui->prikazArtikla->currentIndex();
    int row = index.row();
    query2.prepare("INSERT INTO TrebovanjePodaci (SIFRAPROIZVODA,NAZIVPROIZVODA,JEDINICAMERE,KOLICINA,brTrebovanja) VALUES (:SIFRA,:NAZIV,:JEDINICAMERE,:KOLICINA,:brTrebovanja)");
    query2.bindValue(":SIFRA",index.sibling(row,0).data().toInt());
    query2.bindValue(":NAZIV",index.sibling(row,1).data().toString());
    query2.bindValue(":JEDINICAMERE",index.sibling(row,2).data().toString());
    query2.bindValue(":KOLICINA",index.sibling(row,3).data().toInt());
    query2.bindValue(":brTrebovanja",ui->brojTrebovanja->text().toInt());
    query2.exec();
    osvezi();
}
