#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H

#include <QDialog>

namespace Ui {
class addconnection;
}

class addconnection : public QDialog
{
    Q_OBJECT

public:
    explicit addconnection(QWidget *parent = 0);
    ~addconnection();

private:
    Ui::addconnection *ui;
};

#endif // ADDCONNECTION_H
