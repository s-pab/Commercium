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
    void on_pushButton_3_clicked();

private:
    Ui::FormaKalkulacije *ui;
};

#endif // FORMAKALKULACIJE_H
