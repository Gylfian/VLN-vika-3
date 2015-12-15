#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H

#include "domain.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AddConnection;
}

class AddConnection : public QDialog
{
    Q_OBJECT

public:

    explicit AddConnection(QWidget *parent = 0);
    ~AddConnection();
    void enable();
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private slots:
    void on_dragScientists_entered(const QModelIndex &index);

    void on_dragScientists_clicked(const QModelIndex &index);

    void on_pushButton_clicked();


    void on_scientistsList_clicked(const QModelIndex &index);


    void on_computersList_clicked(const QModelIndex &index);

    void on_btnConnect_clicked();

private:
    Ui::AddConnection *ui;
    Domain domain;
    CScientist scientist;
    Computer computer;
    /*
     * Name: displayAllScientists
     * Parameter/s: None
     * Description: Displays list of scientists
     * Usage: Gets the scientists from the vector, and sends them to the sortBy function before it displays the list from the displayScientists function
     * Output/Return: List of scientists
     */
    void displayAllScientists();
    /*
     * Name: displayAllComputers
     * Parameter/s: None
     * Description: Displays list of computers
     * Usage: Gets the computers from the vector, and sends them to the sortBy function before it displays the list from the displayComputers function
     * Output/Return: List of computers
     */
    void displayAllComputers();

    /*
     * Name: displayScientists
     * Parameter/s: vector <CScientist> scientists
     * Description: Makes a table/widget for scientists and info
     * Usage: Takes the scientists from the vector and by using a for loop, fills in the table/widget.
     * Output/Return: Table/widget with Scientists and information about them
     */
    void displayScientists(vector <CScientist> scientists);

    /*
     * Name: displayComputers
     * Parameter/s: vector <Computer> computers
     * Description: Makes a table/widget for computers and info
     * Usage: Takes the computer from the vector and by using a for loop, fills in the table/widget
     * Output/Return: Table/widget with computers and information about them
     */
    void displayComputers(vector <Computer> computers);

    /*
     * Name:
     * Parameter/s:
     * Description:
     * Usage:
     * Output/Return:
     */
    void designScientistsWidget(vector <CScientist> scientists);
    void designComputersWidget(vector <Computer> computers);

    void setUp();
};

#endif // ADDCONNECTION_H
