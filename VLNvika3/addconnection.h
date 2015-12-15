#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H

#include "domain.h"
#include <QDialog>
#include <QMessageBox>

namespace Ui {
class AddConnection;
}

class AddConnection : public QDialog
{
    Q_OBJECT

public:
    explicit AddConnection(QWidget *parent = 0);
    ~AddConnection();
    void enable();
    void dragEnterEvent(QDragEnterEvent *event);
    void dropEvent(QDropEvent *event);
private slots:
    void on_dragScientists_entered(const QModelIndex &index);

    void on_dragScientists_clicked(const QModelIndex &index);

    void on_pushButton_clicked();


    void on_scientistsList_clicked(const QModelIndex &index);


    void on_computersList_clicked(const QModelIndex &index);

    void on_btnConnect_clicked();

private:
    Ui::AddConnection *ui;
    Domain domain;
    CScientist scientist;
    Computer computer;
    void displayAllScientists();
    void displayAllComputers();

    void displayScientists(vector <CScientist> scientists);
    void displayComputers(vector <Computer> computers);

    void designScientistsWidget(vector <CScientist> scientists);
    void designComputersWidget(vector <Computer> computers);

    void setUp();
};

#endif // ADDCONNECTION_H
