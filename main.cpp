#include "mainwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Check for a quick test flag
    for (int i = 0; i < argc; ++i) {
        if (QString(argv[i]) == "--quick-test") {
            qDebug() << "Quick test mode. Exiting immediately.";
            return 0;
        }
    }

    // Normal application execution
    MainWindow w;
    w.show();
    return a.exec();
}
