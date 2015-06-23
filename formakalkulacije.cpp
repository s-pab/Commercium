#include "formakalkulacije.h"
#include "ui_formakalkulacije.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QTimer>

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

#include <QTextStream>

#include <QDateTime>

FormaKalkulacije::FormaKalkulacije(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FormaKalkulacije)
{
    ui->setupUi(this);
    ui->groupBox_2->setEnabled(false);
    ui->datum->setDate(QDate::currentDate());
    on_pretragaArtikl_textChanged("");
    on_pretragaKupaca_textChanged("");
    ui->groupBox_3->setEnabled(false);
}
FormaKalkulacije::~FormaKalkulacije()
{
    delete ui;
}



void FormaKalkulacije::on_ubaciKupca_clicked()
{
    QModelIndex kupac = ui->twKupac->currentIndex();
    int red = kupac.row();
    ui->komitentS->setValue(kupac.sibling(red,0).data().toInt());
    ui->groupBox_4->setVisible(false);
}

void FormaKalkulacije::on_pretragaKupaca_textChanged(const QString &arg1)
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

void FormaKalkulacije::on_pretragaArtikl_textChanged(const QString &arg1)
{
    QSqlQuery query;
    QString naziv = arg1;
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

void FormaKalkulacije::on_ubaciArtikl_clicked()
{
    QModelIndex artikl = ui->twArtikli->currentIndex();
    int red = artikl.row();
    ui->sifra->setText(artikl.sibling(red,0).data().toString());
    ui->naziv->setText(artikl.sibling(red,1).data().toString());
}


void FormaKalkulacije::on_azuriranje_clicked()
{
    QSqlQuery query;
    bool postoji = false;
    query.exec("SELECT * FROM KalkulacijeOsnovno");
    while(query.next())
    {
        if(query.value(1).toInt() == ui->brAzuriranja->value())
        {
            postoji=true;
            break;
        }
    }
    if(postoji)
    {
        ui->broj->setValue(ui->brAzuriranja->value());
        ui->datum->setDate(query.value(2).toDate());
        ui->brOtpremnice->setText(query.value(3).toString());
        ui->valuta->setValue(query.value(4).toInt());
        ui->komitentS->setValue(query.value(5).toInt());
        osvezi();
        ui->groupBox->setEnabled(false);
        ui->groupBox_2->setEnabled(true);
        ui->groupBox_3->setEnabled(true);
    }
}
void FormaKalkulacije::on_brisanje_clicked()
{
    QSqlQuery query;
    bool postoji = false;
    query.exec("SELECT * FROM KalkulacijeOsnovno");
    while(query.next())
    {
        if(query.value(1).toInt() == ui->brBrisanje->value())
        {
            postoji=true;
            break;
        }
    }
    if(postoji)
    {
        query.prepare("DELETE FROM KalkulacijeOsnovno WHERE sifraKalkulacije=:SK");
        query.bindValue(":SK",ui->brBrisanje->value());
        query.exec();
        query.prepare("DELETE FROM KalkulacijePodaci WHERE brKalkulacije=:SK");
        query.bindValue(":SK",ui->brBrisanje->value());
        query.exec();
        osvezi();
    }
}

void FormaKalkulacije::on_nova_clicked()
{
    QSqlQuery query;
    bool postoji = false;
    query.exec("SELECT sifraKalkulacije FROM KalkulacijeOsnovno");
    while(query.next())
    {
        if(query.value(0).toInt() == ui->broj->text().toInt())
        {
            postoji=true;
            break;
        }
    }
    if(!postoji)
    {
        query.prepare("INSERT INTO KalkulacijeOsnovno (sifraKalkulacije,datum,brOtpremnice,valuta,komitent) VALUES (:SIFRA,:DATUM,:BROTPREMNICE,:VALUTA,:KOMITENT)");
        query.bindValue(":SIFRA",ui->broj->text().toInt());
        QDate Datum = ui->datum->date();
        query.bindValue(":DATUM",Datum);
        query.bindValue(":BROTPREMNICE",ui->brOtpremnice->text());
        query.bindValue(":VALUTA",ui->valuta->text().toInt());
        query.bindValue(":KOMITENT",ui->komitentS->text().toInt());
        query.exec();
        osvezi();
        ui->groupBox->setEnabled(false);
        ui->groupBox_3->setEnabled(true);
    }
}

void FormaKalkulacije::osvezi()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM KalkulacijePodaci WHERE brKalkulacije = :brk");
    query.bindValue(":brk",ui->broj->text().toInt());
    query.exec();
    double ukupno=0;
    while(query.next())
    {
        ukupno+=query.value(3).toDouble()*query.value(9).toDouble();
    }
    QString ukupnoS = QString::number(ukupno);
    ui->ukupno->setText(ukupnoS);
    QSqlQueryModel* model = new QSqlQueryModel(this);
    model->setQuery(query);
    ui->prikaz->verticalHeader()->hide();
    ui->prikaz->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->prikaz->setModel(model);
    ui->prikaz->resizeColumnsToContents();
    ui->prikaz->resizeRowsToContents();
}

