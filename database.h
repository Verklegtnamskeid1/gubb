#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include "insertcomputer.h"
#include "scientistrepository.h"
#include "scientist.h"
#include "scienceservice.h"
namespace Ui {
class database;
}

class database : public QMainWindow
{
    Q_OBJECT

public:
    explicit database(QWidget *parent = 0);
    int start();
    ~database();
    void dialog(QString msg);
    void insertPerson();
    void insertComputers();
    int deleteid;

public slots:
  virtual void resizeEvent(QResizeEvent *event);


private slots:
    void _clickHeader(int col);




    void on_action_Exit_triggered();

    void on_action_Remove_triggered();

    void on_pushButton_2_clicked();

    void on_action_Insert_triggered();

    void on_buttonClosePerson_clicked();

    void on_buttonCloseComputers_clicked();

    void on_actionConnect_triggered();

    void on_treeView_clicked(const QModelIndex &index);

    void on_actionName_toggled(bool arg1);

    void on_Search_edit_returnPressed();

    void on_buttonComputersInsert_clicked();

    void on_buttonPersonInsert_clicked();

    void on_pushButton_clicked();

    void on_checkBox_Persons_StillAlive_clicked();

private:
    QString _delete_id;
    bool asc = true;

    int currentView;

    Ui::database *ui;

    Insertcomputer *insertcomp;

    ScientistRepository scientistRepository;
    ScienceService scienceService;

    void cleartable();
    void personstable();
    void computerstable();
    void fillConnectionTable(bool all = true);

    void fillComputerTable(bool all = true);
    void fillPersonTable(bool all = true);

    int _need_connect;
    int _connect_person_id;
    int _connect_computer_id;

};

#endif // DATABASE_H
