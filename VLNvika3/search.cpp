#include "search.h"
#include "ui_search.h"
#include <iostream>
#include "cscientist.h"
#include "domain.h"
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
    if (option == "Scientist")
    {
        ui->pageStack->setCurrentIndex(1);
    }
    else if (option == "Computer")
    {
       ui->pageStack->setCurrentIndex(0);
    }
}

void Search::on_addOrCancelSci_accepted()
{
    string name = ui->sciNameInput->text().toStdString();
    string gender =getGender();
    string dob = getdob();
    string dod = getdod();

    CScientist c1(0,name,gender,dob,dod,1);
    Domain d1;
    vector<CScientist> Scientists;
    d1.search(Scientists,c1);
    accept();
}

void Search::on_addOrCancelSci_rejected()
{
    rejected();
}



void Search::on_noRadio_clicked(bool checked)
{
    if(checked)
    {
        ui->sciDeathInput->setEnabled(true);
    }
}

void Search::on_yesRadio_clicked(bool checked)
{
    if(checked)
    {
        ui->sciDeathInput->setEnabled(false);
    }
}

void Search::on_unknownRadioAlive_clicked(bool checked)
{
    if(checked)
    {
        ui->sciDeathInput->setEnabled(false);
    }
}


void Search::on_checkBox_clicked(bool checked)
{
    if(checked)
    {
        ui->sciBirthInput->setEnabled(false);
    }
    else
    {
        ui->sciBirthInput->setEnabled(true);
    }
}

string Search::getGender()
{
    string gender = "";
    if(ui->maleRadio->isEnabled())
    {
        gender = "Male";
    }
    if(ui->femaleRadio->isEnabled())
    {
        gender = "Female";
    }
    if(ui->unknownRadio->isEnabled())
    {
        gender = "";
    }
    return gender;
}

string Search::getdob()
{
    string dob = "";

    if(ui->sciBirthInput->isEnabled())
    {
         dob=ui->sciBirthInput->text().toStdString();
    }

    return dob;
}

string Search::getdod()
{
    string dod = "";

    if(ui->yesRadio->isEnabled())
    {
        dod = "Alive";
    }
    if(ui->noRadio->isEnabled())
    {
        dod=ui->sciDeathInput->text().toStdString();
    }

    return dod;
}

string Search::getBuilt()
{
    string built = "";
    //if(ui->yesBuiltRadio->isEnabled())
}

void Search::on_comBuiltButton_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(true);
    }
}

void Search::on_comNotBuiltButton_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(false);
    }
}

void Search::on_comUnawareButton_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(false);
    }
}

void Search::on_adddOrCancelComp_accepted()
{
    string name = ui->comNameInput->text().toStdString();
    string type = ui->comTypeText->text().toStdString();

}
