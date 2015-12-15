#ifndef ANALYZE_H
#define ANALYZE_H

#include "domain.h"
#include <QDialog>
#include <sstream>

namespace Ui {
class Analyze;
}

class Analyze : public QDialog
{
    Q_OBJECT

public:
    /*
     * Name: setScientist
     * Parameter/s: CScientist scientistToSet
     * Description: Gets all the information about the scientist, including a picture.
     * Usage: The user can see more detailed infomation about the scientist
     */
    void setScientist(CScientist scientistToSet);

    /*
     * Name: setComputer
     * Parameter/s: CScientist scientistToSet
     * Description: Gets all the information about the scientist, including a picture.
     * Usage: The user can see more detailed infomation about the scientist
     */
    void setComputer(Computer computerToSet);
    explicit Analyze(QWidget *parent = 0);
    ~Analyze();

private slots:
    void on_analyzeOk_accepted();

private:
    Ui::Analyze *ui;
    Domain dom;

    /*
     * Name: printSciBasicInfo
     * Parameter/s: None
     * Description: Prints out the basic infomation about the scientist
     * Usage: The user can see the scientists name, gender, birth year, death year(if the scientist is dead), quotes and books by the scientist
     * Output/Return: The basic information
     */
    void printSciBasicInfo();

    /*
     * Name: printSciDetailedInfo
     * Parameter/s: None
     * Description: Opens new window with more detailed information.
     */
    void printSciDetailedInfo();
    void getSciPicture();
    /*
     * Name: printComBasicInfo
     * Parameter/s: None
     * Description: Prints out the basic infomation about the computer
     * Usage: The user can see the computer name, type, if it was built or not and the year it was built
     * Output/Return: The basic information
     */
    void printComBasicInfo();
    void printComDetailedInfo();
    void getComPicture();
    CScientist scientist;
    Computer computer;
    void setDefaultPic();
};

#endif // ANALYZE_H
