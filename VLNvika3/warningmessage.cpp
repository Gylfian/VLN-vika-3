#include "warningmessage.h"
#include "ui_warningmessage.h"
Warningmessage::Warningmessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Warningmessage)
{
    ui->setupUi(this);
}

Warningmessage::~Warningmessage()
{
    delete ui;
}

void Warningmessage::addLabel()
{

}

void Warningmessage::on_buttonBox_accepted()
{
    accept();
}

void Warningmessage::on_buttonBox_rejected()
{
    reject();
}
