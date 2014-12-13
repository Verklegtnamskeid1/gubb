#include "insertcomputer.h"
#include "ui_insertcomputer.h"

Insertcomputer::Insertcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insertcomputer)
{
    ui->setupUi(this);
}

Insertcomputer::~Insertcomputer()
{
    delete ui;
}

void Insertcomputer::on_submit_computer_clicked()
{

}

void Insertcomputer::on_lineEdit_namecomputer_cursorPositionChanged(int arg1, int arg2)
{

}
