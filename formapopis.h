#ifndef FORMAPOPIS_H
#define FORMAPOPIS_H

#include <QMainWindow>

namespace Ui {
class FormaPopis;
}

class FormaPopis : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaPopis(QWidget *parent = 0);
    ~FormaPopis();

private slots:
    //void suma();
    void osvezi(int sif);
    void on_pushButton_clicked();

    void on_lineEdit_29_returnPressed();

    void on_pushButton_2_clicked();

private:
    Ui::FormaPopis *ui;
    QString cena,kol;
};

#endif // FORMAPOPIS_H
