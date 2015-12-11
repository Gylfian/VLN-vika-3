#ifndef EDITSCIENTIST_H
#define EDITSCIENTIST_H

#include <QDialog>
#include <QComboBox>

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

private slots:

    //void on_maleRadioButton_clicked();

   // void on_femaleRadioPushButtonSci_clicked();

   // void on_maleRadioButton_clicked(bool checked);

    //void on_femaleRadioPushButtonSci_clicked(bool checked);

    void on_confirmSciEditPushButton_clicked();

    void on_backPushButtonEditSci_clicked();

private:
    Ui::Editscientist *ui;
};

#endif // EDITSCIENTIST_H
