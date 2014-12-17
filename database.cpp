#include "database.h"
#include "ui_database.h"
#include "insertcomputer.h"
#include "insert.h"
#include "addconnection.h"
#include "scienceservice.h"

#include "treemodel.h"
#include <QDebug>



void database::resizeEvent(QResizeEvent* event)
{

    ui->tableWidget->move((ui->treeView->x() + ui->treeView->width()) + 20 ,
                          ui->Search_edit->y() + 40);



   // qDebug() << this->width();
    ui->tableWidget->resize(this->width(), this->width());
    ui->tableWidget->resize((this->width() - (ui->tableWidget->x() + 30)),
                            (this->height() - (ui->tableWidget->y())));
    ui->Search_edit->move(( ui->tableWidget->x() + ui->tableWidget->width()) -
                            ui->Search_edit->width(), ui->Search_edit->y());

    ui->treeView->move(ui->treeView->x(), ui->tableWidget->y() + 20);

    for (int c = 0; c < ui->tableWidget->horizontalHeader()->count(); ++c)
    {
        ui->tableWidget->horizontalHeader()->setSectionResizeMode(
            c, QHeaderView::Stretch);
    }
    ui->frame->resize(this->width(), ui->frame->height());
    ui->frame->move(-20, 0);

    ui->frame_persons->move(ui->tableWidget->x(),ui->tableWidget->y());
    ui->frame_persons->resize(ui->tableWidget->width(), ui->tableWidget->height());

    ui->frame_computers->move(ui->tableWidget->x(),ui->tableWidget->y());
    ui->frame_computers->resize(ui->tableWidget->width(), ui->tableWidget->height());

    ui->connectText->move(0, this->height() - (ui->connectText->height() + 20));

}



database::database(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::database)
{
    ui->setupUi(this);


    TreeModel *treemodel;
    treemodel = new TreeModel(QString("Persons\n Gender\n Year born\n Year died:Computers\n Type\n Year\n Was it built?"));

    ui->treeView->setModel(treemodel);
    ui->treeView->header()->hide();
    ui->treeView->setSelectionBehavior(QTreeView::SelectRows);
    ui->treeView->setAnimated(true);
    ui->treeView->setRootIsDecorated(false);

    ui->Search_edit->setPlaceholderText("Search");

    fillPersonTable();


    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->hideColumn(0);
    ui->tableWidget->setShowGrid(false);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSelectionMode( QAbstractItemView::SingleSelection );
    ui->treeView->header()->resizeSection(0, 220);

    ui->frame->hide();
    ui->frame_persons->hide();
    ui->frame_computers->hide();

    ui->treeView->setMaximumWidth(230);
    ui->treeView->setMinimumWidth(220);





    connect(ui->tableWidget->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(_clickHeader(int)));

    _need_connect = -1;


}

