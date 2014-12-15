#include "database.h"
#include "ui_database.h"
#include "insertcomputer.h"
#include "insert.h"
#include "addconnection.h"
#include "scienceservice.h"



database::database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);
    ui->Search_edit->setPlaceholderText("Search");

    //  setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið


  //  setCentralWidget(ui->tableWidget);  //setur þannig að tablewidget tekur mest alt plássið

}

database::~database()
{
    delete ui;
}
void database::start()
{

    scienceservice.open();

}

//void database::createToolBars()
  //  {
  /*  //    fileToolBar = addToolBar(tr("File"));
        fileToolBar->addAction(newAct);
}*/
/*
void database::displayCurrentPersons()
{
   std::string search = ui->Search_edit->text().toStdString();
   std::list<Scientist> s = ScienceService.searchScientist(search);
    ui->display_all->setRowCount(s.size());
    ui->display_all->setColumnCount(4);

        for (unsigned int i = 0; i < currentPersons.size(); i++) {
        ui->display_all->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(currentPersons[i].getName())));
       ui->display_all->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(currentPersons[i].getBirthyear())));
       ui->display_all->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(currentPersons[i].getDeathyear())));
        ui->display_all->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(currentPersons[i].getGender())));
    }
}
*/


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




