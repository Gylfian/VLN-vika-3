#include "listoptions.h"
#include "ui_listoptions.h"
#include "domain.h"
#include "editscientist.h"
#include "editcomputer.h"
#include "analyze.h"
#include "ui_analyze.h"
#include <QMessageBox>
#include <QDebug>

ListOptions::ListOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOptions)
{
    ui->setupUi(this);
    setUp();
    ui->scientistsList->setHorizontalHeaderLabels(QString("Name;Gender;Birth year;Death year").split(";"));
    ui->computersList->setHorizontalHeaderLabels(QString("Name;Type;Built?;Year built").split(";"));
    ui->connectionsList->setHorizontalHeaderLabels(QString("Scienist name; Computer name").split(";"));
}

ListOptions::~ListOptions()
{
    delete ui;
}

void ListOptions::displayAllScientists()
{
    vector <CScientist> scientists;
    domain.sortBy(scientists, 1, 1);
    displayScientists(scientists);
}

void ListOptions::displayAllComputers()
{
    vector <Computer> computers;
    domain.sortBy(computers, 1, 1);
    displayComputers(computers);
}

void ListOptions::displayAllConnections()
{
    vector <Relation> relation;
    domain.getRelationList(relation, 1);
    displayConnections(relation);
}

void ListOptions::displayScientists(vector <CScientist> scientists)
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

void ListOptions::displayComputers(vector <Computer> computers)
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

void ListOptions::displayConnections(vector<Relation> relations)
{
    CScientist sci;
    Computer com;
    designRelationsWidget(relations);
    for(unsigned int i = 0; i < relations.size(); i++)
    {
        sci = relations[i].getScientist();
        com = relations[i].getComputer();
        ui->connectionsList->setItem(i,0,new QTableWidgetItem(QString::fromStdString(sci.getName())));
        ui->connectionsList->setItem(i,1,new QTableWidgetItem(QString::fromStdString(com.getName())));
    }
}

void ListOptions::designScientistsWidget(vector <CScientist> scientists)
{
    ui->scientistsList->clear();
    ui->scientistsList->setHorizontalHeaderLabels(QString("Name;Gender;Birth year;Death year").split(";"));
    int size = scientists.size();
    ui->scientistsList->setRowCount(size);
}

void ListOptions::designComputersWidget(vector <Computer> computers)
{
    ui->computersList->clear();
    ui->computersList->setHorizontalHeaderLabels(QString("Name;Type;Built?;Year built").split(";"));
    int size = computers.size();
    ui->computersList->setRowCount(size);
}

void ListOptions::designRelationsWidget(vector<Relation> cRelList)
{
    ui->connectionsList->clear();
    ui->connectionsList->setHorizontalHeaderLabels(QString("Scienist name; Computer name").split(";"));
    int size = cRelList.size();
    ui->connectionsList->setRowCount(size);
}

void ListOptions::on_scientistsList_clicked(const QModelIndex &index)
{
    int row = ui->scientistsList->currentRow();
    ui->scientistsList->selectRow(index.row());
    ui->editScientist->setEnabled(true);
    ui->analyzeScientistBotton->setEnabled(true);
    ui->deleteScientistButton->setEnabled(true);
    scientist.setName(ui->scientistsList->item(row, 0)->text().toStdString());
    scientist.setGender(ui->scientistsList->item(row, 1)->text().toStdString());
    scientist.setDob(ui->scientistsList->item(row, 2)->text().toStdString());
    scientist.setDod(ui->scientistsList->item(row, 3)->text().toStdString());
}

void ListOptions::on_editScientist_clicked()
{
   Editscientist editscientist;
   editscientist.setScientist(scientist);
   int wasRejected = editscientist.exec();
   if(wasRejected == QDialog::Rejected)
       return;
   displayAllScientists();
   ui->editScientist->setEnabled(false);
   ui->analyzeScientistBotton->setEnabled(false);
   ui->deleteScientistButton->setEnabled(false);
}

void ListOptions::on_scientistsList_doubleClicked(const QModelIndex &index)
{
    analyzeSci();
}

void ListOptions::on_analyzeScientistBotton_clicked()
{
    analyzeSci();
}

void ListOptions::on_findSciLineEdit_textChanged(const QString &arg1)
{
    ui->editScientist->setEnabled(false);
    ui->analyzeScientistBotton->setEnabled(false);
    ui->deleteScientistButton->setEnabled(false);
    string searchString = ui->findSciLineEdit->text().toStdString();
    vector <CScientist> scientists;
    CScientist temp;
    domain.sortBy(scientists, 1, 1);
    temp.setName(searchString);
    domain.search(scientists, temp);
    displayScientists(scientists);
}

void ListOptions::on_deleteScientistButton_clicked()
{
    int ret = QMessageBox::warning(this, tr("Warning"), tr("You are about to delete a scientist!\n" "Do you want to continue?"), QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QDialog::Rejected)
    {
        return;
    }
    CScientist temp = domain.findScientist(scientist);
    stringstream ss;
    ss << temp.getId();
    string id = ss.str();
    //domain.removeConnections(id);
    domain.updateEntrySci(id);
    displayAllScientists();
}

void ListOptions::on_computersList_clicked(const QModelIndex &index)
{
    int row = ui->computersList->currentRow();
    ui->computersList->selectRow(index.row());
    ui->editComputers->setEnabled(true);
    ui->analyzeComButton->setEnabled(true);
    ui->deleteComButton->setEnabled(true);
    computer.setName(ui->computersList->item(row, 0)->text().toStdString());
    computer.setType(ui->computersList->item(row, 1)->text().toStdString());
    computer.setBuilt(ui->computersList->item(row, 2)->text().toStdString());
    computer.setYear(ui->computersList->item(row, 3)->text().toStdString());
}

