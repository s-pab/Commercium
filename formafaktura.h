#ifndef FORMAFAKTURA_H
#define FORMAFAKTURA_H

#include <QMainWindow>

namespace Ui {
class FormaFaktura;
}

class FormaFaktura : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaFaktura(QWidget *parent = 0);
    void pretraga(QString naziv);
    void osvezi();
    ~FormaFaktura();

private slots:

    void on_obrisi_clicked();

    void on_nova_clicked();

    void on_lePretraga_textChanged(const QString &arg1);

    void on_pbUbaci_clicked();

private:
    Ui::FormaFaktura *ui;
};

#endif // FORMAFAKTURA_H
