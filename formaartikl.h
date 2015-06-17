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
    void on_prikaziArtikle_clicked();

    void on_uveziArtikle_clicked();

private:
    Ui::FormaArtikl *ui;
};

#endif // FORMAARTIKL_H
