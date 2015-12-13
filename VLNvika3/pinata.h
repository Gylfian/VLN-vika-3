#ifndef PINATA_H
#define PINATA_H

#include <QDialog>

namespace Ui {
class Pinata;
}

class Pinata : public QDialog
{
    Q_OBJECT

public:
    explicit Pinata(QWidget *parent = 0);
    ~Pinata();

private:
    Ui::Pinata *ui;
};

#endif // PINATA_H
