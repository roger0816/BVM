#include "widget.h"
#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;

    w.resize(w.size()/10*4);
  //  w.resize(1920,1080);

    w.show();

    return a.exec();
}
