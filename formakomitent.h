#ifndef FORMAKOMITENT_H
#define FORMAKOMITENT_H

#include <QMainWindow>

namespace Ui {
class FormaKomitent;
}

class FormaKomitent : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaKomitent(QWidget *parent = 0);
    ~FormaKomitent();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

private:
    Ui::FormaKomitent *ui;
};

#endif // FORMAKOMITENT_H
