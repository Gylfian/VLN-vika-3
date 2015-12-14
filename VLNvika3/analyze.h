#ifndef ANALYZE_H
#define ANALYZE_H

#include "cscientist.h"
#include "computer.h"
#include <QDialog>

namespace Ui {
class Analyze;
}

class Analyze : public QDialog
{
    Q_OBJECT

public:
    void setScientist(CScientist scientistToSet);
    void setComputer(Computer computerToSet);
    explicit Analyze(QWidget *parent = 0);
    ~Analyze();

private:
    Ui::Analyze *ui;
    CScientist scientist;
    Computer computer;
};

#endif // ANALYZE_H
