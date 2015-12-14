#include "editcomputer.h"
#include "ui_editcomputer.h"
#include "computer.h"
#include "listoptions.h"
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
    Computer newInfo;
    Domain dom;
    //newInfo.setId(3); Hér kemur rétta id!
    newInfo.setName(name().toStdString());
    newInfo.setType(type().toStdString());
    newInfo.setBuilt(wasBuilt().toStdString());
    newInfo.setYear(yearBuilt().toStdString());
    accept();
    dom.editEntry(newInfo);
}

void Editcomputer::on_yesRadioButtonCom_clicked()
{
    ui->comBuiltYearSpinBox->setEnabled(true);
}

void Editcomputer::on_noRadioButtonCom_clicked()
{
    ui->comBuiltYearSpinBox->setEnabled(false);
}
