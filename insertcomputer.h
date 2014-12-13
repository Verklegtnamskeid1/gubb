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

private slots:
    void on_submit_computer_clicked();

    void on_lineEdit_namecomputer_cursorPositionChanged(int arg1, int arg2);

private:
    Ui::Insertcomputer *ui;
};

#endif // INSERTCOMPUTER_H
