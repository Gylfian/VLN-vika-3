#include "editscientist.h"
#include "ui_editscientist.h"
#include "cscientist.h"
#include <iostream>
#include <sstream>
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

void editScientist()
{

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
        return "f";
    else if(male)
        return "m";
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

void Editscientist::on_confirmSciEditPushButton_clicked()
{
    name();
    gender();
    yearBorn();
    yearOfDeath();
    accept();
}

void Editscientist::on_backPushButtonEditSci_clicked()
{
    reject();
}
