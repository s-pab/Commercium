#include "formafaktura.h"
#include "ui_formafaktura.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QTextStream>

#include <QDateTime>

FormaFaktura::FormaFaktura(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaFaktura)
{
    ui->setupUi(this);
    pretraga("");

}

FormaFaktura::~FormaFaktura()
{
    delete ui;
}


void FormaFaktura::on_obrisi_clicked()
{
    QSqlQuery query;
    query.prepare("DELETE FROM FakturePodaci WHERE brFakture=:SIFRA");
    query.bindValue(":SIFRA",ui->racunBroj->text().toInt());
    query.exec();
    query.prepare("DELETE FROM FaktureOsnovno WHERE sifraFakture=:SIFRA");
    query.bindValue(":SIFRA",ui->racunBroj->text().toInt());
    query.exec();

    osvezi();
}

void FormaFaktura::on_nova_clicked()
{
    if(ui->racunBroj->text()=="")
    {
        QMessageBox msg;
        msg.setText("Unesite broj fakture");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        return;
    }
    QSqlQuery query;
    bool postoji = false;
    query.exec("SELECT sifraFakture FROM FaktureOsnovno");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->racunBroj->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(postoji)
    {
        QMessageBox msg;
        msg.setText("Faktura pod tom šifrom već postoji");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
    }
    else
    {
        query.prepare("INSERT INTO FaktureOsnovno (sifraFakture,datum,valuta) VALUES (:SIFRA,:DATUM,:VALUTA)");
        query.bindValue(":SIFRA",ui->racunBroj->text().toInt());
        QDate Datum = ui->datumPlacanja->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":VALUTA",ui->valuta->text().toInt());
        query.exec();
     /* query.exec("SELECT SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA FROM Artikl");
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina,Ukupno FROM FakturePodaci WHERE brFakture = :brFakture");
        query.bindValue(":brFakture",ui->racunBroj->text().toInt());
        query.exec();
        QSqlQueryModel* model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->prikaz->setModel(model);
        ui->prikaz->resizeColumnsToContents();
        ui->prikaz->resizeRowsToContents();*/
    }
}

