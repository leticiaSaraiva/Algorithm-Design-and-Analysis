#include "mainwindowcontroller.hpp"
#include "mainwindow.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    MainWindowController mwc(w);

    w.show();

    return a.exec();
}
