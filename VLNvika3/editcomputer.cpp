#include "editcomputer.h"
#include "ui_editcomputer.h"
#include <iostream>
using namespace std;

Editcomputer::Editcomputer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Editcomputer)
{
    ui->setupUi(this);
    QStringList types;
    types << "Homecomputer" << "Mechanical" << "Electromechanical" << "Electronic Digital" << "Chess computer" << "Electronic digital programmable" << "Microcomputer";
    ui->comTypeComboBox->addItems(types);
}

Editcomputer::~Editcomputer()
{
    delete ui;
}

void Editcomputer:: setComputer(Computer computerToSet)
{
    ui->comNameLineEdit->setText(QString::fromStdString(computerToSet.getName()));
    ui->comTypeComboBox->setCurrentText(QString::fromStdString(computerToSet.getType()));
    if(computerToSet.getBuilt() == "Yes")
    {
        ui->yesRadioButtonCom->setChecked(true);
        ui->comBuiltYearSpinBox->setEnabled(true);
    }
    else if(computerToSet.getBuilt() == "No")
    {
        ui->noRadioButtonCom->setChecked(true);
        ui->comBuiltYearSpinBox->setEnabled(false);
    }
    Domain dom;
    ui->comBuiltYearSpinBox->setValue(dom.convertToInt(computerToSet.getYear()));
}

QString Editcomputer:: name()
{
    QString name = ui->comNameLineEdit->text();
    return name;
}

QString Editcomputer:: type()
{
    QString type = ui->comTypeComboBox->currentText();
    return type;
}

QString Editcomputer::wasBuilt()
{
    bool yes = ui->yesRadioButtonCom->isChecked();
    bool no = ui->noRadioButtonCom->isChecked();
    if(yes)
        return "Yes";
    else if(no)
        return "No";
    return "u";
}

QString Editcomputer:: yearBuilt()
{
    return ui->comBuiltYearSpinBox->text();
}

void Editcomputer::on_backPushButtonEditCom_clicked()
{
    reject();
}

void Editcomputer::on_confirmComEditPushButton_clicked()
{
    name();
    type();
    wasBuilt();
    yearBuilt();
    accept();
}

void Editcomputer::on_yesRadioButtonCom_clicked()
{
    ui->comBuiltYearSpinBox->setEnabled(true);
}

void Editcomputer::on_noRadioButtonCom_clicked()
{
    ui->comBuiltYearSpinBox->setEnabled(false);
}