void FormaFaktura::pretraga(QString naziv)
{
    QSqlQuery query;
    if(naziv == "")
        query.prepare("SELECT sifraProizvoda,nazivProizvoda,ProdajnaCena FROM Artikl");
    else
    {
        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena FROM Artikl WHERE NazivProizvoda LIKE '%'+?+'%'");
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

void FormaFaktura::on_lePretraga_textChanged(const QString &arg1)
{
    pretraga(arg1);
}

void FormaFaktura::on_pbUbaci_clicked()
{
    QSqlQuery query;
    bool postoji = false;
    query.exec("SELECT sifraFakture FROM FaktureOsnovno");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->racunBroj->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(!postoji)
    {
        QMessageBox msg;
        msg.setText("Faktura pod tom šifrom ne postoji u bazi");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
    }
    if(ui->racunBroj->text()=="")
    {
        QMessageBox msg;
        msg.setText("Unesite broj fakture");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        return;
    }
    if(ui->leKolicina->text()=="")
    {
        QMessageBox msg;
        msg.setText("Unesite količinu");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
        return;
    }
    QSqlQuery query2;
    QModelIndex index = ui->twArtikli->currentIndex();
    int row = index.row();
    /*ui->sifra->setText(index.sibling(row,0).data().toString());
    ui->naziv->setText(index.sibling(row,1).data().toString());
    ui->ulica->setText(index.sibling(row,2).data().toString());
    ui->mesto->setText(index.sibling(row,3).data().toString());
    ui->pib->setText(index.sibling(row,4).data().toString());
    ui->tekuciracun->setText(index.sibling(row,5).data().toString());*/


    query2.prepare("INSERT INTO FakturePodaci (SIFRAPROIZVODA,NAZIVPROIZVODA,PRODAJNACENA,KOLICINA,brFakture) VALUES (:SIFRA,:NAZIV,:CENA,:KOLICINA,:brFakture)");
    query2.bindValue(":SIFRA",index.sibling(row,0).data().toInt());
    query2.bindValue(":NAZIV",index.sibling(row,1).data().toString());
    query2.bindValue(":CENA",index.sibling(row,2).data().toInt());
    query2.bindValue(":KOLICINA",ui->leKolicina->text().toInt());
    query2.bindValue(":brFakture",ui->racunBroj->text().toInt());
    query2.exec();
    osvezi();
}

void FormaFaktura::osvezi()
{
    QSqlQuery query;
    query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina FROM FakturePodaci WHERE brFakture = :brf");
    //query.prepare("SELECT * FROM FakturePodaci WHERE brFakture = :brf");
    query.bindValue(":brf",ui->racunBroj->text().toInt());
    query.exec();
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikaz->verticalHeader()->hide();
    ui->prikaz->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->prikaz->setModel(model);
    ui->prikaz->resizeColumnsToContents();
    ui->prikaz->resizeRowsToContents();
}

void FormaFaktura::on_leKupacPretraga_textChanged(const QString &arg1)
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

void FormaFaktura::on_pbUbaciKupca_clicked()
{
    QModelIndex index = ui->twKupac->currentIndex();
    int row = index.row();
    ui->sifra->setText(index.sibling(row,0).data().toString());
    ui->kupac->setText(index.sibling(row,1).data().toString());
    ui->mesto->setText(index.sibling(row,3).data().toString());
    ui->PIB->setText(index.sibling(row,4).data().toString());


    //query2.bindValue(":SIFRA",index.sibling(row,0).data().toInt());

}

void FormaFaktura::on_izmeni_clicked()
{
    QSqlQuery query;
    QSqlQuery query2;
    bool postoji = false;
    query.exec("SELECT sifraFakture FROM FaktureOsnovno");
    if(ui->racunBroj->text()!="")
    while(query.next())
    {
        if(query.value(0).toInt() == ui->racunBroj->text().toInt())
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
        msg.setText("Nepostojeća faktura");
        msg.setWindowTitle("Greška");
        msg.addButton(QMessageBox::Ok);
        msg.exec();
    }
    else
    {
        query.prepare("SELECT * FROM FaktureOsnovno WHERE sifraFakture=:SIFRA");
        query.bindValue(":SIFRA",ui->racunBroj->text().toInt());
        query.exec();
        if(query.next())
        {
            //ui->racunBroj->setText(query.value(0).toString());
            ui->datumRacuna->setDate(query.value(2).toDate());
            query2.prepare("SELECT sifra,naziv,ulica,mesto,pib,tekuciRacun FROM Komitenti WHERE sifra=:SIFRAKOM");
            query2.bindValue(":SIFRAKOM",query.value(5).toInt());
            query2.exec();
            if(query2.next())
            {
                ui->sifra->setText(query2.value(0).toString());
                ui->PIB->setText(query2.value(4).toString());
                ui->kupac->setText(query2.value(1).toString());
                ui->mesto->setText(query2.value(3).toString());
            }
        }

        query.prepare("SELECT SifraProizvoda,NazivProizvoda,ProdajnaCena,Kolicina FROM FakturePodaci WHERE brFakture = :brFakture");
        query.bindValue(":brFakture",ui->racunBroj->text().toInt());
        query.exec();
        osvezi();
    }
}

void FormaFaktura::on_pbUkloniArtikl_clicked()
{
    QSqlQuery query;
    QModelIndex index = ui->prikaz->currentIndex();
    int row = index.row();
    int sifra = index.sibling(row,0).data().toInt();

    query.prepare("DELETE FROM FakturePodaci WHERE sifraProizvoda = :sp AND brFakture = :bf");
    query.bindValue(":sp",sifra);
    query.bindValue(":bf",ui->racunBroj->text().toInt());
    query.exec();

    osvezi();
}

void FormaFaktura::on_racunBroj_returnPressed()
{
    on_izmeni_clicked();
}
