#ifndef FORMATREBOVANJE_H
#define FORMATREBOVANJE_H

#include <QMainWindow>

namespace Ui {
class FormaTrebovanje;
}

class FormaTrebovanje : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaTrebovanje(QWidget *parent = 0);
    ~FormaTrebovanje();

private:
    Ui::FormaTrebovanje *ui;
};

#endif // FORMATREBOVANJE_H
