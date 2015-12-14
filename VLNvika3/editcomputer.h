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
    QString name();
    QString type();
    QString wasBuilt();
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
