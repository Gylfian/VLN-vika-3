#include "addconnection.h"
#include "ui_addconnection.h"
#include <iostream>
#include <QDebug>
using namespace std;

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
void AddConnection::enable()
{
    ui->listScientists->setDragEnabled(true);
    ui->listComputers->setDragEnabled(true);
    ui->dragComputers->setAcceptDrops(true);
    ui->dragScientists->setAcceptDrops(true);
    ui->dragComputers->setDragDropOverwriteMode(true);
    ui->dragScientists->setDragDropOverwriteMode(true);
}

void AddConnection::dragEnterEvent(QDragEnterEvent *event)
{
    cout << "Drag enter event";
}
void AddConnection::dropEvent(QDropEvent *event)
{
    exit(1);
}

void AddConnection::on_dragScientists_entered(const QModelIndex &index)
{

}

void AddConnection::on_dragScientists_clicked(const QModelIndex &index)
{
    cout << "Drag enter event";
    exit(1);
}

void AddConnection::on_pushButton_clicked()
{
    cout << "Drag enter event";
    exit(1);
}
