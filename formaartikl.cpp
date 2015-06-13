#include "formaartikl.h"
#include "ui_formaartikl.h"
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QSqlQuery>
#include <QStringList>
#include <QSqlQueryModel>

FormaArtikl::FormaArtikl(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaArtikl)
{
    ui->setupUi(this);
}

FormaArtikl::~FormaArtikl()
{
    delete ui;
}

void FormaArtikl::on_pushButton_5_clicked()
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

void FormaArtikl::on_pushButton_4_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT sifraProizvoda,nazivProizvoda,jedinicaMere,nabavnaCena,kategorijaPDV,marza,rabat,prodajnaCena,kolicina FROM Artikl");
    //query.bindValue(":brpopisa",ui->spinBox->value());
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->resizeRowsToContents();
}
