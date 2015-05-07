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

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
