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

void FormaPopis::on_noviPopis_clicked()
{
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT SifraPopisa FROM POPISOSNOVNO");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->brojPopisa1->value())
        {
            postoji=true;
            break;
        }
    }
    if(!postoji)
    {
        query.prepare("INSERT INTO POPISOSNOVNO (SIFRAPOPISA,DATUM,UKUPNO) VALUES (:SIFRA,:DATUM,'0,00')");
        query.bindValue(":SIFRA",ui->brojPopisa1->value());
        QDate Datum = ui->datumPopisa->date();
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
            query2.bindValue(":BRPOPISA",ui->brojPopisa1->value());
            query2.exec();
        }
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci WHERE brpopisa = :brpopisa");
        query.bindValue(":brpopisa",ui->brojPopisa1->value());
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->tabelaArtikala->setModel(model);
        ui->tabelaArtikala->resizeColumnsToContents();
        ui->tabelaArtikala->resizeRowsToContents();
    }
}

void FormaPopis::on_sifra_returnPressed()
{
    if(!ui->sifra->text().isEmpty())
    {
        QSqlQuery query;
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci WHERE brpopisa = :brpopisa");
        query.bindValue(":brpopisa",ui->brojPopisa1->value());
        query.exec();
        while(query.next())
        {
            int sifra = query.value(0).toInt();
            if(sifra==ui->sifra->text().toInt())
            {
                ui->naziv->setText(query.value(1).toString());
                double pom = query.value(3).toDouble();
                ui->kolicina->setText(QString::number(pom,'.',2));
                kol=ui->kolicina->text();

                ui->cena->setText(query.value(2).toString());
                cena=ui->cena->text();
                pom=query.value(4).toDouble();
                ui->suma->setText(QString::number(pom,'.',2));
                QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
                QCoreApplication::postEvent (this, event);
                osvezi(ui->sifra->text().toInt());
                break;
            }
        }
    }
    else
    {
        QMessageBox::critical(this, "POPIS", "Unesite sifru!" , QMessageBox::Abort, QMessageBox::NoButton);
    }
}

void FormaPopis::on_azuriranjePopisa_clicked()
{
    QSqlQuery query;
    bool postoji = false;
    query.exec("SELECT SifraPopisa FROM POPISOSNOVNO");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->brojPopisa1->value())
        {
            postoji=true;
            break;
        }
    }
    if(postoji)
    {
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci where brpopisa = :brpopisa");
        query.bindValue(":brpopisa",ui->brojPopisa1->value());
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->tabelaArtikala->setModel(model);
        ui->tabelaArtikala->resizeColumnsToContents();
        ui->tabelaArtikala->resizeRowsToContents();
        suma();
    }

}

void FormaPopis::osvezi(int sif)
{
    QSqlQuery query;
    query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci WHERE SifraProizvoda>? AND SifraProizvoda<? AND brpopisa = ?");
    query.addBindValue(sif-6);
    query.addBindValue(sif+6);
    query.addBindValue(ui->brojPopisa1->value());
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->tabelaArtikala->setModel(model);
    ui->tabelaArtikala->resizeColumnsToContents();
    ui->tabelaArtikala->resizeRowsToContents();
}

void FormaPopis::on_naziv_textChanged(const QString &arg1)
{
    QSqlQuery query;
    query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM PopisPodaci WHERE brpopisa = ? AND NazivProizvoda LIKE '%'+?+'%'");
    query.addBindValue(ui->brojPopisa1->value());
    query.addBindValue(arg1);
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->tabelaArtikala->setModel(model);
    ui->tabelaArtikala->resizeColumnsToContents();
    ui->tabelaArtikala->resizeRowsToContents();
}

void FormaPopis::on_tabelaArtikala_doubleClicked(const QModelIndex &index)
{
    ui->sifra->setFocus();
    int row = index.row();
    ui->sifra->setText(index.sibling(row, 0).data().toString());

    on_sifra_returnPressed();
}

void FormaPopis::suma()
{
    QSqlQuery query;
    query.prepare("SELECT Ukupno FROM PopisPodaci WHERE brpopisa = :brpopisa");
    query.bindValue(":brpopisa",ui->brojPopisa1->value());
    query.exec();
    double suma = 0;
    while(query.next())
    {
        suma+=query.value(0).toDouble();
    }
    QString pomS=QString::number(suma,'.',2);
    pomS.replace('.',',');
    ui->ukupnaVrednost->setText(pomS);
}

void FormaPopis::on_kolicina_returnPressed()
{
    QSqlQuery query;
    query.prepare("UPDATE PopisPodaci SET Kolicina=:kol, Ukupno=:sum WHERE SifraProizvoda=:id AND brpopisa = :brpopisa");
    query.bindValue(":kol",ui->kolicina->text().replace('.',','));
    double pom=ui->kolicina->text().toDouble()*ui->cena->text().toDouble();
    QString pomS=QString::number(pom,'.',2);
    pomS.replace('.',',');
    ui->suma->setText(pomS);
    query.bindValue(":sum",ui->suma->text());
    pomS.replace(',','.');
    ui->suma->setText(pomS);
    query.bindValue(":id",ui->sifra->text().toInt());
    query.bindValue(":brpopisa",ui->brojPopisa1->value());
    if(query.exec()&&kol!=ui->kolicina->text())
    {
        ui->izmenePrikaz->addItem(ui->sifra->text()+". "+ui->naziv->text()+" Količina: "+kol+"->"+ui->kolicina->text());
        kol=ui->kolicina->text();
    }
    QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
    QCoreApplication::postEvent (this, event);
    suma();
    osvezi(ui->sifra->text().toInt());
}

void FormaPopis::on_cena_returnPressed()
{
    if(ui->cena->isModified())
    {
        QSqlQuery query;
        query.prepare("UPDATE PopisPodaci SET ProdajnaCena=:cena WHERE Sifra=:id AND BrPopisa=:brpopisa");
        QString pomS=QString::number(ui->cena->text().toDouble(),'.',2);
        pomS.replace('.',',');
        query.bindValue(":cena",pomS);
        query.bindValue(":id",ui->sifra->text().toInt());
        query.bindValue(":brpopisa",ui->brojPopisa1->value());
        if(query.exec())
        {
            ui->izmenePrikaz->addItem(ui->sifra->text()+". "+ui->naziv->text()+" Cena:"+cena+"->"+ui->cena->text());
            cena=ui->cena->text();
        }
        on_kolicina_returnPressed();
    }
    else
    {
        QKeyEvent *event = new QKeyEvent ( QEvent::KeyPress, Qt::Key_Tab, Qt::NoModifier);
        QCoreApplication::postEvent (this, event);
    }
}
