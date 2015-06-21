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



    void on_pretraga_textChanged(const QString &arg1);

    void on_ubaci_clicked();

private:
    Ui::FormaProfaktura *ui;
};

#endif // FORMAPROFAKTURA_H
