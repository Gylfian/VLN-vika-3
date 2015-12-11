#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

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

private:
    Ui::Search *ui;
};

#endif // SEARCH_H
