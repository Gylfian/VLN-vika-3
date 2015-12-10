#ifndef ADDCONNECTION_H
#define ADDCONNECTION_H

#include <QDialog>

namespace Ui {
class AddConnection;
}

class AddConnection : public QDialog
{
    Q_OBJECT

public:
    explicit AddConnection(QWidget *parent = 0);
    ~AddConnection();

private:
    Ui::AddConnection *ui;
};

#endif // ADDCONNECTION_H
