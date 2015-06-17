#ifndef FORMAOTPREMNICA_H
#define FORMAOTPREMNICA_H

#include <QMainWindow>

namespace Ui {
class FormaOtpremnica;
}

class FormaOtpremnica : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaOtpremnica(QWidget *parent = 0);
    ~FormaOtpremnica();

private slots:
    void on_obrisi_clicked();

private:
    Ui::FormaOtpremnica *ui;
};

#endif // FORMAOTPREMNICA_H
