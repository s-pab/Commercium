#include "formakomitent.h"
#include "ui_formakomitent.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QSqlQuery>
#include <QStringList>
#include <QSqlQueryModel>

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

void FormaKomitent::on_pushButton_3_clicked()
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

void FormaKomitent::on_pushButton_clicked()
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

void FormaKomitent::on_pushButton_2_clicked()
{

}
