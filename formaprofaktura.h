#ifndef FORMAPROFAKTURA_H
#define FORMAPROFAKTURA_H

#include <QMainWindow>

namespace Ui {
class FormaProfaktura;
}

class FormaProfaktura : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaProfaktura(QWidget *parent = 0);

     void osvezi();
     void pretraga(QString naziv);
    ~FormaProfaktura();

private slots:
    void on_obrisi_clicked();

    void on_nova_clicked();

    void on_ubaciArtikl_clicked();

    void on_pretragaKupaca_textChanged(const QString &arg1);

    void on_ubaciKupca_clicked();

    void on_pretragaArtikl_textChanged(const QString &arg1);

    void on_izmeni_clicked();

    void on_pUkloniArtikl_clicked();

private:
    Ui::FormaProfaktura *ui;
};

#endif // FORMAPROFAKTURA_H
