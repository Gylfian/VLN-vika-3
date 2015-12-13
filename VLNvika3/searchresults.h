#ifndef SEARCHRESULTS_H
#define SEARCHRESULTS_H

#include <QDialog>

namespace Ui {
class Searchresults;
}

class Searchresults : public QDialog
{
    Q_OBJECT

public:
    explicit Searchresults(QWidget *parent = 0);
    void initialize();
    ~Searchresults();

private:
    Ui::Searchresults *ui;
};

#endif // SEARCHRESULTS_H
