#include "commercium.h"
#include "formalogovanja.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormaLogovanja f;
    MainWindow w;
    if(f.exec()==QDialog::Accepted)
        w.showMaximized();
    //w.show();

    return a.exec();
}
