#include "listoptions.h"
#include "ui_listoptions.h"
#include "domain.h"
#include "editscientist.h"
#include "editcomputer.h"
#include "analyze.h"
#include "ui_analyze.h"
#include <QDebug>

ListOptions::ListOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOptions)
{
    ui->setupUi(this);
    setWindowTitle("List options");
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

CScientist ListOptions::getsci()
{
    return scientist;
}

ListOptions::~ListOptions()
{
    delete ui;
}

void ListOptions::setCurrent()
{

}

void ListOptions::displayAllScientists()
{
    Domain d1;
    vector <CScientist> scientists;

    d1.sortBy(scientists, 1, 1);
    displayScientists(scientists);
}

void ListOptions::displayAllComputers()
{
    Domain d1;
    vector <Computer> computers;

    d1.sortBy(computers, 1, 1);
    displayComputers(computers);
}

/*
void ListOptions::displayConnections()
{
    Domain d1;
    vector <string> computers;
    vector <string> scientists;
    vector <int> connections;
    d1.getRelationList(scientists, computers, connections);
    displayScientists(connections);
}*/

void ListOptions::displayScientists(vector <CScientist> scientists)
{
    designScientistsWidget(scientists);
    for(int i = 0; i < scientists.size(); i++)
    {
        CScientist currentSci = scientists[i];
        ui->scientistsList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currentSci.getName())));
        ui->scientistsList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(currentSci.getGender())));
        ui->scientistsList->setItem(i,2,new QTableWidgetItem(QString::fromStdString(currentSci.getDob())));
        ui->scientistsList->setItem(i,3,new QTableWidgetItem(QString::fromStdString(currentSci.getDod())));
    }
}

void ListOptions::displayComputers(vector <Computer> computers)
{
    designComputersWidget(computers);
    for(int i = 0; i < computers.size(); i++)
    {
        Computer currentCom = computers[i];
        ui->computersList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currentCom.getName())));
        ui->computersList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(currentCom.getType())));
        ui->computersList->setItem(i,2,new QTableWidgetItem(QString::fromStdString(currentCom.getBuilt())));
        ui->computersList->setItem(i,3,new QTableWidgetItem(QString::fromStdString(currentCom.getYear())));
    }
}

void ListOptions::designScientistsWidget(vector <CScientist> scientists)
{
    ui->scientistsList->clear();
    int size = scientists.size();
    ui->scientistsList->setHorizontalHeaderLabels(QString("Name;Gender;Birth year;Death year").split(";"));
    ui->scientistsList->setRowCount(size);

}

void ListOptions::designComputersWidget(vector <Computer> computers)
{
    ui->computersList->clear();
    int size = computers.size();
    ui->computersList->setHorizontalHeaderLabels(QString("Name;Type;Built?;Year built").split(";"));
    ui->computersList->setRowCount(size);

}

void ListOptions::on_findSciButton_clicked()
{
    ui->editScientist->setEnabled(false);
    string searchString = ui->findSciLineEdit->text().toStdString();
    vector <CScientist> scientists;
    Domain d1;
    CScientist temp;
    d1.sortBy(scientists, 1, 1);
    temp.setName(searchString);
    d1.search(scientists, temp);
    displayScientists(scientists);
}

void ListOptions::on_findComButton_clicked()
{
    string searchString = ui->findComLineEdit->text().toStdString();
    vector <Computer> computers;
    Domain d1;
    Computer temp;
    d1.sortBy(computers, 1, 1);
    temp.setName(searchString);
    d1.search(computers, temp);
    displayComputers(computers);
}

void ListOptions::on_editScientist_clicked()
{
   Editscientist editscientist;
   editscientist.setScientist(scientist);
   int wasRejected = editscientist.exec();

   if(wasRejected == QDialog::Rejected)
       return;
   //scientist.setName(editscientist.name().toStdString());
   //scientist.setGender(editscientist.gender().toStdString());
   //scientist.setDob(editscientist.yearBorn().toStdString());
   //scientist.setDod(editscientist.yearOfDeath().toStdString());
   /*
   scientist = editscientist.name().toStdString();
   gender = editscientist.gender().toStdString();
   yearBorn = editscientist.yearBorn().toStdString();
   yearOfDeath = editscientist.yearOfDeath().toStdString();
   temp.setName(name);
   temp.setGender(gender);
   temp.setDob(yearBorn);
   temp.setDod(yearOfDeath);
   */
   //Domain dom;
   //dom.editEntry(scientist);
   //displayAllScientists();
}

void ListOptions::on_scientistsList_clicked(const QModelIndex &index)
{
    //qDebug() << "index: " << index;
    int row = ui->scientistsList->currentItem()->row();
    scientist.setName(ui->scientistsList->item(row, 0)->text().toStdString());
    scientist.setGender(ui->scientistsList->item(row, 1)->text().toStdString());
    scientist.setDob(ui->scientistsList->item(row, 2)->text().toStdString());
    scientist.setDod(ui->scientistsList->item(row, 3)->text().toStdString());
    ui->editScientist->setEnabled(true);
}

void ListOptions::on_editComputers_clicked()
{
    Editcomputer editcomputer;
    int wasRejected = editcomputer.exec();
    if(wasRejected == QDialog::Rejected)
        return;
    int row = ui->computersList->currentItem()->row();
    int column = ui->computersList->currentItem()->column();
    string name = editcomputer.name().toStdString();
    string type = editcomputer.type().toStdString();
    string wasBuilt = editcomputer.wasBuilt().toStdString();
    string yearBuilt = editcomputer.yearBuilt().toStdString();
    Computer temp(row, name, yearBuilt, type, wasBuilt);
    Domain dom;
    dom.editEntry(temp);
    displayAllComputers();
}

void ListOptions::on_computersList_clicked(const QModelIndex &index)
{
    //qDebug() << "index: " << index;
    ui->editComputers->setEnabled(true);
}

void ListOptions::on_scientistsList_doubleClicked(const QModelIndex &index)
{
    int row = ui->scientistsList->currentRow();
    string name = ui->scientistsList->item(row, 0)->text().toStdString();
    string gender = ui->scientistsList->item(row, 1)->text().toStdString();
    string yearBorn = ui->scientistsList->item(row, 2)->text().toStdString();
    string yearOfDeath = ui->scientistsList->item(row, 3)->text().toStdString();
    CScientist temp(row, name, gender, yearBorn, yearOfDeath, true);
    Analyze analyze;
    analyze.exec();
}

void ListOptions::on_analyzeScientistBotton_clicked()
{
    Analyze analyze;
    analyze.exec();
}

void ListOptions::on_computersList_doubleClicked(const QModelIndex &index)
{
    int row = ui->computersList->currentRow();
    string name = ui->computersList->item(row, 0)->text().toStdString();
    string type = ui->computersList->item(row, 1)->text().toStdString();
    string wasBuilt = ui->computersList->item(row, 2)->text().toStdString();
    string year = ui->computersList->item(row, 3)->text().toStdString();
    Analyze analyze;
    analyze.exec();
}
