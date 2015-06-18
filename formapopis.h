#ifndef FORMAPOPIS_H
#define FORMAPOPIS_H

#include <QMainWindow>

namespace Ui {
class FormaPopis;
}

class FormaPopis : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaPopis(QWidget *parent = 0);
    ~FormaPopis();

private slots:
    void suma();
    void osvezi(int sif);
    void on_noviPopis_clicked();

    void on_sifra_returnPressed();

    void on_azuriranjePopisa_clicked();

    void on_naziv_textChanged(const QString &arg1);

    void on_tabelaArtikala_doubleClicked(const QModelIndex &index);

    void on_kolicina_returnPressed();

    void on_cena_returnPressed();

private:
    Ui::FormaPopis *ui;
    QString cena,kol;
};

#endif // FORMAPOPIS_H
