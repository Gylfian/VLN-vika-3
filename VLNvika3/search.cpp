#include "search.h"
#include "ui_search.h"

using namespace std;

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);
    setWindowTitle("Advanced Search");

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

    CScientist s1(0,name,gender,dob,dod,1);
    Computer c1;
    accept();
    Searchresults results;
    results.initialize(0,c1,s1);
    results.exec();

}

void Search::on_addOrCancelSci_rejected()
{
    reject();
}



void Search::on_noRadio_clicked(bool checked)
{
    if(checked)
    {
        if(!ui->unknownDeath->isChecked())
        {
            ui->sciDeathInput->setEnabled(true);
        }
        ui->unknownDeath->setEnabled(true);
    }
}

void Search::on_yesRadio_clicked(bool checked)
{
    if(checked)
    {
        ui->sciDeathInput->setEnabled(false);
        ui->unknownDeath->setEnabled(false);
    }
}

void Search::on_unknownRadioAlive_clicked(bool checked)
{
    if(checked)
    {
        ui->sciDeathInput->setEnabled(false);
        ui->unknownDeath->setEnabled(false);
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
    if(ui->maleRadio->isChecked())
    {
        gender = "Male";
    }
    if(ui->femaleRadio->isChecked())
    {
        gender = "Female";
    }
    if(ui->unknownRadio->isChecked())
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

    if(ui->yesRadio->isChecked())
    {
        dod = "Alive";
    }
    if(ui->noRadio->isChecked())
    {
        if(ui->unknownDeath->isChecked())
        {
            return dod;
        }
        else
        {
        dod=ui->sciDeathInput->text().toStdString();
        }
    }

    return dod;
}

string Search::getBuilt()
{
    string built = "";
    if(ui->yesBuiltRadio->isChecked())
    {
        built = "Yes";
    }
    if(ui->noBuiltRadio->isChecked())
    {
        built = "No";
    }
    return built;
}

string Search::getBuiltYear()
{
    string builtyear = "";
    if(ui->yesBuiltRadio->isChecked())
    {
        builtyear = ui->comYearBuiltInput->text().toStdString();
    }
    return builtyear;
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
    string type = ui->comTypeInput->text().toStdString();
    string built = getBuilt();
    string builtyear = getBuiltYear();

    Computer c1(0,name,builtyear,type,built);
    CScientist s1;
    Searchresults results;
    results.initialize(1,c1,s1);
    results.exec();
    accept();

}

void Search::on_builtUnknown_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(false);
    }
    else if(checked==false)
    {
        ui->comYearBuiltInput->setEnabled(true);
    }
}

void Search::on_yesBuiltRadio_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(true);
        ui->builtUnknown->setEnabled(true);
    }
}

void Search::on_noBuiltRadio_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(false);
        ui->builtUnknown->setEnabled(false);
    }
}

void Search::on_maybeBuiltRadio_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(false);
        ui->builtUnknown->setEnabled(false);
    }
}

void Search::on_adddOrCancelComp_rejected()
{
    reject();
}


void Search::on_unknownDeath_clicked(bool checked)
{
    if(checked)
    {
    ui->sciDeathInput->setEnabled(false);
    }
    else
    {
    ui->sciDeathInput->setEnabled(true);
    }
}
