#include "database.h"
#include "ui_database.h"
#include "insertcomputer.h"
#include "insert.h"
#include "addconnection.h"



database::database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);
    ui->Search_edit->setPlaceholderText("Search");
    setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið
}

database::~database()
{
    delete ui;
}

void database::on_Search_edit_cursorPositionChanged(int arg1, int arg2)
{
    //displaydatabase-ið sem við ætlum að nota();
}


void database::on_actionAdd_a_new_computer_triggered()
{
   insertcomp = new Insertcomputer(this);
   insertcomp->show();
   //Hafa alla svona ef við viljum hafa að það sé hægt að hafa alla gluggana opna í einu.
}

void database::on_actionAdd_a_new_person_2_triggered()
{
    insert ins;
    ins.setModal(true);
    ins.exec();
}

void database::on_actionAdd_a_new_connection_triggered()
{
   addconnection addcon;
   addcon.setModal(true);
   addcon.exec();
}

void database::on_tableWidget_activated(const QModelIndex &index)
{

}

