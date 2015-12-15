#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QDialog>
#include <string>
#include "domain.h"
#include <QMessageBox>
using namespace std;

namespace Ui {
class AddEntry;
}

class AddEntry : public QDialog
{
    Q_OBJECT

public:
    explicit AddEntry(QWidget *parent = 0);
    ~AddEntry();

private slots:

    /*
     * Name: on_whichToPick_currentIndexChanged
     * Parameter/s: const QString &arg1
     * Description: Pick which entry you want to add
     * Usage: Gives you two options, if the user picks the first option he has picked scientists, and if he picks the second option he has picked computers.
     * Output/Return: Scientist/Computer
     */
    void on_whichToPick_currentIndexChanged(const QString &arg1);

    void on_sciDeadButton_clicked(bool checked);

    void on_sciAlivButton_clicked(bool checked);

    /*
     * Name: on_sciBirthInput_valueChanged
     * Parameter/s: int arg1
     * Description: sets the birth year to the minimum value, which is 2015
     * Usage: The user cannot set the birth year higher then 2015, because that would mean that the scientist has not been born yet
     * Output/Return: 2015
     */
    void on_sciBirthInput_valueChanged(int arg1);

    void on_comNotBuiltButton_clicked(bool checked);

    void on_comBuiltButton_clicked(bool checked);

    /*
     * Name: on_addOrCancelSci_accepted
     * Parameter/s: None
     * Description: If the user has not filled out all the necessary information, he cannot add the scientist, but if he has, the scientist will be added
     * Usage: Sends out a message box with a warning "You must fill out all the necessary information!"
     * Output/Return: The message box
     */
    void on_addOrCancelSci_accepted();

    /*
     * Name: on_addOrCancelCom_accepted
     * Parameter/s: None
     * Description: If the user has not filled out all the necessary information, he cannot add the computer, but if he has, the computer will be added
     * Usage: Sends out a message box with a warning "You must fill out all the necessary information!"
     * Output/Return: The message box
     */
    void on_addOrCancelCom_accepted();

    void on_addOrCancelCom_rejected();

    void on_addOrCancelSci_rejected();

private:
    Ui::AddEntry *ui;

    /*
     * Name: getSciData
     * Parameter/s: None
     * Description: Reads the information given by the user, then puts them in the right places
     * Usage: Works with the infomation from user
     */
    CScientist getSciData();

    /*
     * Name: getComData
     * Parameter/s: None
     * Description: Read the information given by the user, then puts them in the right places
     * Usage: works with the information from user
     */
    Computer getComData();

    /*
     * Name: sciErrorCheck
     * Parameter/s: None
     * Description: Checks if the user has filled out all about the scientist
     * Usage: Checks if any of the info is missing
     */
    bool sciErrorCheck();

    /*
     * Name: comErrorCheck
     * Parameter/s: None
     * Description: Checks if the user has filled out all about the computer
     * Usage: Checks if any of the info is missing
     */
    bool comErrorCheck();
};

#endif // ADDENTRY_H
