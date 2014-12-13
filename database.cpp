#include "database.h"
#include "ui_database.h"
#include "insertcomputer.h"
#include "insert.h"
#include "insertcomputer2.h"

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
    Insertcomputer icomput;
    //icomput.setModal(true);
    //icomput.exec();
    icomput.show();
}

void database::on_actionAdd_a_new_person_2_triggered()
{
    insert ins;
    ins.setModal(true);
    ins.exec();
}

void database::on_actionAdd_a_new_connection_triggered()
{

}

void database::on_tableWidget_activated(const QModelIndex &index)
{

}

