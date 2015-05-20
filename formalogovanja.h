#ifndef FORMALOGOVANJA_H
#define FORMALOGOVANJA_H

#include <QDialog>

namespace Ui {
class FormaLogovanja;
}

class FormaLogovanja : public QDialog
{
    Q_OBJECT

public:
    explicit FormaLogovanja(QWidget *parent = 0);
    ~FormaLogovanja();

private:
    Ui::FormaLogovanja *ui;
};

#endif // FORMALOGOVANJA_H