database::~database()
{
    delete ui;
}
int database::start()
{

    // scienceservice.open();

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








/*void database::on_sectionClicked(int col)
{
    qDebug() << "haha";
    if (asc)
    {
            ui->tableWidget->sortByColumn(col, Qt::AscendingOrder);
            asc = false;
    }
    else
    {
        ui->tableWidget->sortByColumn(col,Qt::DescendingOrder);
        asc = true;

    }
} */

void database::_clickHeader(int col){
    if (asc)
    {
            ui->tableWidget->sortByColumn(col, Qt::AscendingOrder);
            asc = false;
    }
    else
    {
        ui->tableWidget->sortByColumn(col,Qt::DescendingOrder);
        asc = true;

    }
    qDebug() << " Sort";
}





void database::on_action_Exit_triggered()
{
    QApplication::quit();
}

void database::dialog(QString msg)
{
    ui->label->setText(QString(msg));
    ui->pushButton->hide();
    ui->pushButton_2->setText("Sorry!");
    ui->pushButton_2->show();

    /* Fela hin framein */
    ui->frame_persons->hide();
    ui->frame_computers->hide();

    ui->frame->show();
}


void database::on_action_Remove_triggered()
{


    ui->frame->resize(this->width(), ui->frame->height());

    if (ui->tableWidget->selectionModel()->selectedRows().count() != 1)
    {
        dialog("Sorry you need to select A ROW.");

    }
    else
    {
        ui->label->setText(QString("Are you sure you wish to remove this?"));
        ui->pushButton->show();
        ui->pushButton_2->setText("No, gosh!");
        ui->pushButton_2->show();
        ui->frame->show();
        _delete_id = QString::number(ui->tableWidget->selectionModel()->selectedRows().value(0).data().toInt());

    }

}

void database::on_pushButton_2_clicked()
{
    ui->frame->hide();

}
void database::on_action_Insert_triggered()
{
    if (currentView == 1) insertComputers();
    else { insertPerson(); }
}

void database::insertComputers()
{
    ui->frame_computers->move(ui->tableWidget->x(),ui->tableWidget->y());
    ui->frame_computers->resize(ui->tableWidget->width(), ui->tableWidget->height());
    ui->frame_computers->show();

    ui->line_Computers_name->setStyleSheet("background: #fff;");
    ui->line_Computers_name->resize(210, ui->line_Persons_name->height());
    ui->line_Computers_name->setPlaceholderText("Type computer name here");
    ui->line_Computers_name->setText("");
    ui->line_Computers_name->move(40, 20);

    ui->comboComputerstype->move(40, 70);
    ui->comboComputerstype->resize(210, ui->line_Persons_name->height());

    ui->line_Computers_yearbuilt->setStyleSheet("background: #fff;");
    ui->line_Computers_yearbuilt->resize(210, ui->line_Persons_name->height());
    ui->line_Computers_yearbuilt->setPlaceholderText("...year built");
    ui->line_Computers_yearbuilt->setText("");
    ui->line_Computers_yearbuilt->move(40, 120);

    ui->checkBox_Computers_WasBuilt->move(40, 180);
    ui->checkBox_Computers_WasBuilt->setChecked(true);

    ui->buttonComputersInsert->move(40,280);
    ui->buttonCloseComputers->move(150,280);

}

void database::insertPerson()
{
    ui->frame_persons->move(ui->tableWidget->x(),ui->tableWidget->y());
    ui->frame_persons->resize(ui->tableWidget->width(), ui->tableWidget->height());


    ui->frame_persons->show();


    ui->line_Persons_name->setStyleSheet("background: #fff;");
    ui->line_Persons_name->resize(210, ui->line_Persons_name->height());
    ui->line_Persons_name->setPlaceholderText("Type a full name here");
    ui->line_Persons_name->setText("");
    ui->line_Persons_name->move(40, 20);

    ui->comboPersonMale->move(40, 70);
    ui->comboPersonFemale->move(40, 100);
    ui->comboPersonMale->setChecked(true);


    ui->line_Persons_yearborn->setStyleSheet("background: #fff;");
    ui->line_Persons_yearborn->resize(210, ui->line_Persons_name->height());
    ui->line_Persons_yearborn->setPlaceholderText("...year born");
    ui->line_Persons_yearborn->setText("");
    ui->line_Persons_yearborn->move(40, 140);

    ui->checkBox_Persons_StillAlive->move(40, 180);
    ui->checkBox_Persons_StillAlive->setChecked(true);


    ui->line_Persons_whendied->hide();
    ui->line_Persons_whendied->setStyleSheet("background: #fff;");
    ui->line_Persons_whendied->resize(210, ui->line_Persons_name->height());
    ui->line_Persons_whendied->setPlaceholderText("... year died");
    ui->line_Persons_whendied->move(40, 220);

    ui->buttonPersonInsert->move(40,280);
    ui->buttonClosePerson->move(150,280);



    ui->line_Persons_whendied->setText("");
}

void database::on_buttonClosePerson_clicked()
{
    ui->frame_persons->hide();


}

void database::on_buttonCloseComputers_clicked()
{
    ui->frame_computers->hide();

}

void database::on_actionConnect_triggered()
{
    ui->frame->resize(this->width(), ui->frame->height());

    if (ui->tableWidget->selectionModel()->selectedRows().count() != 1)
    {
        dialog("Sorry you need to select A ROW.");

    }
    else
    {
        if (_need_connect == -1)
        {
        if (currentView == 0)
        {
            _need_connect = 1;
            _connect_person_id = ui->tableWidget->selectionModel()->selectedRows().value(0).data().toInt();

        }
        else{
            _connect_computer_id = ui->tableWidget->selectionModel()->selectedRows().value(0).data().toInt();
           _need_connect = 0;
        }

        }
        else if (_need_connect == currentView)
        {
            if (currentView == 0)
                _connect_person_id = ui->tableWidget->selectionModel()->selectedRows().value(0).data().toInt();
            else if (currentView == 1)
            {
                _connect_computer_id = ui->tableWidget->selectionModel()->selectedRows().value(0).data().toInt();

            }

            _need_connect = -1;
            ScientistComputerConnections newConn;

            std::string cid = "" + _connect_computer_id;
            std::string sid = "" + _connect_person_id;
            scienceService.addConnection(sid, cid );

        }
    }
}

void database::personstable()
{
    cleartable();
    fillPersonTable();

}

void database::computerstable()
{

    cleartable();
    fillComputerTable();

}

void database::cleartable()
{

    ui->tableWidget->clearContents();
    ui->tableWidget->setColumnCount(0);
    ui->tableWidget->setRowCount(0);


}

void database::fillPersonTable(bool all){
    currentView = 0;

    ui->tableWidget->clearContents();
    QStringList personheader;
    personheader << "ID"  << "Name" << "Gender" << "Year born" << "Year dead";
    ui->tableWidget->setColumnCount(5);

    ui->tableWidget->setHorizontalHeaderLabels(personheader);
    ui->tableWidget->setColumnHidden(0, true);
    list<Scientist> currentScientists;
    if (all)
        currentScientists = scienceService.getAllScientists();
    else
    {
         std::string currentSearchterm = ui->Search_edit->text().toUtf8().constData();
         currentScientists = scienceService.searchScientist(currentSearchterm);
    }

   int counter = 0;
    for(std::list<Scientist>::iterator iter = currentScientists.begin(); iter != currentScientists.end(); iter ++) {
           QString gender, yeardead;
           if (iter->getGender() == 0) gender = "Male";
           else gender = "Female";
           yeardead = QString::fromStdString(iter->getDateOfDeath());
           if (yeardead == "0") yeardead = "Alive";
           ui->tableWidget->insertRow(counter);

           QTableWidgetItem *icon_item = new QTableWidgetItem;
           // icon_item->setIcon(icon);

           ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(QString::number(iter->getId())));
           ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(QString::fromStdString(iter->getName())));
           ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(gender));
           ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(QString::fromStdString(iter->getDateOfBirth())));
           ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(yeardead));
           counter++;
        }
    ui->tableWidget->setRowCount(counter);
}

