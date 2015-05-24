#include "formapopis.h"
#include "ui_formapopis.h"


#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QKeyEvent>

#include <QFile>
#include <QCoreApplication>
#include <QTextStream>

#include <QDateTime>

FormaPopis::FormaPopis(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaPopis)
{
    ui->setupUi(this);

}

FormaPopis::~FormaPopis()
{
    delete ui;
}

void FormaPopis::on_pushButton_clicked()
{
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT SifraPopisa FROM POPISOSNOVNO");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->spinBox->value())
        {
            postoji=true;
            break;
        }
    }
    if(!postoji)
    {
        query.prepare("INSERT INTO POPISOSNOVNO (SIFRAPOPISA,DATUM,UKUPNO) VALUES (:SIFRA,:DATUM,'0,00')");
        query.bindValue(":SIFRA",ui->spinBox->value());
        QDate Datum = ui->dateEdit->date();
        query.bindValue(":DATUM",Datum);
        query.exec();
        query.exec("SELECT SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA FROM Artikl");
        while (query.next()) {
            query2.prepare("INSERT INTO POPISPODACI (SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA,KOLICINA,UKUPNO,BRPOPISA) VALUES (:SIFRA,:NAZIV,:CENA,:KOLICINA,:UKUPNO,:BRPOPISA)");
            query2.bindValue(":SIFRA",query.value(0));
            query2.bindValue(":NAZIV",query.value(1));
            query2.bindValue(":CENA",query.value(2));
            query2.bindValue(":KOLICINA",0);
            query2.bindValue(":UKUPNO",0);
            query2.bindValue(":BRPOPISA",ui->spinBox->value());
            query2.exec();
        }
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci WHERE brpopisa = :brpopisa");
        query.bindValue(":brpopisa",ui->spinBox->value());
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->tableView_6->setModel(model);
        ui->tableView_6->resizeColumnsToContents();
        ui->tableView_6->resizeRowsToContents();
    }
}

void FormaPopis::on_lineEdit_29_returnPressed()
{
    if(!ui->lineEdit_29->text().isEmpty())
    {
        QSqlQuery query;
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci WHERE brpopisa = :brpopisa");
        query.bindValue(":brpopisa",ui->spinBox->value());
        query.exec();
        while(query.next())
        {
            int sifra = query.value(0).toInt();
            if(sifra==ui->lineEdit_29->text().toInt())
            {
                ui->lineEdit_30->setText(query.value(1).toString());
                double pom = query.value(3).toDouble();
                ui->lineEdit_26->setText(QString::number(pom,'.',2));
                kol=ui->lineEdit_26->text();

                ui->lineEdit_27->setText(query.value(2).toString());
                cena=ui->lineEdit_27->text();
                pom=query.value(4).toDouble();
                ui->lineEdit_28->setText(QString::number(pom,'.',2));
                QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
                QCoreApplication::postEvent (this, event);
                osvezi(ui->lineEdit_29->text().toInt());
                break;
            }
        }
    }
    else
    {
        QMessageBox::critical(this, "POPIS", "Unesite sifru!" , QMessageBox::Abort, QMessageBox::NoButton);
    }
}

void FormaPopis::on_pushButton_2_clicked()
{
    QSqlQuery query;
    bool postoji = false;
    query.exec("SELECT SifraPopisa FROM POPISOSNOVNO");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->spinBox->value())
        {
            postoji=true;
            break;
        }
    }
    if(postoji)
    {
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci where brpopisa = :brpopisa");
        query.bindValue(":brpopisa",ui->spinBox->value());
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->tableView_6->setModel(model);
        ui->tableView_6->resizeColumnsToContents();
        ui->tableView_6->resizeRowsToContents();
    }

}

void FormaPopis::osvezi(int sif)
{
    QSqlQuery query;
    query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci WHERE SifraProizvoda>? AND SifraProizvoda<? AND brpopisa = ?");
    query.addBindValue(sif-6);
    query.addBindValue(sif+6);
    query.addBindValue(ui->spinBox->value());
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->tableView_6->setModel(model);
    ui->tableView_6->resizeColumnsToContents();
    ui->tableView_6->resizeRowsToContents();
}
