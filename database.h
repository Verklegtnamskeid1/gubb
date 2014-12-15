#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include "insertcomputer.h"
namespace Ui {
class database;
}

class database : public QMainWindow
{
    Q_OBJECT

public:
    explicit database(QWidget *parent = 0);
    ~database();

private slots:
    void on_Search_edit_cursorPositionChanged(int arg1, int arg2);

    void on_actionAdd_new_computer_triggered();

    void on_actionAdd_a_new_computer_triggered();

    void on_actionAdd_a_new_person_2_triggered();

    void on_actionAdd_a_new_connection_triggered();

    void on_tableWidget_activated(const QModelIndex &index);

<<<<<<< HEAD
    void on_treeWidget_activated(const QModelIndex &index);

    void on_Search_edit_textChanged(const QString &arg1);
    void displayCurrentPersons();
=======
>>>>>>> 5cfc50f5c398a82a87b7a14850528912e8e67d5c
private:
    Ui::database *ui;
    Insertcomputer *insertcomp;
};

#endif // DATABASE_H
