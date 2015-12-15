#ifndef SEARCHRESULTS_H
#define SEARCHRESULTS_H
#include "computer.h"
#include "cscientist.h"
#include <QDialog>

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
    void displayAllComputers();
    void displayAllScientists();
    void fillvector(Computer c1);
    void fillvector(CScientist s1);
    void displayComputers(vector<Computer> computers);
    void displayScientists(vector<CScientist> scientists);
    void designScientistsWidget(vector<CScientist> scientists);
    void designComputersWidget(vector<Computer> computers);
    void analyzeCom();
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
