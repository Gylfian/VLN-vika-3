#include "searchresults.h"
#include "ui_searchresults.h"
#include "domain.h"

Searchresults::Searchresults(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Searchresults)
{
    ui->setupUi(this);
}

Searchresults::~Searchresults()
{
    delete ui;
}

void Searchresults::displayvector(Computer c1)
{
    vector<Computer> computers;
    Domain d1;
    d1.search(computers,c1);
}

void Searchresults::displayvector(CScientist s1)
{
    vector<CScientist> scientists;
    Domain d1;
    d1.search(scientists,s1);
}

void Searchresults::designScientistsList(vector<CScientist> scientists)
{

}

void Searchresults::designComputersList(vector<Computer> computers)
{

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
        displayvector(s1);
    }
    if(indexnumber==1)
    {
        ui->pageWidget->setCurrentIndex(1);
        setindex(indexnumber);
        displayvector(c1);
    }
}
