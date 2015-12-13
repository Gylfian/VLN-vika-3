#ifndef NOENTRIESFOUND_H
#define NOENTRIESFOUND_H

#include <QDialog>

namespace Ui {
class Noentriesfound;
}

class Noentriesfound : public QDialog
{
    Q_OBJECT

public:
    explicit Noentriesfound(QWidget *parent = 0);
    ~Noentriesfound();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Noentriesfound *ui;
};

#endif // NOENTRIESFOUND_H
