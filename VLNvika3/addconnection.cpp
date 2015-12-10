#include "addconnection.h"
#include "ui_addconnection.h"

AddConnection::AddConnection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConnection)
{
    ui->setupUi(this);
}

AddConnection::~AddConnection()
{
    delete ui;
}
