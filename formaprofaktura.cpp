#include "formaprofaktura.h"
#include "ui_formaprofaktura.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QTextStream>

#include <QDateTime>

FormaProfaktura::FormaProfaktura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaProfaktura)
{
    ui->setupUi(this);
}

FormaProfaktura::~FormaProfaktura()
{
    delete ui;
}

void FormaProfaktura::on_obrisi_clicked()
{
    ui->sifraKupca->clear();
    ui->PIB->clear();
    ui->datumPredracuna->clear();
    ui->kupac->clear();
    ui->brojPredracuna->clear();
    ui->mesto->clear();
    ui->mestoIzdavanja->clear();
    ui->valuta->clear();
    ui->prikaz->clearFocus();
}

void FormaProfaktura::on_nova_clicked()
{
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT sifraFakture FROM ProfaktureOsnovno");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->brojPredracuna->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(!postoji)
    {
        query.prepare("INSERT INTO ProfaktureOsnovno (sifraProfakture,datum,valuta) VALUES (:SIFRA,:DATUM,:VALUTA)");
        query.bindValue(":SIFRA",ui->brojPredracuna->text().toInt());
        QDate Datum = ui->datumPredracuna->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":VALUTA",ui->valuta->text().toInt());
        query.exec();
        query.exec("SELECT SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA FROM Artikl");
        while (query.next()) {
            query2.prepare("INSERT INTO ProfakturePodaci (SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA,KOLICINA,brProfakture) VALUES (:SIFRA,:NAZIV,:CENA,:KOLICINA,:UKUPNO,:brProfakture)");
            query2.bindValue(":SIFRA",query.value(0));
            query2.bindValue(":NAZIV",query.value(1));
            query2.bindValue(":CENA",query.value(2));
            query2.bindValue(":KOLICINA",0);
            query2.bindValue(":brProfakture",ui->brojPredracuna->text().toInt());
            query2.exec();
        }
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM FakturePodaci WHERE brProfakture = :brProfakture");
        query.bindValue(":brFakture",ui->brojPredracuna->text().toInt());
        query.exec();
        osvezi();
    }
}
void FormaProfaktura::pretraga(QString naziv)
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
    ui->twArtikli->verticalHeader()->hide();
    ui->twArtikli->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->twArtikli->setModel(model);
    ui->twArtikli->resizeColumnsToContents();
    ui->twArtikli->resizeRowsToContents();
}


void FormaProfaktura::osvezi()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ProfakturePodaci WHERE brProfakture = :brpf");
    query.bindValue(":brpf",ui->brojPredracuna->text().toInt());
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikaz->setModel(model);
    ui->prikaz->resizeColumnsToContents();
    ui->prikaz->resizeRowsToContents();
}

void FormaProfaktura::on_ubaciArtikl_clicked()
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


    query2.prepare("INSERT INTO ProfakturePodaci (SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA,KOLICINA,brProfakture) VALUES (:SIFRA,:NAZIV,:CENA,:KOLICINA,:brProfakture)");
    query2.bindValue(":SIFRA",index.sibling(row,0).data().toInt());
    query2.bindValue(":NAZIV",index.sibling(row,1).data().toString());
    query2.bindValue(":CENA",index.sibling(row,2).data().toInt());
    query2.bindValue(":KOLICINA",index.sibling(row,3).data().toInt());
    query2.bindValue(":brProfakture",ui->brojPredracuna->text().toInt());
    query2.exec();
    osvezi();
}


void FormaProfaktura::on_pretragaKupaca_textChanged(const QString &arg1)
{

    QSqlQuery query;
    query.prepare("SELECT sifra,naziv,ulica,mesto,pib,tekuciRacun FROM Komitenti WHERE naziv LIKE '%'+?+'%'");
    query.addBindValue(arg1);
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->twKupac->verticalHeader()->hide();
    ui->twKupac->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->twKupac->setModel(model);
    ui->twKupac->resizeColumnsToContents();
    ui->twKupac->resizeRowsToContents();
}

void FormaProfaktura::on_ubaciKupca_clicked()
{
    QModelIndex index = ui->twKupac->currentIndex();
    int row = index.row();
    ui->sifraKupca->setText(index.sibling(row,0).data().toString());
    ui->kupac->setText(index.sibling(row,1).data().toString());
    ui->mesto->setText(index.sibling(row,3).data().toString());
    ui->PIB->setText(index.sibling(row,4).data().toString());
}

void FormaProfaktura::on_pretragaArtikl_textChanged(const QString &arg1)
{
    pretraga(arg1);
}

void FormaProfaktura::on_izmeni_clicked()
{
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT sifraProfakture FROM ProfaktureOsnovno");
    if(ui->brojPredracuna->text()!="")
    while(query.next())
    {
        if(query.value(0).toInt() == ui->brojPredracuna->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    else
        postoji=false;
    if(!postoji)
    {
        QMessageBox msg;
        msg.setText("Nepostojeća profaktura");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
    }
    else
    {
        query.prepare("INSERT INTO ProfaktureOsnovno (sifraProfakture,datum,valuta) VALUES (:SIFRA,:DATUM,:VALUTA)");
        query.bindValue(":SIFRA",ui->brojPredracuna->text().toInt());
        QDate Datum = ui->datumPredracuna->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":VALUTA",ui->valuta->text().toInt());
        query.exec();
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM ProfakturePodaci WHERE brProfakture = :brProfakture");
        query.bindValue(":brProfakture",ui->brojPredracuna->text().toInt());
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->prikaz->setModel(model);
        ui->prikaz->resizeColumnsToContents();
        ui->prikaz->resizeRowsToContents();
    }
}
