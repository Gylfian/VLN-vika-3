#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include "editscientist.h"
#include "ui_editscientist.h"
#include "cscientist.h"

namespace Ui {
class Editscientist;
}

class Editscientist : public QDialog
{
    Q_OBJECT

public:
    explicit Editscientist(QWidget *parent = 0);
    ~Editscientist();

    /*
     * Name: name
     * Description: Changes the name of the scientist
     * Output/Return: The new name
     */
    QString name();

    /*
     * Name: gender
     * Description: Changes the gender of the scientist
     * Output/Return: The new gender
     */
    QString gender();

    /*
     * Name: yearBorn
     * Description: Changes the birth year
     * Output/Return: The new birth year
     */
    QString yearBorn();

    /*
     * Name: yearOfDeath
     * Description: Changes the death year
     * Output/Return: The new death year
     */
    QString yearOfDeath();

    void setScientist(CScientist scientist);

private slots:
    void on_confirmSciEditPushButton_clicked();

    void on_backPushButtonEditSci_clicked();

    void on_noAliveButton_clicked();

    void on_yesAliveButton_clicked();

private:
    Ui::Editscientist *ui;
    CScientist scientist;
};

#endif // EDITSCIENTIST_H
