#include "GUI.h"
#include "test.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    test_all();

    Repo r{ "melodii.txt" };
    Service s{ r };

    QApplication a(argc, argv);
    GUI w{ s };
    w.show();

    return a.exec();
}