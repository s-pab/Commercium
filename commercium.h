#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionZatvori_triggered();

    void on_actionNova_triggered();

    void on_actionKalkulacija_triggered();

    void on_actionTrebovanje_triggered();

    void on_actionPrijemnice_triggered();

    void on_actionOtpremnice_triggered();

    void on_actionFaktura_triggered();

    void on_actionProfaktura_triggered();

    void on_actionNivelacije_triggered();

    void connectToDatabase();

    void on_actionO_nama_triggered();

    void on_action_ablon_uplatnice_triggered();

    void on_actionPopis_triggered();

    void on_actionNalog_za_isplatu_triggered();

    void on_actionNalog_za_prenos_triggered();


    void on_actionZabranjeno_pu_enje_triggered();

    void on_actionUzimite_ra_un_triggered();

    void on_actionZabrana_prodaje_cigareta_osobama_ispod_18_godina_triggered();

    void on_actionZabrana_prodaje_alkohola_osobama_ispod_18_godina_triggered();

    void on_actionPrikaz_informacija_o_artiklima_triggered();

    void on_actionPrikaz_informacija_o_komitentima_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
