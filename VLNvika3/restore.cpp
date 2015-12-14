#include "restore.h"
#include "ui_restore.h"
#include "domain.h"
#include <QDebug>

Restore::Restore(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Restore)
{
    ui->setupUi(this);
    setUp();
}

Restore::~Restore()
{
    delete ui;
}

void Restore::setUp()
{

   CScientist s1;
   Computer c1;

    displayvector(s1);
    displayvector(c1);
}

void Restore::displayvector(Computer c1)
{
    vector<Computer> computers;
    Domain d1;
    d1.restoreEntry(computers);
    for(int i =0; i<computers.size(); i++)
    {
    Computer temp = computers[i];
    string name = temp.getName();
    ui->computerList->addItem(QString::fromStdString(name));
    }
}

void Restore::displayvector(CScientist s1)
{
    vector<CScientist> scientists;
    Domain d1;

    d1.restoreEntry(scientists);
    for(int i =0; i<scientists.size(); i++)
    {
    CScientist temp = scientists[i];
    qDebug() << QString::fromStdString("virkarsci");
    string name = temp.getName();
    ui->scientistList->addItem(QString::fromStdString(name));
    }
}

