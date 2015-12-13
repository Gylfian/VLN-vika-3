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
void initialize()
{

}
