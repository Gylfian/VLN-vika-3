#include "searchresults.h"
#include "ui_searchresults.h"
#include "editscientist.h"
#include "editcomputer.h"
#include "domain.h"
#include "analyze.h"
#include <QMessageBox>

Searchresults::Searchresults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Searchresults)
{
    ui->setupUi(this);
    ui->computerList->setRowCount(5);
    ui->scientistList->setRowCount(5);
    ui->computerList->setColumnCount(4);
    ui->scientistList->setColumnCount(4);
    setWindowTitle("Search Results");
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
        sciParameter = s1;
        fillvector(s1);
    }
    if(indexnumber==1)
    {
        ui->pageWidget->setCurrentIndex(1);
        setindex(indexnumber);
        compParameter = c1;
        fillvector(c1);
    }

    displayAllScientists();
    displayAllComputers();
}

void Searchresults::fillvector(Computer c1){
    Domain d1;
    d1.search(compResults,c1);

}
void Searchresults::fillvector(CScientist s1){
    Domain d1;
    d1.search(sciResults,s1);

}


void Searchresults::on_scientistList_clicked(const QModelIndex &index)
{
     int row = ui->scientistList->currentRow();
     ui->scientistList->selectRow(index.row());
     ui->anlyzeScientist->setEnabled(true);
     ui->editScientist->setEnabled(true);
     ui->deleteScientist->setEnabled(true);
     scientist.setName(ui->scientistList->item(row, 0)->text().toStdString());
     scientist.setGender(ui->scientistList->item(row, 1)->text().toStdString());
     scientist.setDob(ui->scientistList->item(row, 2)->text().toStdString());
     scientist.setDod(ui->scientistList->item(row, 3)->text().toStdString());
}

void Searchresults::on_computerList_clicked(const QModelIndex &index)
{
   int row = ui->computerList->currentRow();
   ui->computerList->selectRow(index.row());
   ui->analyzeComputer->setEnabled(true);
   ui->editComputer->setEnabled(true);
   ui->deleteComputer->setEnabled(true);
   computer.setName(ui->computerList->item(row, 0)->text().toStdString());
   computer.setType(ui->computerList->item(row, 1)->text().toStdString());
   computer.setBuilt(ui->computerList->item(row, 2)->text().toStdString());
   computer.setYear(ui->computerList->item(row, 3)->text().toStdString());
}


void Searchresults::on_editScientist_clicked()
{
    Editscientist editscientist;
    editscientist.setScientist(scientist);
    int wasRejected = editscientist.exec();
    if(wasRejected == QDialog::Rejected)
        return;
    fillvector(sciParameter);
    displayAllScientists();
}


void Searchresults::on_editComputer_clicked()
{
    Editcomputer editcomputer;
    editcomputer.setComputer(computer);
    int wasRejected = editcomputer.exec();
    if(wasRejected == QDialog::Rejected)
        return;
    fillvector(compParameter);
    displayAllComputers();
}

void Searchresults::on_analyzeComputer_clicked()
{
     analyzeCom();
}

void Searchresults::on_anlyzeScientist_clicked()
{
    analyzeSci();
}

void Searchresults::analyzeSci()
{
    if(ui->scientistList->rowCount() == 0)
        QMessageBox::warning(this, "WARNING!", "No entries found!");
    else
    {
        int row = ui->scientistList->currentRow();
        scientist.setName(ui->scientistList->item(row, 0)->text().toStdString());
        scientist.setGender(ui->scientistList->item(row, 1)->text().toStdString());
        scientist.setDob(ui->scientistList->item(row, 2)->text().toStdString());
        scientist.setDod(ui->scientistList->item(row, 3)->text().toStdString());
        Analyze analyze;
        analyze.setScientist(scientist);
        analyze.exec();
    }
}

void Searchresults::analyzeCom()
{
    if(ui->computerList->rowCount() == 0)
        QMessageBox::warning(this, "WARNING!", "No entries found!");
    else
    {
        int row = ui->computerList->currentRow();
        computer.setName(ui->computerList->item(row, 0)->text().toStdString());
        computer.setType(ui->computerList->item(row, 1)->text().toStdString());
        computer.setBuilt(ui->computerList->item(row, 2)->text().toStdString());
        computer.setYear(ui->computerList->item(row, 3)->text().toStdString());
        Analyze analyze;
        analyze.setComputer(computer);
        analyze.exec();
    }
}


void Searchresults::on_deleteComputer_clicked()
{
    int ret = QMessageBox::warning(this, tr("Warning"), tr("You are about to delete a computer!\n" "Do you want to continue?"), QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QDialog::Rejected)
    {
        return;
    }
    Domain d1;
    Computer temp = d1.findComputer(computer);
    stringstream ss;
    ss << temp.getId();
    string id = ss.str();
    d1.updateEntryCom(id);
    fillvector(compParameter);
    displayAllComputers();
}


void Searchresults::on_deleteScientist_clicked()
{
    int ret = QMessageBox::warning(this, tr("Warning"), tr("You are about to delete a scientist!\n" "Do you want to continue?"), QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QDialog::Rejected)
    {
        return;
    }
    Domain d1;
    CScientist temp = d1.findScientist(scientist);
    stringstream ss;
    ss << temp.getId();
    string id = ss.str();
    d1.updateEntrySci(id);
    fillvector(sciParameter);
    displayAllScientists();
}
