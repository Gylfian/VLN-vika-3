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
    bool male = ui->maleRadioButton->isChecked();
    if(female)
        return "Female";
    else if(male)
        return "Male";
    return "u";
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
        ui->femaleRadioPushButtonSci->setChecked(true);
    else if(scientist.getGender() == "Male")
        ui->maleRadioButton->setChecked(true);
    Domain dom;
    ui->sciBirthYearSpinBox->setValue(dom.convertToInt(scientist.getDob()));
    ui->sciDeathYearSpinBox->setValue(dom.convertToInt(scientist.getDod()));
}

void Editscientist::on_confirmSciEditPushButton_clicked()
{
    CScientist newInfo;
    Domain dom;
    //newInfo.setId(3); Hér kemur rétta id!
    newInfo.setName(name().toStdString());
    newInfo.setGender(gender().toStdString());
    newInfo.setDob(yearBorn().toStdString());
    newInfo.setDod(yearOfDeath().toStdString());
    accept();
    dom.editEntry(newInfo);
}

void Editscientist::on_backPushButtonEditSci_clicked()
{
    reject();
}
