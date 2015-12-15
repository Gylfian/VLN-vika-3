#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include <QComboBox>
#include "computer.h"
#include "domain.h"

namespace Ui {
class Editcomputer;
}

class Editcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit Editcomputer(QWidget *parent = 0);
    ~Editcomputer();
    void setComputer(Computer computerToSet);

    /*
     * Name: name
     * Description: Changes the name of the computer
     * Output/Return: The new name
     */
    QString name();

    /*
     * Name: type
     * Description: Changes the type of the computer
     * Output/Return: The new type
     */
    QString type();

    /*
     * Name: wasBuilt
     * Description: Changes to if it was built or not
     * Output/Return: The new information if it was built or not
     */
    QString wasBuilt();

    /*
     * Name: yearBuilt
     * Description: Changes the year when the computer was built
     * Output/Return: The new year
     */
    QString yearBuilt();

private slots:
    void on_backPushButtonEditCom_clicked();

    void on_confirmComEditPushButton_clicked();

    void on_yesRadioButtonCom_clicked();

    void on_noRadioButtonCom_clicked();

private:
    Ui::Editcomputer *ui;
    Computer computer;
};

#endif // EDITCOMPUTER_H
