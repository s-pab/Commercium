#ifndef FORMALOGOVANJA_H
#define FORMALOGOVANJA_H

#include <QMainWindow>

namespace Ui {
class FormaLogovanja;
}

class FormaLogovanja : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaLogovanja(QWidget *parent = 0);
    ~FormaLogovanja();

private slots:
    void on_Otkazi_clicked();

private:
    Ui::FormaLogovanja *ui;
};

#endif // FORMALOGOVANJA_H
