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

private:
    Ui::FormaFaktura *ui;
};

#endif // FORMAFAKTURA_H
