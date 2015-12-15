#ifndef SEARCHRESULTS_H
#define SEARCHRESULTS_H
#include <QDialog>
#include "editscientist.h"
#include "editcomputer.h"
#include "domain.h"
#include "analyze.h"
#include <QMessageBox>

namespace Ui {
class Searchresults;
}

class Searchresults : public QDialog
{
    Q_OBJECT

public:
    explicit Searchresults(QWidget *parent = 0);
    void initialize(int indexnumber,Computer c1,CScientist s1);
    ~Searchresults();
    void displayvector(Computer c1);
    void displayvector(CScientist s1);
    void designScientistsList(vector <CScientist> scientists);
    void designComputersList(vector <Computer> computers);


    void setUp();

    /*
     * Name: displayAllComputers
     * Parameter/s: None
     * Description: Makes header for the table
     */
    void displayAllComputers();

    /*
     * Name: displayAllScientists
     * Parameter/s: None
     * Description: Makes header for the table
     */
    void displayAllScientists();

    /*
     * Name: fillvector
     * Parameter/s: Computer c1
     * Description: Fills the vector with the computer/s that were searched for
     */
    void fillvector(Computer c1);

    /*
     * Name: fillvector
     * Parameter/s: CScientist s1
     * Description: Fills the vector with the scientist/s that were searched for
     */
    void fillvector(CScientist s1);

    /*
     * Name: displayComputers
     * Parameter/s: vector<Computer> computer
     * Description: Fills the table with information
     * Output/Return: The list of computers
     */
    void displayComputers(vector<Computer> computers);

    /*
     * Name: displayScientists
     * Parameter/s: vector<CScientist> scientists
     * Description: Fills the table with information
     * Output/Return: The list of scientists
     */
    void displayScientists(vector<CScientist> scientists);

    /*
     * Name: designScientistsList
     * Parameter/s: vector<CScientist> scientists
     * Description: Makes the widget for scientists
     */
    void designScientistsWidget(vector<CScientist> scientists);

    /*
     * Name: designComputersWidget
     * Parameter/s: vector<Computer> computers
     * Description: Makes the widget for computers
     */
    void designComputersWidget(vector<Computer> computers);

    /*
     * Name: analyzeCom
     * Parameter/s: None
     * Description: Gets information about the computer the user has searched for
     * Usage: The user can see more detailed information about the computer
     * Output/Return: The Analyze window
     */
    void analyzeCom();

    /*
     * Name: analyzeSci
     * Parameter/s: None
     * Description: Gets information about the scientist the user has searched for
     * Usage: The user can see more detailed information about the scientist
     * Output/Return: The Analyze window
     */
    void analyzeSci();
private slots:

    void on_scientistList_clicked(const QModelIndex &index);

    void on_computerList_clicked(const QModelIndex &index);



    void on_editScientist_clicked();

    void on_editComputer_clicked();

    void on_analyzeComputer_clicked();

    void on_anlyzeScientist_clicked();

    void on_deleteComputer_clicked();

    void on_deleteScientist_clicked();

private:
    Ui::Searchresults *ui;
    void setindex(int indexnumber);
    int typeindex;
    vector<CScientist> sciResults;
    vector<Computer> compResults;
    CScientist scientist;
    Computer computer;
    CScientist sciParameter;
    Computer compParameter;
};

#endif // SEARCHRESULTS_H
