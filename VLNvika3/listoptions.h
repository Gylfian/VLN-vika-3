#ifndef LISTOPTIONS_H
#define LISTOPTIONS_H
#include "cscientist.h"
#include "domain.h"
#include "computer.h"
#include "relation.h"
#include <QDialog>
#include <QTableWidget>
#include <iostream>
#include <vector>

namespace Ui {
class ListOptions;
}

class ListOptions : public QDialog
{
    Q_OBJECT

public:
    explicit ListOptions(QWidget *parent = 0);
    CScientist getsci();
    Ui::ListOptions *ui;
    ~ListOptions();

    void errorMessage();
private slots:
    //void onFindSciButtonClicked();
    void setCurrent();
    void on_findSciButton_clicked();
    void on_findComButton_clicked();

    //void on_scientistsList_clicked(const QModelIndex &index);

    void on_editScientist_clicked();


    void on_scientistsList_clicked(const QModelIndex &index);


    void on_editComputers_clicked();

    void on_computersList_clicked(const QModelIndex &index);

    void on_scientistsList_doubleClicked(const QModelIndex &index);

    void on_analyzeScientistBotton_clicked();

    void on_computersList_doubleClicked(const QModelIndex &index);

    void on_deleteComButton_clicked();

    void on_analyzeComButton_clicked();
    void analyzeCom();

    void on_findComLineEdit_textChanged(const QString &arg1);

    void on_findSciLineEdit_textChanged(const QString &arg1);

    void on_deleteScientistButton_clicked();

private:
    void displayAllScientists();
    void displayScientists(std::vector<CScientist> scientists);
    void designScientistsWidget(vector <CScientist> scientists);

    void displayComputers(vector<Computer> computers);
    //void displayConnections();
    void displayAllComputers();
    void designComputersWidget(vector<Computer> computers);
    CScientist scientist;
    Domain domain;
};

#endif // LISTOPTIONS_H
