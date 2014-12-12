#include "database.h"
#include "ui_database.h"

database::database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);
    ui->Search_edit->setPlaceholderText("Search");
}

database::~database()
{
    delete ui;
}

void database::on_Search_edit_cursorPositionChanged(int arg1, int arg2)
{
    //displaydatabase-ið sem við ætlum að nota();
}

void database::on_actionAdd_new_computer_triggered()
{

}

void database::on_actionAdd_a_new_computer_triggered()
{

}

void database::on_actionAdd_a_new_person_2_triggered()
{

}

void database::on_actionAdd_a_new_connection_triggered()
{

}

void database::on_tableWidget_activated(const QModelIndex &index)
{

}