void ListOptions::on_editComputers_clicked()
{
    Editcomputer editcomputer;
    editcomputer.setComputer(computer);
    int wasRejected = editcomputer.exec();
    if(wasRejected == QDialog::Rejected)
        return;
    displayAllComputers();
    ui->editComputers->setEnabled(false);
    ui->analyzeComButton->setEnabled(false);
    ui->deleteComButton->setEnabled(false);
}

void ListOptions::on_computersList_doubleClicked(const QModelIndex &index)
{
    analyzeCom();
}

void ListOptions::on_analyzeComButton_clicked()
{
    analyzeCom();
}

void ListOptions::on_findComLineEdit_textChanged(const QString &arg1)
{
    ui->editComputers->setEnabled(false);
    ui->analyzeComButton->setEnabled(false);
    ui->deleteComButton->setEnabled(false);
    string searchString = ui->findComLineEdit->text().toStdString();
    vector <Computer> computers;
    Domain d1;
    Computer temp;
    domain.sortBy(computers, 1, 1);
    temp.setName(searchString);
    domain.search(computers, temp);
    displayComputers(computers);
}

void ListOptions::on_deleteComButton_clicked()
{
    int ret = QMessageBox::warning(this, tr("Warning"), tr("You are about to delete a computer!\n" "Do you want to continue?"), QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QDialog::Rejected)
    {
        return;
    }
    Computer temp = domain.findComputer(computer);
    stringstream ss;
    ss << temp.getId();
    string id = ss.str();
    domain.updateEntryCom(id);
    displayAllComputers();
}

void ListOptions::analyzeCom()
{
    if(ui->computersList->rowCount() == 0)
        QMessageBox::warning(this, "WARNING!", "No entries found!");
    else
    {
        int row = ui->computersList->currentRow();
        computer.setName(ui->computersList->item(row, 0)->text().toStdString());
        computer.setType(ui->computersList->item(row, 1)->text().toStdString());
        computer.setBuilt(ui->computersList->item(row, 2)->text().toStdString());
        computer.setYear(ui->computersList->item(row, 3)->text().toStdString());
        Analyze analyze;
        analyze.setComputer(computer);
        analyze.exec();
    }
}

void ListOptions::analyzeSci()
{
    if(ui->scientistsList->rowCount() == 0)
        QMessageBox::warning(this, "WARNING!", "No entries found!");
    else
    {
        int row = ui->scientistsList->currentRow();
        scientist.setName(ui->scientistsList->item(row, 0)->text().toStdString());
        scientist.setGender(ui->scientistsList->item(row, 1)->text().toStdString());
        scientist.setDob(ui->scientistsList->item(row, 2)->text().toStdString());
        scientist.setDod(ui->scientistsList->item(row, 3)->text().toStdString());
        Analyze analyze;
        analyze.setScientist(scientist);
        analyze.exec();
    }
}

void ListOptions::setUp()
{
    setWindowTitle("List options");
    ui->scientistsList->setColumnWidth(0, 183);
    ui->scientistsList->setColumnWidth(1, 70);
    ui->scientistsList->setColumnWidth(2, 90);
    ui->scientistsList->setColumnWidth(3, 100);
    ui->computersList->setColumnWidth(0, 140);
    ui->computersList->setColumnWidth(1, 153);
    ui->computersList->setColumnWidth(2, 55);
    ui->computersList->setColumnWidth(3, 100);
    ui->connectionsList->setColumnWidth(0, 230);
    ui->connectionsList->setColumnWidth(1, 230);
    displayAllScientists();
    displayAllComputers();
    displayAllConnections();
}

void ListOptions::on_findConnLineEdit_textChanged(const QString &arg1)
{
    ui->deletConnPushButton->setEnabled(false);
    string searchString = ui->findConnLineEdit->text().toStdString();
    vector <Relation> relations = domain.findRelation(searchString);
    displayConnections(relations);
}

void ListOptions::on_cancelConnPushButton_clicked()
{
    reject();
}

void ListOptions::on_deletConnPushButton_clicked()
{
    int ret = QMessageBox::warning(this, tr("Warning"), tr("You are about to delete a connection!\n" "Do you want to continue?"), QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QDialog::Rejected)
    {
        return;
    }
    if(ui->connectionsList->rowCount() == 0)
        QMessageBox::warning(this, "WARNING!", "No entries found!");
    else
    {
        //domain.changeRelation("8");
        int row = ui->connectionsList->currentRow();
        scientist.setName(ui->connectionsList->item(row, 0)->text().toStdString());
        computer.setName(ui->connectionsList->item(row, 1)->text().toStdString());
        int id = domain.findConnectionId(scientist.getName(), computer.getName());
        domain.removeRelations(id);
    }
    displayAllConnections();
    ui->deletConnPushButton->setEnabled(false);
}

void ListOptions::on_cancelComPushButton_clicked()
{
    reject();
}

void ListOptions::on_cancelSciPushButton_clicked()
{
    reject();
}

void ListOptions::on_connectionsList_clicked(const QModelIndex &index)
{
    ui->connectionsList->selectRow(index.row());
    int row = ui->connectionsList->currentRow();
    ui->deletConnPushButton->setEnabled(true);
    relation.setScientistName(ui->computersList->item(row, 0)->text().toStdString());
    relation.setComputerName(ui->computersList->item(row, 1)->text().toStdString());
}
