#include "commercium.h"
#include "formalogovanja.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormaLogovanja f;
    int p=f.exec();
    MainWindow w;
    if(p==QDialog::Accepted)
    {
        w.showMaximized();
    }
    else
        exit(0);

    return a.exec();
}
