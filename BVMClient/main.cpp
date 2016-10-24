#include "widget.h"
#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;
  w.resize(1080,1920);
    w.resize(w.size()*0.96);

    w.show();






    return a.exec();
}
