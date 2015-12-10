#include "listoptions.h"
#include "ui_listoptions.h"

ListOptions::ListOptions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListOptions)
{
    ui->setupUi(this);
}

ListOptions::~ListOptions()
{
    delete ui;
}
