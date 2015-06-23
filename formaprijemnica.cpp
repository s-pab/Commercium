#include "formaprijemnica.h"
#include "ui_formaprijemnica.h"


#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QTextStream>

#include <QDateTime>

FormaPrijemnica::FormaPrijemnica(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaPrijemnica)
{
    ui->setupUi(this);
    osvezi();
}

FormaPrijemnica::~FormaPrijemnica()
{
    delete ui;
}
void FormaPrijemnica::osvezi()
{
    QSqlQuery query;
    //query.prepare("SELECT sifraProizvoda,nazivProizvoda,prodajnaCena,jedinicaMere,kolicina FROM OtpremnicaPodaci WHERE brOtpremnice = :bro");
    query.prepare("SELECT * FROM PrijemnicaPodaci WHERE brPrijemice = :brp");
    //query.bindValue(":brp",ui->brojPrijemnice->text().toInt());
    query.bindValue(":brp",1);
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikaz->verticalHeader()->hide();
    ui->prikaz->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->prikaz->setModel(model);
    ui->prikaz->resizeColumnsToContents();
    ui->prikaz->resizeRowsToContents();
}
void FormaPrijemnica::pretraga(QString naziv)
{
    QSqlQuery query;
    if(naziv == "")
        query.prepare("SELECT sifraProizvoda,nazivProizvoda,nabavnaCena,jedinicaMere,kolicina FROM Artikl");
    else
    {
        query.prepare("SELECT sifraProizvoda,nazivProizvoda,prodajnaCena,jedinicaMere,kolicina FROM Artikl WHERE nazivProizvoda LIKE '%'+?+'%'");
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

void FormaPrijemnica::on_ubaciKomitenta_clicked()
{
    QModelIndex index = ui->prikazKomitenta->currentIndex();
    int row = index.row();
    ui->komitent->setText(index.sibling(row,0).data().toString());
}

void FormaPrijemnica::on_ubaciArtikl_clicked()
{
    if(ui->brojPrijemnice->text()=="")
        return;
    QSqlQuery query2;
    QModelIndex index = ui->prikazArtikla->currentIndex();
    int row = index.row();
    query2.prepare("INSERT INTO PrijemnicaPodaci (brPrijemnice,SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA,JEDINICAMERE,KOLICINA) VALUES (:brPrijemnice,:SIFRA,:NAZIV,:CENA,:JEDINICAMERE,:KOLICINA)");
    query2.bindValue(":brPrijemnice",ui->brojPrijemnice->text().toInt());
    query2.bindValue(":SIFRA",index.sibling(row,0).data().toInt());
    query2.bindValue(":NAZIV",index.sibling(row,1).data().toString());
    query2.bindValue(":CENA",index.sibling(row,2).data().toInt());
    query2.bindValue(":JEDINICAMERE",index.sibling(row,3).data().toString());
    query2.bindValue(":KOLICINA",index.sibling(row,4).data().toInt());
    query2.exec();
    osvezi();
}

void FormaPrijemnica::on_pretragaKomitenata_textChanged(const QString &arg1)
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

void FormaPrijemnica::on_pretragaArtikala_textChanged(const QString &arg1)
{
    pretraga(arg1);
}

void FormaPrijemnica::on_izbaciArtikl_clicked()
{

}

void FormaPrijemnica::on_nova_clicked()
{
    if(ui->brojPrijemnice->text()=="")
    {
        QMessageBox msg;
        msg.setText("Unesite broj prijemnice");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        return;
    }
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT sifraPrijemnice FROM PrijemnicaOsnovno");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->brojPrijemnice->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(postoji)
    {
        QMessageBox msg;
        msg.setText("Prijemnica pod tom šifrom već postoji");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
    }
    else
    {
        query.prepare("INSERT INTO PrijemnicaOsnovno (sifraPrijemnice,datum,komitent,ukupnaVrednost) VALUES (:SIFRA,:DATUM,:KOMITENT,:UKUPNAVREDNOST)");
        query.bindValue(":SIFRA",ui->brojPrijemnice->text().toInt());
        QDate Datum = ui->datum->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":KOMITENT",ui->komitent->text().toInt());
        query.bindValue(":UKUPNAVREDNOST",ui->ukupnaVrednost->text().toDouble());
        query.exec();
        osvezi();
    }
}

void FormaPrijemnica::on_izmeni_clicked()
{

}

void FormaPrijemnica::on_obrisi_clicked()
{

}
