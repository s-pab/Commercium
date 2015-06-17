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

void FormaKomitent::on_pushButton_3_clicked()//prikaz
{
    QSqlQuery query;
    query.prepare("SELECT sifra,naziv,ulica,mesto,pib,tekuciRacun FROM Komitenti");
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}

void FormaKomitent::on_pushButton_clicked()//dodavanje
{
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT sifra FROM Komitenti");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->lineEdit->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(!postoji)
    {
        query.prepare("INSERT INTO Komitenti (sifra,naziv,ulica,mesto,pib,tekuciRacun) VALUES (:SIFRA,:NAZIV,:ULICA,:MESTO,:PIB,:TEKUCIRACUN)");
        query.bindValue(":SIFRA",ui->lineEdit->text().toInt());
        query.bindValue(":NAZIV",ui->lineEdit_2->text());
        query.bindValue(":ULICA",ui->lineEdit_3->text());
        query.bindValue(":MESTO",ui->lineEdit_4->text());
        query.bindValue(":PIB",ui->lineEdit_5->text().toInt());
        query.bindValue(":TEKUCIRACUN",ui->lineEdit_6->text());
        query.exec();
        query2.prepare("SELECT sifra,naziv,ulica,mesto,pib,tekuciRacun FROM Komitenti ");
        query2.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query2);
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
    }
}

void FormaKomitent::on_pushButton_2_clicked()//izmeni
{
    QSqlQuery query;
    query.prepare("UPDATE Komitenti SET naziv=:NAZIV, ulica=:ULICA, mesto=:MESTO, pib=:PIB, tekuciRacun=:TEKUCIRACUN  WHERE sifra=:SIFRA");
    query.bindValue(":SIFRA",ui->lineEdit->text().toInt());
    query.bindValue(":NAZIV",ui->lineEdit_2->text());
    query.bindValue(":ULICA",ui->lineEdit_3->text());
    query.bindValue(":MESTO",ui->lineEdit_4->text());
    query.bindValue(":PIB",ui->lineEdit_5->text().toInt());
    query.bindValue(":TEKUCIRACUN",ui->lineEdit_6->text());
    query.exec();
    on_pushButton_3_clicked();
}



void FormaKomitent::on_tableView_doubleClicked(const QModelIndex &index)//prebaci ga gore
{
    int row = index.row();
    ui->lineEdit->setText(index.sibling(row,0).data().toString());
    ui->lineEdit_2->setText(index.sibling(row,1).data().toString());
    ui->lineEdit_3->setText(index.sibling(row,2).data().toString());
    ui->lineEdit_4->setText(index.sibling(row,3).data().toString());
    ui->lineEdit_5->setText(index.sibling(row,4).data().toString());
    ui->lineEdit_6->setText(index.sibling(row,5).data().toString());
}

void FormaKomitent::on_pushButton_4_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    QSqlQuery query;
    query.prepare("DELETE FROM Komitenti WHERE sifra=:SIFRA");
    query.bindValue(":SIFRA",index.sibling(index.row(),0).data().toInt());
    query.exec();
    on_pushButton_3_clicked();

}
