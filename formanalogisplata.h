#ifndef FORMANALOGISPLATA_H
#define FORMANALOGISPLATA_H

#include <QMainWindow>

namespace Ui {
class FormaNalogIsplata;
}

class FormaNalogIsplata : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaNalogIsplata(QWidget *parent = 0);
    ~FormaNalogIsplata();

private slots:
    void on_snimiIsplatnicu_clicked();

    void on_ocistiIsplatnicu_clicked();

private:
    Ui::FormaNalogIsplata *ui;
    void writeisplata();
};

#endif // FORMANALOGISPLATA_H
