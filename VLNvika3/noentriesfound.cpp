#include "noentriesfound.h"
#include "ui_noentriesfound.h"

Noentriesfound::Noentriesfound(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Noentriesfound)
{
    ui->setupUi(this);
}

Noentriesfound::~Noentriesfound()
{
    delete ui;
}

void Noentriesfound::on_pushButton_clicked()
{
    accept();
}
