#ifndef EDITCOMPUTER_H
#define EDITCOMPUTER_H

#include <QDialog>
#include <QComboBox>

namespace Ui {
class Editcomputer;
}

class Editcomputer : public QDialog
{
    Q_OBJECT

public:
    explicit Editcomputer(QWidget *parent = 0);
    ~Editcomputer();

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
};

#endif // EDITCOMPUTER_H
