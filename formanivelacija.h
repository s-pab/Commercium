#ifndef FORMANIVELACIJA_H
#define FORMANIVELACIJA_H

#include <QMainWindow>

namespace Ui {
class FormaNivelacija;
}

class FormaNivelacija : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaNivelacija(QWidget *parent = 0);
    ~FormaNivelacija();

private:
    Ui::FormaNivelacija *ui;
};

#endif // FORMANIVELACIJA_H
