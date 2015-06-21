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
}

FormaKalkulacije::~FormaKalkulacije()
{
    delete ui;
}



void FormaKalkulacije::on_ubaciKupca_clicked()
{

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
