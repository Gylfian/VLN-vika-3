#include "analyze.h"
#include "ui_analyze.h"

void Analyze::setScientist(CScientist scientistToSet)
{
    scientist = scientistToSet;
}

void Analyze::setComputer(Computer computerToSet)
{
    computer = computerToSet;
}

Analyze::Analyze(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Analyze)
{
    ui->setupUi(this);
}

Analyze::~Analyze()
{
    delete ui;
}
