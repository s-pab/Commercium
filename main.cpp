#include "commercium.h"
#include "formalogovanja.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormaLogovanja w;
    w.show();
   // MainWindow w;
    //w.showMaximized();
    //w.show();

    return a.exec();
}
