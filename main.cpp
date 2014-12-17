#include "database.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    database w;
    w.show();

    QFile file(":/CSS/style.css");

    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
        a.setStyleSheet(file.readAll());
        file.close();
       }


    return a.exec();



}


