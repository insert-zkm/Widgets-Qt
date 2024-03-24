#include "win.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Win w;
    if(w.Failed()) {
        return 0;
    }
    w.show();
    return a.exec();
}
