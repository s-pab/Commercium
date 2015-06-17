#ifndef FORMANALOGPRENOS_H
#define FORMANALOGPRENOS_H

#include <QMainWindow>

namespace Ui {
class FormaNalogPrenos;
}

class FormaNalogPrenos : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaNalogPrenos(QWidget *parent = 0);
    ~FormaNalogPrenos();

private slots:
    void on_snimiPrenos_clicked();

    void on_ocistiPrenos_clicked();

private:
    Ui::FormaNalogPrenos *ui;
    void writeprenos();
};

#endif // FORMANALOGPRENOS_H
