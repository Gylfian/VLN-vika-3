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
    //CScientist getsci();
    Ui::ListOptions *ui;
    ~ListOptions();
    void setUp();

private slots:
    void on_scientistsList_clicked(const QModelIndex &index);
    void on_editScientist_clicked();
    void on_scientistsList_doubleClicked(const QModelIndex &index);
    void on_analyzeScientistBotton_clicked();
    void on_findSciLineEdit_textChanged(const QString &arg1);
    void on_deleteScientistButton_clicked();
    void on_computersList_clicked(const QModelIndex &index);
    void on_editComputers_clicked();
    void on_computersList_doubleClicked(const QModelIndex &index);
    void on_analyzeComButton_clicked();
    void on_deleteComButton_clicked();
    void analyzeCom();
    void analyzeSci();
    void on_findComLineEdit_textChanged(const QString &arg1);

    void on_findConnLineEdit_textChanged(const QString &arg1);

    void on_cancelConnPushButton_clicked();

    void on_deletConnPushButton_clicked();

    void on_cancelComPushButton_clicked();

    void on_cancelSciPushButton_clicked();

    void on_connectionsList_clicked(const QModelIndex &index);

private:
    CScientist scientist;
    Computer computer;
    Domain domain;
    Relation relation;
    void displayAllScientists();
    void displayScientists(std::vector<CScientist> scientists);
    void designScientistsWidget(vector <CScientist> scientists);
    void displayComputers(vector<Computer> computers);
    void displayAllConnections();
    void displayAllComputers();
    void designComputersWidget(vector<Computer> computers);
    void designRelationsWidget(vector<Relation> relations);
    void displayRelations(vector<string> scientists, vector<string> computers);
    void displayConnections(vector<Relation> relations);
};

#endif // LISTOPTIONS_H
