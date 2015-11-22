#include <QtGui/QApplication>
#include "chttpauth.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CHttpAuth w;
    w.show();

    return a.exec();
}
