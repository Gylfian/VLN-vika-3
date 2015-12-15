#include "editscientist.h"
#include "listoptions.h"
#include "ui_listoptions.h"
#include "ui_editscientist.h"
#include "cscientist.h"
#include "domain.h"
#include <iostream>
using namespace std;

Editscientist::Editscientist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editscientist)
{
    ui->setupUi(this);
    setWindowTitle("Edit scientist");
}

Editscientist::~Editscientist()
{
    delete ui;
}


QString Editscientist:: name()
{
    QString name = ui->sciNameLineEdit->text();
    return name;
}

QString Editscientist:: gender()
{
    bool female = ui->femaleRadioPushButtonSci->isChecked();
    if(female)
        return "Female";
        return "Male";
}

QString Editscientist:: yearBorn()
{
    return ui->sciBirthYearSpinBox->text();
}


QString Editscientist:: yearOfDeath()
{
    return ui->sciDeathYearSpinBox->text();
}

void Editscientist::setScientist(CScientist scientistToSet)
{
    scientist = scientistToSet;
    ui->sciNameLineEdit->setText(QString::fromStdString(scientist.getName()));
    if(scientist.getGender() == "Female")
    {
        ui->maleRadioButton->setChecked(false);
        ui->femaleRadioPushButtonSci->setChecked(true);
    }
    else if(scientist.getGender() == "Male")
    {
        ui->femaleRadioPushButtonSci->setChecked(false);
        ui->maleRadioButton->setChecked(true);
    }
    Domain dom;
    ui->sciBirthYearSpinBox->setValue(dom.convertToInt(scientist.getDob()));
    if(scientist.getDod() == "")
    {
        ui->sciDeathYearSpinBox->setDisabled(true);
        ui->yesAliveButton->setChecked(true);
    }
    else
    {
        ui->sciDeathYearSpinBox->setValue(dom.convertToInt(scientist.getDod()));
        ui->noAliveButton->setChecked(true);
    }
}

void Editscientist::on_confirmSciEditPushButton_clicked()
{
    CScientist newInfo;
    Domain dom;
    newInfo = dom.findScientist(scientist);
    newInfo.setName(name().toStdString());
    newInfo.setGender(gender().toStdString());
    newInfo.setDob(yearBorn().toStdString());
    newInfo.setDod(yearOfDeath().toStdString());
    if(ui->yesAliveButton->isChecked())
       newInfo.setDod("Alive");
    accept();
    dom.editEntry(newInfo);
}

void Editscientist::on_backPushButtonEditSci_clicked()
{
    reject();
}

void Editscientist::on_noAliveButton_clicked()
{
    ui->sciDeathYearSpinBox->setEnabled(true);
}

void Editscientist::on_yesAliveButton_clicked()
{
    ui->sciDeathYearSpinBox->setEnabled(false);
}
