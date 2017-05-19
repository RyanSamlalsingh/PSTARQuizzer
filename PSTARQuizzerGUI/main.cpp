#include "PSTARQuizzerMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PSTARQuizzerMainWindow w;
    w.show();
    return a.exec();
}
