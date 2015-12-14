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
    QString name();
    QString gender();
    QString yearBorn();
    QString yearOfDeath();
    void setScientist(CScientist scientist);

private slots:
    void on_confirmSciEditPushButton_clicked();
    void on_backPushButtonEditSci_clicked();

private:
    Ui::Editscientist *ui;
    CScientist scientist;
};

#endif // EDITSCIENTIST_H
