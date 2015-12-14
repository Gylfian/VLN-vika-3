#ifndef ANALYZE_H
#define ANALYZE_H

#include "cscientist.h"
#include "computer.h"
#include <QDialog>

namespace Ui {
class Analyze;
}

class Analyze : public QDialog
{
    Q_OBJECT

public:
    void setScientist(CScientist scientistToSet);
    void setComputer(Computer computerToSet);
    explicit Analyze(QWidget *parent = 0);
    ~Analyze();

private slots:
    void on_analyzeOk_accepted();

private:
    Ui::Analyze *ui;
    void printSciBasicInfo();
    void printSciDetailedInfo();
    void getSciPicture();
    void printComBasicInfo();
    void printComDetailedInfo();
    void getComPicture();
    CScientist scientist;
    Computer computer;

};

#endif // ANALYZE_H
