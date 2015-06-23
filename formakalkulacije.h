#ifndef FORMAKALKULACIJE_H
#define FORMAKALKULACIJE_H

#include <QMainWindow>

namespace Ui {
class FormaKalkulacije;
}

class FormaKalkulacije : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaKalkulacije(QWidget *parent = 0);
    ~FormaKalkulacije();

private slots:

    void on_ubaciKupca_clicked();

    void on_pretragaKupaca_textChanged(const QString &arg1);

    void on_pretragaArtikl_textChanged(const QString &arg1);

    void on_ubaciArtikl_clicked();

    void on_azuriranje_clicked();

    void on_brisanje_clicked();

    void on_nova_clicked();

    void osvezi();

    void on_komitentS_valueChanged(const QString &arg1);

    void on_nabavna_valueChanged(double arg1);

    void on_rabat_valueChanged(double arg1);

    void on_marza_valueChanged(double arg1);

    void on_prodajna_valueChanged(double arg1);

    void on_ubaci_clicked();

    void on_sacuvaj_clicked();

private:
    Ui::FormaKalkulacije *ui;
    double marzaT;
    double rabatT;
    double nabavnaT;
    double prodajnaT;
};

#endif // FORMAKALKULACIJE_H
