#ifndef INSERTCOMPUTER_H
#define INSERTCOMPUTER_H

#include <QDialog>

namespace Ui {
class Insertcomputer;
}

class Insertcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit Insertcomputer(QWidget *parent = 0);
    ~Insertcomputer();

private:
    Ui::Insertcomputer *ui;
};

#endif // INSERTCOMPUTER_H
