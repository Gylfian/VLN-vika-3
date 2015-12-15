#include "searchresults.h"
#include "ui_searchresults.h"
#include "editscientist.h"
#include "editcomputer.h"
#include "domain.h"
#include <QDebug>

Searchresults::Searchresults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Searchresults)
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

Searchresults::~Searchresults()
{
    delete ui;
}

void Searchresults::setUp()
{
    ui->scientistList->setColumnWidth(0, 160);
    ui->scientistList->setColumnWidth(1, 70);
    ui->scientistList->setColumnWidth(2, 90);
    ui->scientistList->setColumnWidth(3, 100);
    ui->computerList->setColumnWidth(0, 150);
    ui->computerList->setColumnWidth(1, 115);
    ui->computerList->setColumnWidth(2, 55);
    ui->computerList->setColumnWidth(3, 100);
}

void Searchresults::displayAllScientists()
{
    displayScientists(sciResults);
    ui->scientistList->setHorizontalHeaderLabels(QString("Name;Gender;Birth year;Death year").split(";"));
}

void Searchresults::displayAllComputers()
{
    displayComputers(compResults);
    ui->computerList->setHorizontalHeaderLabels(QString("Name;Type;Built?;Year built").split(";"));
}

void Searchresults::displayScientists(vector <CScientist> scientists)
{
    designScientistsWidget(scientists);
    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        CScientist currentSci = scientists[i];
        ui->scientistList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currentSci.getName())));
        ui->scientistList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(currentSci.getGender())));
        ui->scientistList->setItem(i,2,new QTableWidgetItem(QString::fromStdString(currentSci.getDob())));
        ui->scientistList->setItem(i,3,new QTableWidgetItem(QString::fromStdString(currentSci.getDod())));
    }
}

void Searchresults::displayComputers(vector <Computer> computers)
{
    designComputersWidget(computers);
    for(unsigned int i = 0; i < computers.size(); i++)
    {
        Computer currentCom = computers[i];
        ui->computerList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(currentCom.getName())));
        ui->computerList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(currentCom.getType())));
        ui->computerList->setItem(i,2,new QTableWidgetItem(QString::fromStdString(currentCom.getBuilt())));
        ui->computerList->setItem(i,3,new QTableWidgetItem(QString::fromStdString(currentCom.getYear())));
    }
}

void Searchresults::designScientistsWidget(vector <CScientist> scientists)
{
    ui->scientistList->clear();
    int size = scientists.size();
    ui->scientistList->setRowCount(size);

}

void Searchresults::designComputersWidget(vector <Computer> computers)
{
    ui->computerList->clear();
    int size = computers.size();
    ui->computerList->setRowCount(size);

}

/*void Searchresults::displayvector(Computer c1)
{
    vector<Computer> computers;
    Domain d1;
    d1.search(computers,c1);
    for(int i =0; i<computers.size(); i++)
    {
    Computer temp = computers[i];
    string name = temp.getName();
    ui->computerList->addItem(QString::fromStdString(name));
    }
}

void Searchresults::displayvector(CScientist s1)
{
    vector<CScientist> scientists;
    Domain d1;
    d1.search(scientists,s1);
    for(int i =0; i<scientists.size(); i++)
    {
    CScientist temp = scientists[i];
    string name = temp.getName();
    ui->scientistList->addItem(QString::fromStdString(name));
    }
}

void Searchresults::designScientistsList(vector<CScientist> scientists)
{
    ui->scientistList->clear();
}

void Searchresults::designComputersList(vector<Computer> computers)
{
    ui->computerList->clear();
}
*/
void Searchresults::setindex(int indexnumber)
{
    typeindex = indexnumber;
}

void Searchresults::initialize(int indexnumber, Computer c1, CScientist s1)
{
    if(indexnumber==0)
    {
        ui->pageWidget->setCurrentIndex(0);
        setindex(indexnumber);
        fillvector(s1);
    }
    if(indexnumber==1)
    {
        ui->pageWidget->setCurrentIndex(1);
        setindex(indexnumber);
        fillvector(c1);
    }

    displayAllScientists();
    displayAllComputers();
}

void Searchresults::fillvector(Computer c1){
    Domain d1;
    d1.search(compResults,c1);
    qDebug() << "size = ";
    qDebug() << compResults.size();
    qDebug() << typeindex;
}
void Searchresults::fillvector(CScientist s1){
    Domain d1;
    d1.search(sciResults,s1);
    //qDebug() << "size = ";
    //qDebug() << sciResults.size();
}

