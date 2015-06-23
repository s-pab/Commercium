#include "commercium.h"
#include "formalogovanja.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    FormaLogovanja f;
    int p=f.exec();
    if(p==QDialog::Accepted)
    {
        w.showMaximized();
    }
    else
        exit(0);

    //w.showMaximized();
    return a.exec();
}
