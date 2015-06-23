#ifndef FORMAPRIJEMNICA_H
#define FORMAPRIJEMNICA_H

#include <QMainWindow>

namespace Ui {
class FormaPrijemnica;
}

class FormaPrijemnica : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaPrijemnica(QWidget *parent = 0);
    void osvezi();
    void pretraga(QString naziv);
    ~FormaPrijemnica();

private slots:

    void on_ubaciKomitenta_clicked();

    void on_ubaciArtikl_clicked();

    void on_pretragaKomitenata_textChanged(const QString &arg1);

    void on_pretragaArtikala_textChanged(const QString &arg1);

    void on_izbaciArtikl_clicked();

    void on_nova_clicked();

    void on_izmeni_clicked();

    void on_obrisi_clicked();

private:
    Ui::FormaPrijemnica *ui;
};

#endif // FORMAPRIJEMNICA_H
