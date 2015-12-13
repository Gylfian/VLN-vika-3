#ifndef WARNINGMESSAGE_H
#define WARNINGMESSAGE_H

#include <QDialog>

namespace Ui {
class Warningmessage;
}

class Warningmessage : public QDialog
{
    Q_OBJECT

public:
    explicit Warningmessage(QWidget *parent = 0);
    ~Warningmessage();

    void addLabel();
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::Warningmessage *ui;
};

#endif // WARNINGMESSAGE_H
