#ifndef FORMANALOGUPLATA_H
#define FORMANALOGUPLATA_H

#include <QMainWindow>

namespace Ui {
class FormaNalogUplata;
}

class FormaNalogUplata : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaNalogUplata(QWidget *parent = 0);
    ~FormaNalogUplata();

private slots:
    void on_snimiUplatnicu_clicked();

    void on_ocistiUplatnicu_clicked();

private:
    Ui::FormaNalogUplata *ui;
    void writeuplata();
};

#endif // FORMANALOGUPLATA_H
