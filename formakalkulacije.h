#ifndef FORMAKALKULACIJE_H
#define FORMAKALKULACIJE_H

#include <QMainWindow>

namespace Ui {
class FormaKalkulacije;
}

class FormaKalkulacije : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaKalkulacije(QWidget *parent = 0);
    ~FormaKalkulacije();

private slots:

    void on_ubaciKupca_clicked();

    void on_pretragaKupaca_textChanged(const QString &arg1);

    void on_pretragaArtikl_textChanged(const QString &arg1);

    void on_ubaciArtikl_clicked();

private:
    Ui::FormaKalkulacije *ui;
};

#endif // FORMAKALKULACIJE_H
