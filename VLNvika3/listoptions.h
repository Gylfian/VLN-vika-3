#ifndef LISTOPTIONS_H
#define LISTOPTIONS_H
#include "cscientist.h"
#include "computer.h"

#include <QDialog>
#include <iostream>
#include <vector>

namespace Ui {
class ListOptions;
}

class ListOptions : public QDialog
{
    Q_OBJECT

public:
    explicit ListOptions(QWidget *parent = 0);
    ~ListOptions();

private:
    void displayAllScientists();
    void displayScientists(std::vector<CScientist> scientists);
    Ui::ListOptions *ui;
};

#endif // LISTOPTIONS_H
