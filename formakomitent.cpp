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
