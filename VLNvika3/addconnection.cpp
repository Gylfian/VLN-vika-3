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
    ui->computersList->setHorizontalHeaderLabels(QString("Name;Type;Built?;Year built").split(";"));
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

void AddConnection::displayAllComputers()
{
    vector <Computer> computers;
    domain.sortBy(computers, 1, 1);
    displayComputers(computers);
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

void AddConnection::displayComputers(vector <Computer> computers)
{
    designComputersWidget(computers);
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        Computer currentCom = computers[i];
        ui->computersList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currentCom.getName())));
        ui->computersList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(currentCom.getType())));
        ui->computersList->setItem(i,2,new QTableWidgetItem(QString::fromStdString(currentCom.getBuilt())));
        ui->computersList->setItem(i,3,new QTableWidgetItem(QString::fromStdString(currentCom.getYear())));
    }
}

void AddConnection::designScientistsWidget(vector <CScientist> scientists)
{
    ui->scientistsList->clear();
    ui->scientistsList->setHorizontalHeaderLabels(QString("Name").split(";"));
    int size = scientists.size();
    ui->scientistsList->setRowCount(size);
}

void AddConnection::designComputersWidget(vector <Computer> computers)
{
    ui->computersList->clear();
    int size = computers.size();
    ui->computersList->setRowCount(size);
}

void AddConnection::setUp()
{
    setWindowTitle("Add Connection");
    ui->scientistsList->setColumnWidth(0, 160);
    ui->scientistsList->setColumnWidth(1, 70);
    ui->scientistsList->setColumnWidth(2, 90);
    ui->scientistsList->setColumnWidth(3, 100);
    ui->computersList->setColumnWidth(0, 150);
    ui->computersList->setColumnWidth(1, 115);
    ui->computersList->setColumnWidth(2, 55);
    ui->computersList->setColumnWidth(3, 100);
    displayAllScientists();
    displayAllComputers();
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

}



void AddConnection::on_scientistsList_clicked(const QModelIndex &index)
{
    int row = ui->scientistsList->currentRow();
    ui->scientistsList->selectRow(index.row());
    ui->addSci->setText(ui->scientistsList->item(row, 0)->text());
    scientist.setName(ui->scientistsList->item(row, 0)->text().toStdString());
    scientist.setGender(ui->scientistsList->item(row, 1)->text().toStdString());
    scientist.setDob(ui->scientistsList->item(row, 2)->text().toStdString());
    scientist.setDod(ui->scientistsList->item(row, 3)->text().toStdString());
}


void AddConnection::on_computersList_clicked(const QModelIndex &index)
{
    int row = ui->computersList->currentRow();
    ui->computersList->selectRow(index.row());
    ui->addCom->setText(ui->computersList->item(row, 0)->text());
    computer.setName(ui->computersList->item(row, 0)->text().toStdString());
    computer.setType(ui->computersList->item(row, 1)->text().toStdString());
    computer.setBuilt(ui->computersList->item(row, 2)->text().toStdString());
    computer.setYear(ui->computersList->item(row, 3)->text().toStdString());

}

void AddConnection::on_btnConnect_clicked()
{
    CScientist cSci = domain.findScientist(scientist);
    Computer cCom = domain.findComputer(computer);
    if(!ui->addSci->text().isEmpty() && !ui->addCom->text().isEmpty())
    {
        string msg = "Connection between " + cSci.getName() + " and " + cCom.getName() + " has been establied. You can manage this connection in List Options from the main menu.";
        QString qstr = QString::fromStdString(msg);
        domain.addRelation(cSci, cCom);
        QMessageBox::information(this, "Add Connection", qstr);
    }
}
