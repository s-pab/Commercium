#ifndef FORMATREBOVANJE_H
#define FORMATREBOVANJE_H

#include <QMainWindow>

namespace Ui {
class FormaTrebovanje;
}

class FormaTrebovanje : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaTrebovanje(QWidget *parent = 0);
    ~FormaTrebovanje();
    void pretraga(QString naziv);
    void osvezi();

private slots:

    void on_pretragaKomitenata_textChanged(const QString &arg1);

    void on_pretragaArtikala_textChanged(const QString &arg1);

    void on_nova_clicked();

    void on_izmeni_clicked();

    void on_obrisi_clicked();

    void on_ubaciKomitenta_clicked();

    void on_ubaciArtikl_clicked();

    void on_izbaciArtikl_clicked();

private:
    Ui::FormaTrebovanje *ui;
};

#endif // FORMATREBOVANJE_H
