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

    /*
     * Name: displayAllScientists
     * Parameter/s: None
     * Description: Displays list of scientists
     * Usage: Gets the scientists from the vector, and sends them to the sortBy function before it displays the list from the displayScientists function
     * Output/Return: List of scientists
     */
    void displayAllScientists();

    /*
     * Name: displayScientists
     * Parameter/s: vector <CScientist> scientists
     * Description: Fills the table for scientists and info
     * Usage: Takes the scientists from the vector and by using a for loop, fills in the table/widget.
     * Output/Return: Table/widget with Scientists and information about them
     */
    void displayScientists(std::vector<CScientist> scientists);

    /*
     * Name: designScientistsWidget
     * Parameter/s: vector <CScientist> scientists
     * Description: Makes the widget for scientist
     */
    void designScientistsWidget(vector <CScientist> scientists);

    /*
     * Name: displayComputers
     * Parameter/s: vector <Computer> computers
     * Description: Fills the table for computers and info
     * Usage: Takes the computer from the vector and by using a for loop, fills in the table/widget
     * Output/Return: Table/widget with computers and information about them
     */
    void displayComputers(vector<Computer> computers);

    /*
     * Name: displayAllConnections
     * Parameter/s: None
     * Description: Displays list of relations
     * Usage: Gets the connections from the vector, and sends them to the sortBy function before it displays the list from the displayConnections function
     * Output/Return: List of connections
     */
    void displayAllConnections();

    /*
     * Name: displayAllComputers
     * Parameter/s: None
     * Description: Displays list of computers
     * Usage: Gets the computers from the vector, and sends them to the sortBy function before it displays the list from the displayComputers function
     * Output/Return: List of computers
     */
    void displayAllComputers();

    /*
     * Name: designComputerWidget
     * Parameter/s: vector <Computer> computers
     * Description: Makes the widget for computers
     */
    void designComputersWidget(vector<Computer> computers);

    /*
     * Name: designRelationsWidget
     * Parameter/s: vector <Relation> relations
     * Description: Makes the widget for relations
     */
    void designRelationsWidget(vector<Relation> relations);

    /*
     * Name: displayConnections
     * Parameter/s: vector <Relation> relations
     * Description: Fills the table for connections
     * Usage: Takes the relations from the vector and by using a for loop, fills in the table
     * Output/Return: Table/widget with connections
     */
    void displayConnections(vector<Relation> relations);
};

#endif // LISTOPTIONS_H