void database::fillComputerTable(bool all){
    currentView = 1;

    ui->tableWidget->clearContents();
    QStringList computerheader;
    computerheader << "ID" << "Name" << "Year built" << "Type" << "Was it built?";
    ui->tableWidget->setColumnCount(5);

    ui->tableWidget->setColumnHidden(0, true);
    ui->tableWidget->setHorizontalHeaderLabels(computerheader);
    list<Computer> currentComputer;
    if (all)
         currentComputer = scienceService.getAllComputers();
    else
    {
         std::string currentSearchterm = ui->Search_edit->text().toUtf8().constData();
         currentComputer = scienceService.searchComputer(currentSearchterm);
    }

       int counter2 = 0;




    for(std::list<Computer>::iterator iter = currentComputer.begin(); iter != currentComputer.end(); iter ++) {
            QString wasbuilt;
            if (QString::number(iter->getWasBuilt()) == "1")
                 wasbuilt = "Yes";
            else
                wasbuilt = "No";

            int a = iter->getType();
            QString machinetype;
            switch(a)
            {
                case 0:
                    machinetype = "Electronics";
                    break;
                case 1:
                    machinetype = "Mechanical";
                    break;
                case 2:
                    machinetype = "Electro-mechanical";
                    break;
                case 3:
                    machinetype = "Transistors";
                    break;

                default:
                    machinetype ="Other";


               }
           ui->tableWidget->insertRow(counter2);
           ui->tableWidget->setItem(counter2, 0, new QTableWidgetItem(QString::number(iter->getId())));
           ui->tableWidget->setItem(counter2, 1, new QTableWidgetItem(QString::fromStdString(iter->getName())));
           ui->tableWidget->setItem(counter2, 2, new QTableWidgetItem(QString::fromStdString(iter->getYearBuilt())));
           ui->tableWidget->setItem(counter2, 3, new QTableWidgetItem(machinetype));
           ui->tableWidget->setItem(counter2, 4, new QTableWidgetItem(wasbuilt));
           counter2++;
    }
        ui->tableWidget->setRowCount(counter2);


}

