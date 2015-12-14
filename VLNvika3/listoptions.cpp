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

void ListOptions::displayAllConnections()
{
    Domain d1;
    vector <Relation> relation;
    d1.getRelationList(relation);
    displayConnections(relation);
}

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

void ListOptions::displayConnections(vector<Relation> relations)
{
    CScientist sci;
    Computer com;
    designRelationsWidget(relations);
    for(int i = 0; i < relations.size(); i++)
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
    int size = computers.size();
    ui->computersList->setRowCount(size);

}

void ListOptions::designRelationsWidget(vector<Relation> cRelList)
{
    ui->connectionsList->clear();
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
    cout << ui->scientistsList->rowCount();
    if(ui->scientistsList->rowCount() == 0)
    QMessageBox::warning(this, "WARNING!", "No entries found!");
}

void ListOptions::on_editScientist_clicked()
{
   Editscientist editscientist;
   editscientist.setScientist(scientist);
   int wasRejected = editscientist.exec();
   if(wasRejected == QDialog::Rejected)
       return;
   scientist.setName(editscientist.name().toStdString());
   scientist.setGender(editscientist.gender().toStdString());
   scientist.setDob(editscientist.yearBorn().toStdString());
   if(editscientist.yearOfDeath().toStdString() == "0")
      scientist.setDod("Alive");
   else
      scientist.setDod(editscientist.yearOfDeath().toStdString());
   CScientist temp = domain.findScientist(scientist);
   cout << temp.getId();
   domain.editEntry(temp);
   displayAllScientists();
}

void ListOptions::on_scientistsList_doubleClicked(const QModelIndex &index)
{
    Analyze analyze;
    analyze.setScientist(scientist);
    analyze.exec();
}

void ListOptions::on_analyzeScientistBotton_clicked()
{
    analyzeCom();
}

void ListOptions::on_findSciLineEdit_textChanged(const QString &arg1)
{
    ui->editScientist->setEnabled(false);
    ui->analyzeScientistBotton->setEnabled(false);
    ui->deleteScientistButton->setEnabled(false);
    ui->findSciButton->setEnabled(true);
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
    int row = ui->scientistsList->currentRow();
    string name = ui->scientistsList->item(row, 0)->text().toStdString();
    string gender = ui->scientistsList->item(row, 1)->text().toStdString();
    string yearBorn = ui->scientistsList->item(row, 2)->text().toStdString();
    string yearOfDeath = ui->scientistsList->item(row, 3)->text().toStdString();
    CScientist temp(row, name, gender, yearBorn, yearOfDeath, true);
    stringstream ss;
    ss << row;
    string id = ss.str();
    int ret = QMessageBox::warning(this, tr("Warning"), tr("You are about to delete a scientist!\n" "Do you want to continue?"), QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QDialog::Rejected)
    {
        return;
    }
    domain.updateEntrySci(id);
}

void ListOptions::on_computersList_clicked(const QModelIndex &index)
{
    int row = ui->computersList->currentRow();
    ui->editComputers->setEnabled(true);
    ui->analyzeComButton->setEnabled(true);
    ui->deleteComButton->setEnabled(true);
    computer.setName(ui->computersList->item(row, 0)->text().toStdString());
    computer.setType(ui->computersList->item(row, 1)->text().toStdString());
    computer.setBuilt(ui->computersList->item(row, 2)->text().toStdString());
    computer.setYear(ui->computersList->item(row, 3)->text().toStdString());
}

void ListOptions::on_findComButton_clicked()
{
    string searchString = ui->findComLineEdit->text().toStdString();
    vector <Computer> computers;
    Computer temp;
    domain.sortBy(computers, 1, 1);
    temp.setName(searchString);
    domain.search(computers, temp);
    displayComputers(computers);
    if(ui->computersList->rowCount() == 0)
    QMessageBox::warning(this, "WARNING!", "No entries found!");
}

void ListOptions::on_editComputers_clicked()
{
    Editcomputer editcomputer;
    editcomputer.setComputer(computer);
    int wasRejected = editcomputer.exec();
    if(wasRejected == QDialog::Rejected)
        return;
    computer.setName(editcomputer.name().toStdString());
    computer.setType(editcomputer.type().toStdString());
    computer.setBuilt(editcomputer.wasBuilt().toStdString());
    if(editcomputer.yearBuilt().toStdString() == "0")
    ;
    else
       computer.setYear(editcomputer.yearBuilt().toStdString());
    //findcom
    displayAllComputers();
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
    ui->findComButton->setEnabled(true);
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
    int row = ui->computersList->currentRow();
    string name = ui->computersList->item(row, 0)->text().toStdString();
    string type = ui->computersList->item(row, 1)->text().toStdString();
    string wasBuilt = ui->computersList->item(row, 2)->text().toStdString();
    string yearBuilt = ui->computersList->item(row, 3)->text().toStdString();
    Computer temp(row, name, yearBuilt, type, wasBuilt);
    stringstream ss;
    ss << row;
    string id = ss.str();
    int ret = QMessageBox::warning(this, tr("Warning"), tr("You are about to delete a computer!\n" "Do you want to continue?"), QMessageBox::Ok | QMessageBox::Cancel);
    if(ret == QDialog::Rejected)
    {
        return;
    }
    domain.updateEntryCom(id);
}

void ListOptions::analyzeCom()
{
    int row = ui->computersList->currentRow();
    string name = ui->computersList->item(row, 0)->text().toStdString();
    string type = ui->computersList->item(row, 1)->text().toStdString();
    string wasBuilt = ui->computersList->item(row, 2)->text().toStdString();
    string year = ui->computersList->item(row, 3)->text().toStdString();
    if(ui->scientistsList->rowCount() == 0)
        QMessageBox::warning(this, "WARNING!", "No entries found!");
    else
    {
        Analyze analyze;
        analyze.exec();
    }
}

void ListOptions::setUp()
{
    setWindowTitle("List options");
    ui->scientistsList->setColumnWidth(0, 160);
    ui->scientistsList->setColumnWidth(1, 70);
    ui->scientistsList->setColumnWidth(2, 90);
    ui->scientistsList->setColumnWidth(3, 100);
    ui->computersList->setColumnWidth(0, 150);
    ui->computersList->setColumnWidth(1, 115);
    ui->computersList->setColumnWidth(2, 55);
    ui->computersList->setColumnWidth(3, 100);
    ui->connectionsList->setColumnWidth(0, 230);
    ui->connectionsList->setColumnWidth(1, 210);
    displayAllScientists();
    displayAllComputers();
    displayAllConnections();
}
