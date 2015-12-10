#include "addentry.h"
#include "ui_addentry.h"

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
