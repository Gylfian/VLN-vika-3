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
    void enable();
    void dragEnterEvent(QDragEnterEvent *event);

    void dropEvent(QDropEvent *event);
private slots:
    void on_dragScientists_entered(const QModelIndex &index);

    void on_dragScientists_clicked(const QModelIndex &index);

    void on_pushButton_clicked();

private:
    Ui::AddConnection *ui;
};

#endif // ADDCONNECTION_H