void FormaKalkulacije::on_komitentS_valueChanged(const QString &arg1)
{
    ui->groupBox_4->setVisible(true);
}

void FormaKalkulacije::on_nabavna_valueChanged(double arg1)
{
    double rabat = ui->rabat->value();
    double marza = ui->marza->value();
    double porez = 20;
    double prodajna = ui->prodajna->value();
    if(prodajna!=arg1*(1+porez/100)*(1-rabat/100)*(1+marza/100))
    {
        prodajnaT = arg1*(1+porez/100)*(1-rabat/100)*(1+marza/100);
        ui->prodajna->setValue(prodajnaT);
    }
}

void FormaKalkulacije::on_rabat_valueChanged(double arg1)
{
    rabatT = arg1;
    double nabavna = ui->nabavna->value();
    double marza = ui->marza->value();
    double porez = 20;
    double prodajna = ui->prodajna->value();
    if(prodajna!=nabavna*(1+porez/100)*(1-arg1/100)*(1+marza/100))
    {
        prodajnaT = nabavna*(1+porez/100)*(1-arg1/100)*(1+marza/100);
        ui->prodajna->setValue(prodajnaT);
    }
}

void FormaKalkulacije::on_marza_valueChanged(double arg1)
{
    if(abs(marzaT-arg1)>0.01)
    {
        double rabat = ui->rabat->value();
        double nabavna = ui->nabavna->value();
        double porez = 20;
        double prodajna = ui->prodajna->value();
        if(prodajna!=nabavna*(1+porez/100)*(1-rabat/100)*(1+arg1/100))
        {
            prodajnaT = nabavna*(1+porez/100)*(1-rabat/100)*(1+arg1/100);
            ui->prodajna->setValue(prodajnaT);
        }

    }
}

void FormaKalkulacije::on_prodajna_valueChanged(double arg1)
{
    if(abs(prodajnaT-arg1)>0.01)
    {
        double rabat = ui->rabat->value();
        double nabavna = ui->nabavna->value();
        double marza = ui->marza->value();
        double porez = 20;
        if(marza!=((arg1/(nabavna*(1+porez/100)*(1-rabat/100)))-1)*100)
        {
           marzaT = ((arg1/(nabavna*(1+porez/100)*(1-rabat/100)))-1)*100;
           ui->marza->setValue(((arg1/(nabavna*(1+porez/100)*(1-rabat/100)))-1)*100);
        }
    }

}

void FormaKalkulacije::on_ubaci_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT jedinicaMere FROM artikl WHERE sifraProizvoda=:SIFRA");
    query.bindValue(":SIFRA",ui->sifra->text().toInt());
    query.exec();
    query.next();
    QString jedMer = query.value(0).toString();
    query.prepare("SELECT kategorijaPDV FROM artikl WHERE sifraProizvoda=:SIFRA");
    query.bindValue(":SIFRA",ui->sifra->text().toInt());
    query.exec();
    query.next();
    int brPoreza = query.value(0).toInt();
    query.prepare("SELECT porez FROM porez WHERE brporez=:POREZ");
    query.bindValue(":POREZ",brPoreza);
    query.exec();
    query.next();
    int pdv =  query.value(0).toInt();
    query.prepare("INSERT INTO KalkulacijePodaci (brKalkulacije,sifraProizvoda,nazivProizvoda,prodajnaCena,nabavnaCena,marza,rabat,jedinicaMere,kategorijaPDV,kolicina) VALUES (:SIFRAKALK, :SIFRAPRO, :NAZIV, :PRODAJNA, :NABAVNA, :MARZA, :RABAT, :JEDMER, :PDV, :KOLICINA)");
    query.bindValue(":SIFRAKALK",ui->broj->text().toInt());
    query.bindValue(":SIFRAPRO",ui->sifra->text().toInt());
    query.bindValue(":NAZIV",ui->naziv->text());
    query.bindValue(":PRODAJNA",ui->prodajna->value());
    query.bindValue(":NABAVNA",ui->nabavna->value());
    query.bindValue(":MARZA",ui->marza->value());
    query.bindValue(":RABAT",ui->rabat->value());
    query.bindValue(":JEDMER",jedMer);
    query.bindValue(":PDV",pdv);
    query.bindValue(":KOLICINA",ui->kolicina->text().toDouble());
    query.exec();
    osvezi();

}

void FormaKalkulacije::on_sacuvaj_clicked()
{
    ui->broj->setValue(0);
    ui->datum->setDate(QDate::currentDate());
    ui->brOtpremnice->setText("");
    ui->valuta->setValue(0);
    ui->komitentS->setValue(0);
    osvezi();
    ui->groupBox->setEnabled(true);
    ui->groupBox_4->setVisible(true);
    ui->groupBox_2->setEnabled(false);
}
