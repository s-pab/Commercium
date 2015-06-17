#ifndef FORMAKOMITENT_H
#define FORMAKOMITENT_H

#include <QMainWindow>

namespace Ui {
class FormaKomitent;
}

class FormaKomitent : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaKomitent(QWidget *parent = 0);
    ~FormaKomitent();

private slots:
    void on_prikazKomitenta_clicked();

    void on_dodajKomitenta_clicked();

    void on_izmenaKomitenta_clicked();

    void on_tabelaKomitenti_doubleClicked(const QModelIndex &index);

    void on_obrisiKomitenta_clicked();

private:
    Ui::FormaKomitent *ui;
};

#endif // FORMAKOMITENT_H
