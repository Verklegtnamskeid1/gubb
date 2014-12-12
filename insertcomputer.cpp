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
