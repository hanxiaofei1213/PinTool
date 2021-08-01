#include "pintool.h"
#include <QtWidgets/QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/qss/res/styleSheet.qss");
    if (file.open(QIODevice::ReadOnly)) {
        a.setStyleSheet(file.readAll());
    }

    PinTool w;
    w.show();
    return a.exec();
}
