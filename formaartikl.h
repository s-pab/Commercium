#ifndef FORMAARTIKL_H
#define FORMAARTIKL_H

#include <QMainWindow>

namespace Ui {
class FormaArtikl;
}

class FormaArtikl : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaArtikl(QWidget *parent = 0);
    ~FormaArtikl();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::FormaArtikl *ui;
};

#endif // FORMAARTIKL_H