void database::on_treeView_clicked(const QModelIndex &index)
{
    QModelIndex root;
    root = index;
    while(1)
    {
        if (root.parent().row() == -1)
        {
            break;
        }
        else
        {
            root = root.parent();
        }
    }
    if (root.row() == 0)
    {
        fillPersonTable();
    }
    else
    {
        fillComputerTable();
    }
}

void database::on_actionName_toggled(bool arg1)
{

}

void database::on_Search_edit_returnPressed()
{
    if (currentView == 1)
        fillComputerTable(false);
    else if (currentView == 0)
        fillPersonTable(false);
}

void database::on_buttonComputersInsert_clicked()
{
    Computer newComp;
    newComp.setName(ui->line_Computers_name->text().toUtf8().constData());
    newComp.setYearBuilt(ui->line_Computers_yearbuilt->text().toUtf8().constData());
    int wasbuilt;
    int type = ui->comboComputerstype->currentIndex();
    if (ui->checkBox_Computers_WasBuilt->isChecked()) wasbuilt = true;
    else wasbuilt = false;
    newComp.setType(type);
    newComp.setWasBuilt(wasbuilt);
    scienceService.addComputer(newComp);
    ui->frame_computers->hide();
    fillComputerTable();

}

void database::on_buttonPersonInsert_clicked()
{

    Scientist newScie;
    newScie.setName(ui->line_Persons_name->text().toUtf8().constData());
    newScie.setDateOfBirth(ui->line_Persons_yearborn->text().toUtf8().constData());

    std::string died;
    if (ui->checkBox_Persons_StillAlive->isChecked())
    {
        died = "0";
    }
    else
    {
        died = ui->line_Persons_whendied->text().toUtf8().constData();
    }
    int gender;
    if (ui->comboPersonMale->isChecked()) gender = 0;
    else gender = 1;

    newScie.setDateOfDeath(died);
    newScie.setGender(gender);
    scienceService.addScientist(newScie);
    ui->frame_persons->hide();
    fillPersonTable();
}

void database::on_pushButton_clicked()
{
    if (currentView == 1)
    {
        scienceService.removeComputer(_delete_id.toUtf8().constData());
        ui->frame->hide();
        fillComputerTable();
    }
    else if (currentView == 0)
    {
        qDebug() << _delete_id.toUtf8().constData();
        scienceService.removeScientist(_delete_id.toUtf8().constData());
        ui->frame->hide();
        fillPersonTable();
    }


}

void database::on_checkBox_Persons_StillAlive_clicked()
{
    qDebug() << "hello";
    if (ui->checkBox_Persons_StillAlive->isChecked())
     {
        ui->line_Persons_whendied->hide();
    }
    else
    {
        ui->line_Persons_whendied->show();
    }
}
