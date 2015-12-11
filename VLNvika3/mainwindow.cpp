#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listoptions.h"
#include "search.h"
#include "addentry.h"
#include "addconnection.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonAddEntry_clicked()
{
    AddEntry a1;
    a1.exec();
}

void MainWindow::on_pushButtonAddConnection_clicked()
{
    AddConnection a1;
    a1.exec();
}

void MainWindow::on_pushButtonSearch_clicked()
{
    Search s1;
    s1.exec();
}

void MainWindow::on_pushButtonDelete_clicked()
{

}

void MainWindow::on_pushButtonExit_clicked()
{
    exit(0);
}

void MainWindow::on_pushButtonListOptions_clicked()
{
    ListOptions listoptions;
    listoptions.exec();
}
