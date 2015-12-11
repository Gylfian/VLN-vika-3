#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listoptions.h"

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

}

void MainWindow::on_pushButtonAddConnection_clicked()
{

}

void MainWindow::on_pushButtonSearch_clicked()
{

}

void MainWindow::on_pushButtonDelete_clicked()
{

}

void MainWindow::on_pushButtonExit_clicked()
{

}

void MainWindow::on_pushButtonListOptions_clicked()
{
    ListOptions listoptions;
    listoptions.setModal(true);
    listoptions.exec();
}
