#ifndef FORMAPRIJEMNICA_H
#define FORMAPRIJEMNICA_H

#include <QMainWindow>

namespace Ui {
class FormaPrijemnica;
}

class FormaPrijemnica : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaPrijemnica(QWidget *parent = 0);
    ~FormaPrijemnica();

private:
    Ui::FormaPrijemnica *ui;
};

#endif // FORMAPRIJEMNICA_H
