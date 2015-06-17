#include "formakomitent.h"
#include "ui_formakomitent.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QSqlQuery>
#include <QStringList>
#include <QSqlQueryModel>
#include <QDebug>

FormaKomitent::FormaKomitent(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaKomitent)
{
    ui->setupUi(this);
}

FormaKomitent::~FormaKomitent()
{
    delete ui;
}

void FormaKomitent::on_prikazKomitenta_clicked()//prikaz
{
    QSqlQuery query;
    query.prepare("SELECT sifra,naziv,ulica,mesto,pib,tekuciRacun FROM Komitenti");
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->tabelaKomitenti->setModel(model);
    ui->tabelaKomitenti->resizeColumnsToContents();
    ui->tabelaKomitenti->resizeRowsToContents();
}

void FormaKomitent::on_dodajKomitenta_clicked()//dodavanje
{
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT sifra FROM Komitenti");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->sifra->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(!postoji)
    {
        query.prepare("INSERT INTO Komitenti (sifra,naziv,ulica,mesto,pib,tekuciRacun) VALUES (:SIFRA,:NAZIV,:ULICA,:MESTO,:PIB,:TEKUCIRACUN)");
        query.bindValue(":SIFRA",ui->sifra->text().toInt());
        query.bindValue(":NAZIV",ui->naziv->text());
        query.bindValue(":ULICA",ui->ulica->text());
        query.bindValue(":MESTO",ui->mesto->text());
        query.bindValue(":PIB",ui->pib->text().toInt());
        query.bindValue(":TEKUCIRACUN",ui->tekuciracun->text());
        query.exec();
        query2.prepare("SELECT sifra,naziv,ulica,mesto,pib,tekuciRacun FROM Komitenti ");
        query2.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query2);
        ui->tabelaKomitenti->setModel(model);
        ui->tabelaKomitenti->resizeColumnsToContents();
        ui->tabelaKomitenti->resizeRowsToContents();
    }
}

void FormaKomitent::on_izmenaKomitenta_clicked()//izmeni
{
    QSqlQuery query;
    query.prepare("UPDATE Komitenti SET naziv=:NAZIV, ulica=:ULICA, mesto=:MESTO, pib=:PIB, tekuciRacun=:TEKUCIRACUN  WHERE sifra=:SIFRA");
    query.bindValue(":SIFRA",ui->sifra->text().toInt());
    query.bindValue(":NAZIV",ui->naziv->text());
    query.bindValue(":ULICA",ui->ulica->text());
    query.bindValue(":MESTO",ui->mesto->text());
    query.bindValue(":PIB",ui->pib->text().toInt());
    query.bindValue(":TEKUCIRACUN",ui->tekuciracun->text());
    query.exec();
    on_prikazKomitenta_clicked();
}



void FormaKomitent::on_tabelaKomitenti_doubleClicked(const QModelIndex &index)//prebaci ga gore
{
    int row = index.row();
    ui->sifra->setText(index.sibling(row,0).data().toString());
    ui->naziv->setText(index.sibling(row,1).data().toString());
    ui->ulica->setText(index.sibling(row,2).data().toString());
    ui->mesto->setText(index.sibling(row,3).data().toString());
    ui->pib->setText(index.sibling(row,4).data().toString());
    ui->tekuciracun->setText(index.sibling(row,5).data().toString());
}

void FormaKomitent::on_obrisiKomitenta_clicked()
{
    QModelIndex index = ui->tabelaKomitenti->currentIndex();
    QSqlQuery query;
    query.prepare("DELETE FROM Komitenti WHERE sifra=:SIFRA");
    query.bindValue(":SIFRA",index.sibling(index.row(),0).data().toInt());
    query.exec();
    on_prikazKomitenta_clicked();

}
