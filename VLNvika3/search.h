#ifndef SEARCH_H
#define SEARCH_H
#include "searchresults.h"
#include <QDialog>
#include <iostream>

using namespace std;

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();

private slots:

    void on_searchComboBox_currentIndexChanged(const QString &arg1);

    void on_addOrCancelSci_accepted();

    void on_addOrCancelSci_rejected();

    void on_noRadio_clicked(bool checked);

    void on_yesRadio_clicked(bool checked);

    void on_unknownRadioAlive_clicked(bool checked);


    void on_checkBox_clicked(bool checked);

    void on_comBuiltButton_clicked(bool checked);

    void on_comNotBuiltButton_clicked(bool checked);

    void on_comUnawareButton_clicked(bool checked);

    void on_adddOrCancelComp_accepted();

    void on_builtUnknown_clicked(bool checked);

    void on_yesBuiltRadio_clicked(bool checked);

    void on_noBuiltRadio_clicked(bool checked);

    void on_maybeBuiltRadio_clicked(bool checked);

    void on_adddOrCancelComp_rejected();


    void on_unknownDeath_clicked(bool checked);

private:
    string getGender();
    string getdob();
    string getdod();
    string getBuilt();
    string getBuiltYear();
    Ui::Search *ui;
};

#endif // SEARCH_H
