#include "addconnection.h"
#include "ui_addconnection.h"

addconnection::addconnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addconnection)
{
    ui->setupUi(this);
}

addconnection::~addconnection()
{
    delete ui;
}
