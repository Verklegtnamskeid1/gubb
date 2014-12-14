#include "main.h"
#include "consoleui.h"
#include "database.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    database w;
    w.show();

    return a.exec();

   /* ConsoleUI ui = ConsoleUI();
    ui.start();

    return 0;
*/
}
