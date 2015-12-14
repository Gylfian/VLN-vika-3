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


private:
    Ui::Searchresults *ui;
    void setindex(int indexnumber);
    int typeindex;
};

#endif // SEARCHRESULTS_H
