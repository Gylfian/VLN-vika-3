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

private:
    Ui::Analyze *ui;
};

#endif // ANALYZE_H
