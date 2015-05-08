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
    ~FormaFaktura();

private slots:
    void on_pushButton_3_clicked();

private:
    Ui::FormaFaktura *ui;
};

#endif // FORMAFAKTURA_H
