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

    void displayvector(Computer c1);
    void displayvector(CScientist s1);
private:
    Ui::Restore *ui;
};

#endif // RESTORE_H
