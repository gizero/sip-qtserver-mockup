#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "sipserver.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0, SipServer *server = 0);
    ~MainWindow();

private slots:
    void on_clearButton_clicked();
    void on_clearButton_2_clicked();
    void on_clearButton_3_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
