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
    setUp();
    ui->scientistsList->setHorizontalHeaderLabels(QString("Name;Gender;Birth year;Death year").split(";"));
}

AddConnection::~AddConnection()
{
    delete ui;
}
void AddConnection::enable()
{

}



void AddConnection::displayAllScientists()
{
    vector <CScientist> scientists;
    domain.sortBy(scientists, 1, 1);
    displayScientists(scientists);
}

void AddConnection::displayScientists(vector <CScientist> scientists)
{
    designScientistsWidget(scientists);
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        CScientist currentSci = scientists[i];
        ui->scientistsList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currentSci.getName())));
        ui->scientistsList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(currentSci.getGender())));
        ui->scientistsList->setItem(i,2,new QTableWidgetItem(QString::fromStdString(currentSci.getDob())));
        ui->scientistsList->setItem(i,3,new QTableWidgetItem(QString::fromStdString(currentSci.getDod())));
    }
}

void AddConnection::designScientistsWidget(vector <CScientist> scientists)
{
    ui->scientistsList->clear();
    ui->scientistsList->setHorizontalHeaderLabels(QString("Name;Gender;Birth year;Death year").split(";"));
    int size = scientists.size();
    ui->scientistsList->setRowCount(size);
}

void AddConnection::setUp()
{
    setWindowTitle("Add Connection");
    ui->scientistsList->setColumnWidth(0, 160);
    ui->scientistsList->setColumnWidth(1, 70);
    ui->scientistsList->setColumnWidth(2, 90);
    ui->scientistsList->setColumnWidth(3, 100);
    displayAllScientists();
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
