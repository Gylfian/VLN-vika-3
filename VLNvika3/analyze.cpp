#include "analyze.h"
#include "ui_analyze.h"

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
