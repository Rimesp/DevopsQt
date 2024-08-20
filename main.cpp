#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QTime>

int main(int argc, char *argv[])
{
    QTime timer;
    timer.start();

    QApplication a(argc, argv);

    // Debug start
    qDebug() << "Application started at" << timer.elapsed() << "ms";

    // Check for a quick test flag
    for (int i = 0; i < argc; ++i) {
        if (QString(argv[i]) == "--quick-test") {
            qDebug() << "Quick test mode. Exiting immediately at" << timer.elapsed() << "ms";
            return 0;
        }
    }

    // Debug before window
    qDebug() << "MainWindow creation at" << timer.elapsed() << "ms";

    // Normal application execution
    MainWindow w;
    w.show();

    qDebug() << "Application exec at" << timer.elapsed() << "ms";
    return a.exec();
}
