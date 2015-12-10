#include "listoptions.h"
#include "ui_listoptions.h"
#include "domain.h"

ListOptions::ListOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOptions)
{
    ui->setupUi(this);
    displayAllScientists();
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

void ListOptions::displayScientists(vector <CScientist> scientists)
{
    ui->scientistsList->clear();
    for(int i = 0; i < scientists.size(); i++)
    {
        CScientist currentSci = scientists[i];
        ui->scientistsList->addItem(QString::fromStdString(currentSci.getName()));
    }
}
