#ifndef LISTOPTIONS_H
#define LISTOPTIONS_H

#include <QDialog>

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
    Ui::ListOptions *ui;
};

#endif // LISTOPTIONS_H
