#include "consoleui.h"
#include "database.h"
#include <QApplication>
#include "consoleui.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database w;
    w.show();

    return a.exec();


    ConsoleUI ui = ConsoleUI();

    return ui.start();
}


