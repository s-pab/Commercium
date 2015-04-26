#ifndef FORMATREBOVANJE
#define FORMATREBOVANJE

#include <QMainWindow>

namespace Uii {
class FormaTrebovanje;
}

class FormaTrebovanje : public QMainWindow
{
    Q_OBJECT

public:
    explicit FormaTrebovanje(QWidget *parent = 0);
    ~FormaTrebovanje();

private:
    Uii::FormaTrebovanje *uii;
};

#endif // FORMATREBOVANJE

