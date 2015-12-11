#include "addentry.h"
#include "ui_addentry.h"
#include <string>
#include <QDebug>

using namespace std;

AddEntry::AddEntry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddEntry)
{
    ui->setupUi(this);
}

AddEntry::~AddEntry()
{
    delete ui;
}

void AddEntry::on_whichToPick_currentIndexChanged(const QString &arg1)
{
    string option = arg1.toStdString();
    if (option == "Scientist")
    {
        ui->whichToAdd->setCurrentIndex(1);
    }
    else if (option == "Computer")
    {
       ui->whichToAdd->setCurrentIndex(0);
    }
}

void AddEntry::on_sciDeadButton_clicked(bool checked)
{
    if (checked)
    {
        ui->sciDeathInput->setEnabled(true);
        int min = ui->sciBirthInput->value();
        ui->sciDeathInput->setMinimum(min);
    }
}

void AddEntry::on_sciAlivButton_clicked(bool checked)
{
    if(checked)
    {
        ui->sciDeathInput->setEnabled(false);
    }
}

void AddEntry::on_sciBirthInput_valueChanged(int arg1)
{
    if(ui->sciDeathInput->isEnabled())
    {
        ui->sciDeathInput->setMinimum(arg1);
    }
}

void AddEntry::on_comNotBuiltButton_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(false);
    }
}

void AddEntry::on_comBuiltButton_clicked(bool checked)
{
    if(checked)
    {
        ui->comYearBuiltInput->setEnabled(true);
    }
}
