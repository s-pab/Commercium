#ifndef FORMAOTPREMNICA_H
#define FORMAOTPREMNICA_H

#include <QMainWindow>
#include <QCompleter>

namespace Ui {
class FormaOtpremnica;
}

class FormaOtpremnica : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaOtpremnica(QWidget *parent = 0);
    ~FormaOtpremnica();
    void pretraga(QString naziv);
    void osvezi();
private slots:

    void on_pretragaKomitenata_textChanged(const QString &arg1);

    void on_pretragaArtikala_textChanged(const QString &arg1);

    void on_nova_clicked();

    void on_ubaciKomitenta_clicked();

    void on_ubaciArtikl_clicked();

private:
    Ui::FormaOtpremnica *ui;
};

#endif // FORMAOTPREMNICA_H
