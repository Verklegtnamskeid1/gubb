#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>

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

private:
    Ui::database *ui;
};

#endif // DATABASE_H
