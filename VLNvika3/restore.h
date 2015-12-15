#ifndef RESTORE_H
#define RESTORE_H
#include "computer.h"
#include "domain.h"
#include <QDialog>

namespace Ui {
class Restore;
}

class Restore : public QDialog
{
    Q_OBJECT

public:
    explicit Restore(QWidget *parent = 0);
    ~Restore();
    void setUp();


    void displayScientists(vector<CScientist> scientists);
    void displayComputers(vector<Computer> computers);
    void designScientistsWidget(vector<CScientist> scientists);
    void designComputersWidget(vector<Computer> computers);
    void displayAllScientists();
    void displayAllComputers();
private slots:
    void on_scientistList_clicked(const QModelIndex &index);
    void on_computerList_clicked(const QModelIndex &index);
    void on_restoreButtonSci_clicked();

    void on_restoreButtonComp_clicked();

private:
    Ui::Restore *ui;
    CScientist scientist;
    Computer computer;
};

#endif // RESTORE_H
