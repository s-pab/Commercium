#ifndef FORMALOGOVANJA_H
#define FORMALOGOVANJA_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>

namespace Ui {
class FormaLogovanja;
}

class FormaLogovanja : public QDialog
{
    Q_OBJECT
private:
        QSqlDatabase db;

public:
    explicit FormaLogovanja(QWidget *parent = 0);
    ~FormaLogovanja();
    void connect();

private slots:
    void on_bPrijava_clicked();

private:
    Ui::FormaLogovanja *ui;
};

#endif // FORMALOGOVANJA_H
