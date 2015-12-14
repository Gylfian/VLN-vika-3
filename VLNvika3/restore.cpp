#include "restore.h"
#include "ui_restore.h"
#include "domain.h"
#include <QDebug>
#include <QTableWidget>
#include <sstream>


Restore::Restore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Restore)
{
    ui->setupUi(this);
    ui->computerList->setRowCount(5);
    ui->scientistList->setRowCount(5);
    ui->computerList->setColumnCount(4);
    ui->scientistList->setColumnCount(4);
    setUp();
    ui->scientistList->setHorizontalHeaderLabels(QString("Name;Gender;Birth year;Death year").split(";"));
    ui->computerList->setHorizontalHeaderLabels(QString("Name;Type;Built?;Year built").split(";"));
}

Restore::~Restore()
{
    delete ui;
}

void Restore::setUp()
{
    ui->scientistList->setColumnWidth(0, 160);
    ui->scientistList->setColumnWidth(1, 70);
    ui->scientistList->setColumnWidth(2, 90);
    ui->scientistList->setColumnWidth(3, 100);
    ui->computerList->setColumnWidth(0, 150);
    ui->computerList->setColumnWidth(1, 115);
    ui->computerList->setColumnWidth(2, 55);
    ui->computerList->setColumnWidth(3, 100);
    displayAllScientists();
    displayAllComputers();

   //CScientist s1;
   //Computer c1;

    //displayvector(s1);
    //displayvector(c1);
}

void Restore::displayAllScientists()
{
    Domain d1;
    vector <CScientist> scientists;

    d1.restoreEntry(scientists);
    displayScientists(scientists);
}

void Restore::displayAllComputers()
{
    Domain d1;
    vector <Computer> computers;

    d1.restoreEntry(computers);
    displayComputers(computers);
}

void Restore::displayScientists(vector <CScientist> scientists)
{
    designScientistsWidget(scientists);
    for(int i = 0; i < scientists.size(); i++)
    {
        CScientist currentSci = scientists[i];
        ui->scientistList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currentSci.getName())));
        ui->scientistList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(currentSci.getGender())));
        ui->scientistList->setItem(i,2,new QTableWidgetItem(QString::fromStdString(currentSci.getDob())));
        ui->scientistList->setItem(i,3,new QTableWidgetItem(QString::fromStdString(currentSci.getDod())));
    }
}

void Restore::displayComputers(vector <Computer> computers)
{
    designComputersWidget(computers);
    for(int i = 0; i < computers.size(); i++)
    {
        Computer currentCom = computers[i];
        ui->computerList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currentCom.getName())));
        ui->computerList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(currentCom.getType())));
        ui->computerList->setItem(i,2,new QTableWidgetItem(QString::fromStdString(currentCom.getBuilt())));
        ui->computerList->setItem(i,3,new QTableWidgetItem(QString::fromStdString(currentCom.getYear())));
    }
}

void Restore::designScientistsWidget(vector <CScientist> scientists)
{
    ui->scientistList->clear();
    int size = scientists.size();
    ui->scientistList->setRowCount(size);

}

void Restore::designComputersWidget(vector <Computer> computers)
{
    ui->computerList->clear();
    int size = computers.size();
    ui->computerList->setRowCount(size);

}

void Restore::on_scientistList_clicked(const QModelIndex &index)
{
    ui->scientistList->selectRow(index.row());
    ui->restoreButtonSci->setEnabled(true);
    int row = ui->scientistList->currentItem()->row();
    scientist.setName(ui->scientistList->item(row, 0)->text().toStdString());
    scientist.setGender(ui->scientistList->item(row, 1)->text().toStdString());
    scientist.setDob(ui->scientistList->item(row, 2)->text().toStdString());
    scientist.setDod(ui->scientistList->item(row, 3)->text().toStdString());
}
void Restore::on_computerList_clicked(const QModelIndex &index)
{
    int row = ui->computerList->currentRow();
    ui->computerList->selectRow(index.row());
    ui->restoreButtonComp->setEnabled(true);
    computer.setName(ui->computerList->item(row, 0)->text().toStdString());
    computer.setType(ui->computerList->item(row, 1)->text().toStdString());
    computer.setBuilt(ui->computerList->item(row, 2)->text().toStdString());
    computer.setYear(ui->computerList->item(row, 3)->text().toStdString());
}


void Restore::on_restoreButtonSci_clicked()
{
    Domain d1;
    CScientist s1;
    s1 = d1.findInactiveScientist(scientist);
    string strengur = s1.getDod();
    int id=s1.getId();
    qDebug() << s1.getId();
    qDebug() << QString::fromStdString(strengur);
    stringstream ss;
    ss << id;
    string converted = ss.str();
    d1.updateEntrySci(converted);
    displayAllScientists();
}

void Restore::on_restoreButtonComp_clicked()
{
    Domain d1;
    Computer c1;
    c1 = d1.findInactiveComputer(computer);
    string strengur = c1.getName();
    int id=c1.getId();
    qDebug() << c1.getId();
    qDebug() << QString::fromStdString(strengur);
    stringstream ss;
    ss << id;
    string converted = ss.str();
    d1.updateEntryCom(converted);
    displayAllComputers();

}
