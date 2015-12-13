#include "searchresults.h"
#include "ui_searchresults.h"

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
void Searchresults::initialize(int indexnumber)
{
    if(indexnumber==0)
    {
        ui->pageWidget->setCurrentIndex(0);
    }
    if(indexnumber==1)
    {
        ui->pageWidget->setCurrentIndex(1);
    }
}
