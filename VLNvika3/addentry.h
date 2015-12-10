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

private:
    Ui::AddEntry *ui;
};

#endif // ADDENTRY_H
