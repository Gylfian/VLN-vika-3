#ifndef ANALYZE_H
#define ANALYZE_H

#include <QDialog>

namespace Ui {
class Analyze;
}

class Analyze : public QDialog
{
    Q_OBJECT

public:
    explicit Analyze(QWidget *parent = 0);
    ~Analyze();

private slots:
    void on_analyzeOk_accepted();

private:
    Ui::Analyze *ui;
    void printBasicInfo();
    void printDetailedInfo();
    void getPicture();
};

#endif // ANALYZE_H
