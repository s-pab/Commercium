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
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::FormaNalogIsplata *ui;
    void writeisplata();
};

#endif // FORMANALOGISPLATA_H
