#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_pushButtonAddEntry_clicked();

    void on_pushButtonAddConnection_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButtonRestore_clicked();

    void on_pushButtonExit_clicked();

    void on_pushButtonListOptions_clicked();

    void on_pinata_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
