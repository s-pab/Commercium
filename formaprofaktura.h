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
    ~FormaProfaktura();

private:
    Ui::FormaProfaktura *ui;
};

#endif // FORMAPROFAKTURA_H