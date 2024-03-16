#include "win.h"

#include <QApplication>

int main(int argc, char *argv[]) try
{
    QApplication a(argc, argv);
    Win w;
    w.show();
    return a.exec();
} catch (const std::exception &e) {
    qDebug() << e.what();
}
