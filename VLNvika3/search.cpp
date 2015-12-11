#include "search.h"
#include "ui_search.h"
#include <iostream>

using namespace std;

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
}

Search::~Search()
{
    delete ui;
}



void Search::on_searchComboBox_currentIndexChanged(const QString &arg1)
{
    string option = arg1.toStdString();
    if(option == "Scientists")
    {
       ui->pageStacks->setCurrentIndex(0);
    }
    else if(option == "Computers")
    {
       ui->pageStacks->setCurrentIndex(1);
    }
}
