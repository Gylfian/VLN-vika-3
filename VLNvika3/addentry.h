#ifndef ADDENTRY_H
#define ADDENTRY_H

#include <QDialog>

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
    void on_whichToPick_currentIndexChanged(const QString &arg1);

    void on_sciDeadButton_clicked(bool checked);

    void on_sciAlivButton_clicked(bool checked);

    void on_sciBirthInput_valueChanged(int arg1);

    void on_comNotBuiltButton_clicked(bool checked);

    void on_comBuiltButton_clicked(bool checked);



private:
    Ui::AddEntry *ui;
};

#endif // ADDENTRY_H
